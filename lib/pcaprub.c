#include "ruby.h"
#include "rubysig.h"

#include <pcap.h>

static VALUE rb_cPcap;

#define OFFLINE 1
#define LIVE 2

typedef struct rbpcap {
    pcap_t *pd;
    char iface[256];
    char type;
} rbpcap_t;

static VALUE
rbpcap_new_s(VALUE class)
{
    VALUE self;
    rbpcap_t *rbp;

    // need to make destructor do a pcap_close later
    self = Data_Make_Struct(class, rbpcap_t, 0, free, rbp);
    rb_obj_call_init(self, 0, 0);

    memset(rbp, 0, sizeof(rbpcap_t));

    return self;
}

static VALUE
rbpcap_setfilter(VALUE self, VALUE filter)
{
    char  eb[1024];
    rbpcap_t *rbp;
    u_int32_t mask = 0, netid = 0;
    struct bpf_program bpf;

    Data_Get_Struct(self, rbpcap_t, rbp);

	if(TYPE(filter) != T_STRING)
		rb_raise(rb_eArgError, "filter must be a string");

    if(rbp->type == LIVE)
        if(pcap_lookupnet(rbp->iface, &netid, &mask, eb) < 0)
            rb_raise(rb_eRuntimeError, "%s", eb);

    if(pcap_compile(rbp->pd, &bpf, RSTRING(filter)->ptr, 0, mask) < 0)
        rb_raise(rb_eRuntimeError, "invalid bpf filter");

    if(pcap_setfilter(rbp->pd, &bpf) < 0)
        rb_raise(rb_eRuntimeError, "unable to set bpf filter");

    return self;
}

static VALUE
rbpcap_open_live(VALUE self, VALUE interface, VALUE snaplen, VALUE promisc, VALUE timeout)
{
    char eb[1024];
    rbpcap_t *rbp;
    int promisc_value = 0;

	if(TYPE(interface) != T_STRING)
		rb_raise(rb_eArgError, "interface must be a string");
	if(TYPE(snaplen) != T_FIXNUM)
		rb_raise(rb_eArgError, "snaplen must be a fixnum");
	if(TYPE(timeout) != T_FIXNUM)
		rb_raise(rb_eArgError, "timeout must be a fixnum");

    switch(promisc) {
        case Qtrue:
            promisc_value = 1;
            break;
        case Qfalse:
            promisc_value = 0;
            break;
        default:
            rb_raise(rb_eTypeError, "Argument not boolean");
    }

    Data_Get_Struct(self, rbpcap_t, rbp);

    rbp->type = LIVE;
    memset(rbp->iface, 0, sizeof(rbp->iface));
    strncpy(rbp->iface, RSTRING(interface)->ptr, sizeof(rbp->iface) - 1);

    rbp->pd = pcap_open_live(
        RSTRING(interface)->ptr,
        NUM2INT(snaplen),
        promisc_value,
        NUM2INT(timeout),
        eb
    );

    if(!rbp->pd)
        rb_raise(rb_eRuntimeError, "%s", eb);

    return self;
}

static VALUE
rbpcap_open_live_s(VALUE class, VALUE interface, VALUE snaplen, VALUE promisc, VALUE timeout)
{
    VALUE iPcap = rb_funcall(rb_cPcap, rb_intern("new"), 0);

    return rbpcap_open_live(iPcap, interface, snaplen, promisc, timeout);
}

static VALUE
rbpcap_open_offline(VALUE self, VALUE filename)
{
    char eb[1024];
    rbpcap_t *rbp;

	if(TYPE(filename) != T_STRING)
		rb_raise(rb_eArgError, "filename must be a string");

    Data_Get_Struct(self, rbpcap_t, rbp);

    memset(rbp->iface, 0, sizeof(rbp->iface));
    rbp->type = OFFLINE;

    rbp->pd = pcap_open_offline(
        RSTRING(filename)->ptr,
        eb
    );

    if(!rbp->pd)
        rb_raise(rb_eRuntimeError, "%s", eb);

    return self;
}


static VALUE
rbpcap_open_offline_s(VALUE class, VALUE filename)
{
    VALUE iPcap = rb_funcall(rb_cPcap, rb_intern("new"), 0);

    return rbpcap_open_offline(iPcap, filename);
}

static VALUE
rbpcap_inject(VALUE self, VALUE payload)
{
    rbpcap_t *rbp;

	if(TYPE(payload) != T_STRING)
		rb_raise(rb_eArgError, "payload must be a string");

    Data_Get_Struct(self, rbpcap_t, rbp);

    return INT2NUM(pcap_inject(rbp->pd, RSTRING(payload)->ptr, RSTRING(payload)->len));
}

static VALUE
rbpcap_next(VALUE self)
{
    int ret;
    char *pkt;
    rbpcap_t *rbp;
    struct pcap_pkthdr pkthdr;

    Data_Get_Struct(self, rbpcap_t, rbp);

	memset(&pkthdr, 0, sizeof(pkthdr));

    TRAP_BEG;
    pkt = (char *)pcap_next(rbp->pd, &pkthdr);
    TRAP_END;

    if(pkthdr.caplen > 0)
        return rb_str_new(pkt, pkthdr.caplen);

    return Qnil;
}

static VALUE
rbpcap_capture(VALUE self)
{
    int ret;
    char *pkt;
    rbpcap_t *rbp;
    struct pcap_pkthdr pkthdr;

    Data_Get_Struct(self, rbpcap_t, rbp);

    for(;;) {

		VALUE packet = rbpcap_next(self);

        if(packet == Qnil && rbp->type == OFFLINE)
            break;

        if(packet != Qnil)
            rb_yield(packet);
    }

    return self;
}


static VALUE
rbpcap_datalink(VALUE self)
{
    rbpcap_t *rbp;

    Data_Get_Struct(self, rbpcap_t, rbp);

    return INT2NUM(pcap_datalink(rbp->pd));
}

void
Init_pcaprub()
{
    // Pcap
    rb_cPcap = rb_define_class("Pcap", rb_cObject);

    rb_define_const(rb_cPcap, "DLT_NULL",   INT2NUM(DLT_NULL));
    rb_define_const(rb_cPcap, "DLT_EN10MB", INT2NUM(DLT_EN10MB));
    rb_define_const(rb_cPcap, "DLT_EN3MB", INT2NUM(DLT_EN3MB));
    rb_define_const(rb_cPcap, "DLT_AX25", INT2NUM(DLT_AX25));
    rb_define_const(rb_cPcap, "DLT_PRONET", INT2NUM(DLT_PRONET));
    rb_define_const(rb_cPcap, "DLT_CHAOS", INT2NUM(DLT_CHAOS));
    rb_define_const(rb_cPcap, "DLT_IEEE802", INT2NUM(DLT_IEEE802));
    rb_define_const(rb_cPcap, "DLT_ARCNET", INT2NUM(DLT_ARCNET));
    rb_define_const(rb_cPcap, "DLT_SLIP", INT2NUM(DLT_SLIP));
    rb_define_const(rb_cPcap, "DLT_PPP", INT2NUM(DLT_PPP));
    rb_define_const(rb_cPcap, "DLT_FDDI", INT2NUM(DLT_FDDI));
    rb_define_const(rb_cPcap, "DLT_ATM_RFC1483", INT2NUM(DLT_ATM_RFC1483));


    rb_define_singleton_method(rb_cPcap, "new", rbpcap_new_s, 0);

    rb_define_singleton_method(rb_cPcap, "open_live", rbpcap_open_live_s, 4);
    rb_define_singleton_method(rb_cPcap, "open_offline", rbpcap_open_offline_s, 1);

    rb_define_method(rb_cPcap, "each", rbpcap_capture, 0);
    rb_define_method(rb_cPcap, "next", rbpcap_next, 0);
    rb_define_method(rb_cPcap, "setfilter", rbpcap_setfilter, 1);
    rb_define_method(rb_cPcap, "inject", rbpcap_inject, 1);
    rb_define_method(rb_cPcap, "datalink", rbpcap_datalink, 0);

}
