  rb_define_const(rb_cPcap, "DLT_NULL",   INT2NUM());	/* BSD loopback encapsulation */
  rb_define_const(rb_cPcap, "DLT_EN10MB",   INT2NUM()); /* Ethernet (10Mb) */
  rb_define_const(rb_cPcap, "DLT_EN3MB",   INT2NUM());	/* Experimental Ethernet (3Mb) */
  rb_define_const(rb_cPcap, "DLT_AX25",   INT2NUM());	/* Amateur Radio AX.25 */
  rb_define_const(rb_cPcap, "DLT_PRONET",   INT2NUM());		/* Proteon ProNET Token Ring */
  rb_define_const(rb_cPcap, "DLT_CHAOS",   INT2NUM());		/* Chaos */
  rb_define_const(rb_cPcap, "DLT_IEEE802",   INT2NUM());	/* 802.5 Token Ring */
  rb_define_const(rb_cPcap, "DLT_ARCNET",   INT2NUM());	/* ARCNET, with BSD-style header */
  rb_define_const(rb_cPcap, "DLT_SLIP",   INT2NUM());		/* Serial Line IP */
  rb_define_const(rb_cPcap, "DLT_PPP",   INT2NUM());		/* Point-to-point Protocol */
  rb_define_const(rb_cPcap, "DLT_FDDI",   INT2NUM());		/* FDDI */
  rb_define_const(rb_cPcap, "DLT_ATM_RFC1483",   INT2NUM());	/* LLC-encapsulated ATM */
  rb_define_const(rb_cPcap, "DLT_RAW",   INT2NUM());	/* raw IP */
  rb_define_const(rb_cPcap, "DLT_RAW",   INT2NUM());		/* raw IP */
  rb_define_const(rb_cPcap, "DLT_SLIP_BSDOS",   INT2NUM());		/* BSD/OS Serial Line IP */
  rb_define_const(rb_cPcap, "DLT_PPP_BSDOS",   INT2NUM());		/* BSD/OS Point-to-point Protocol */
  rb_define_const(rb_cPcap, "DLT_SLIP_BSDOS",   INT2NUM());		/* BSD/OS Serial Line IP */
  rb_define_const(rb_cPcap, "DLT_PPP_BSDOS",   INT2NUM());		/* BSD/OS Point-to-point Protocol */
  rb_define_const(rb_cPcap, "DLT_ATM_CLIP",   INT2NUM());		/* Linux Classical-IP over ATM */
  rb_define_const(rb_cPcap, "DLT_REDBACK_SMARTEDGE",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_PPP_SERIAL",   INT2NUM());		/* PPP over serial with HDLC encapsulation */
  rb_define_const(rb_cPcap, "DLT_PPP_ETHER",   INT2NUM());		/* PPP over Ethernet */
  rb_define_const(rb_cPcap, "DLT_SYMANTEC_FIREWALL",   INT2NUM());
  rb_define_const(rb_cPcap, "DLT_C_HDLC",   INT2NUM());		/* Cisco HDLC */
  rb_define_const(rb_cPcap, "DLT_CHDLC",   INT2NUM());
  rb_define_const(rb_cPcap, "DLT_IEEE802_11",   INT2NUM());		/* IEEE 802.11 wireless */
  rb_define_const(rb_cPcap, "DLT_FRELAY",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_LOOP",   INT2NUM());	

  rb_define_const(rb_cPcap, "DLT_ENC",   INT2NUM());

  rb_define_const(rb_cPcap, "DLT_LINUX_SLL",   INT2NUM());
  rb_define_const(rb_cPcap, "DLT_LTALK",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_ECONET",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_IPFILTER",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_OLD_PFLOG",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_PFSYNC",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_PFLOG",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_CISCO_IOS",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_PRISM_HEADER",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_AIRONET_HEADER",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_HHDLC",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_IP_OVER_FC",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_SUNATM",   INT2NUM());			/* Solaris+SunATM */
  rb_define_const(rb_cPcap, "DLT_RIO",   INT2NUM()); /* RapidIO */
  rb_define_const(rb_cPcap, "DLT_PCI_EXP",   INT2NUM()); /* PCI Express */
  rb_define_const(rb_cPcap, "DLT_AURORA",   INT2NUM()); /* Xilinx Aurora link layer */
  rb_define_const(rb_cPcap, "DLT_IEEE802_11_RADIO",   INT2NUM());		/* 802.11 plus radiotap radio header */
  rb_define_const(rb_cPcap, "DLT_TZSP",   INT2NUM()); /* Tazmen Sniffer Protocol */
  rb_define_const(rb_cPcap, "DLT_ARCNET_LINUX",   INT2NUM());		/* ARCNET */
  rb_define_const(rb_cPcap, "DLT_JUNIPER_MLPPP",   INT2NUM());       
  rb_define_const(rb_cPcap, "DLT_JUNIPER_MLFR",   INT2NUM());        
  rb_define_const(rb_cPcap, "DLT_JUNIPER_ES",   INT2NUM());         
  rb_define_const(rb_cPcap, "DLT_JUNIPER_GGSN",   INT2NUM());        
  rb_define_const(rb_cPcap, "DLT_JUNIPER_MFR",   INT2NUM());         
  rb_define_const(rb_cPcap, "DLT_JUNIPER_ATM2",   INT2NUM());        
  rb_define_const(rb_cPcap, "DLT_JUNIPER_SERVICES",   INT2NUM());    
  rb_define_const(rb_cPcap, "DLT_JUNIPER_ATM1",   INT2NUM());        
  rb_define_const(rb_cPcap, "DLT_APPLE_IP_OVER_IEEE1394",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_MTP2_WITH_PHDR",   INT2NUM());		/* pseudo-header with various info, followed by MTP2 */
  rb_define_const(rb_cPcap, "DLT_MTP2",   INT2NUM());			/* MTP2, without pseudo-header */
  rb_define_const(rb_cPcap, "DLT_MTP3",   INT2NUM());			/* MTP3, without pseudo-header or MTP2 */
  rb_define_const(rb_cPcap, "DLT_SCCP",   INT2NUM());		/* SCCP, without pseudo-header or MTP2 or MTP3 */
  rb_define_const(rb_cPcap, "DLT_DOCSIS",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_LINUX_IRDA",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_IBM_SP",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_IBM_SN",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER0",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER1",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER2",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER3",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER4",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER5",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER6",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER7",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER8",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER9",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER10",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER11",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER12",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_USER13",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER14",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USER15",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_IEEE802_11_RADIO_AVS",   INT2NUM()); /* 802.11 plus AVS radio header */
  rb_define_const(rb_cPcap, "DLT_JUNIPER_MONITOR",   INT2NUM());     
  rb_define_const(rb_cPcap, "DLT_BACNET_MS_TP",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_PPP_PPPD",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_PPP_WITH_DIRECTION",   INT2NUM());
  rb_define_const(rb_cPcap, "DLT_LINUX_PPP_WITHDIRECTION",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_JUNIPER_PPPOE",   INT2NUM());       
  rb_define_const(rb_cPcap, "DLT_JUNIPER_PPPOE_ATM",   INT2NUM());   
  rb_define_const(rb_cPcap, "DLT_GPRS_LLC",   INT2NUM());			/* GPRS LLC */
  rb_define_const(rb_cPcap, "DLT_GPF_T",   INT2NUM());		/* GPF-T (ITU-T G.7041/Y.1303) */
  rb_define_const(rb_cPcap, "DLT_GPF_F",   INT2NUM());			/* GPF-F (ITU-T G.7041/Y.1303) */
  rb_define_const(rb_cPcap, "DLT_GCOM_T1E1",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_GCOM_SERIAL",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_JUNIPER_PIC_PEER",   INT2NUM());    
  rb_define_const(rb_cPcap, "DLT_ERF_ETH",   INT2NUM());			/* Ethernet */
  rb_define_const(rb_cPcap, "DLT_ERF_POS",   INT2NUM());			/* Packet-over-SONET */
  rb_define_const(rb_cPcap, "DLT_LINUX_LAPD",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_JUNIPER_ETHER",   INT2NUM());       
  rb_define_const(rb_cPcap, "DLT_JUNIPER_PPP",   INT2NUM());         
  rb_define_const(rb_cPcap, "DLT_JUNIPER_FRELAY",   INT2NUM());      
  rb_define_const(rb_cPcap, "DLT_JUNIPER_CHDLC",   INT2NUM());       
  rb_define_const(rb_cPcap, "DLT_MFR",   INT2NUM());                 
  rb_define_const(rb_cPcap, "DLT_JUNIPER_VP",   INT2NUM());          
  rb_define_const(rb_cPcap, "DLT_A429",   INT2NUM());                
  rb_define_const(rb_cPcap, "DLT_A653_ICM",   INT2NUM());            
  rb_define_const(rb_cPcap, "DLT_USB",   INT2NUM());			
  rb_define_const(rb_cPcap, "DLT_BLUETOOTH_HCI_H4",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_IEEE802_16_MAC_CPS",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_USB_LINUX",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_CAN20B",   INT2NUM());              
  rb_define_const(rb_cPcap, "DLT_IEEE802_15_4_LINUX",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_PPI",   INT2NUM());			
  rb_define_const(rb_cPcap, "DLT_IEEE802_16_MAC_CPS_RADIO",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_JUNIPER_ISM",   INT2NUM());         
  rb_define_const(rb_cPcap, "DLT_IEEE802_15_4",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_SITA",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_ERF",   INT2NUM());			
  rb_define_const(rb_cPcap, "DLT_RAIF1",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_IPMB",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_JUNIPER_ST",   INT2NUM());          
  rb_define_const(rb_cPcap, "DLT_BLUETOOTH_HCI_H4_WITH_PHDR",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_AX25_KISS",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_LAPD",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_PPP_WITH_DIR",   INT2NUM());		/* PPP - don't confuse with DLT_PPP_WITH_DIRECTION */
  rb_define_const(rb_cPcap, "DLT_C_HDLC_WITH_DIR",   INT2NUM());		/* Cisco HDLC */
  rb_define_const(rb_cPcap, "DLT_FRELAY_WITH_DIR",   INT2NUM());		/* Frame Relay */
  rb_define_const(rb_cPcap, "DLT_LAPB_WITH_DIR",   INT2NUM());		/* LAPB */
  rb_define_const(rb_cPcap, "DLT_IPMB_LINUX",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_FLEXRAY",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_MOST",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_LIN",   INT2NUM());			
  rb_define_const(rb_cPcap, "DLT_X2E_SERIAL",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_X2E_XORAYA",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_IEEE802_15_4_NONASK_PHY",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_LINUX_EVDEV",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_GSMTAP_UM",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_GSMTAP_ABIS",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_MPLS",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_USB_LINUX_MMAPPED",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_DECT",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_AOS",   INT2NUM());                 
  rb_define_const(rb_cPcap, "DLT_WIHART",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_FC_2",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_FC_2_WITH_FRAME_DELIMS",   INT2NUM());	
  rb_define_const(rb_cPcap, "DLT_IPNET",   INT2NUM());			
  rb_define_const(rb_cPcap, "DLT_CAN_SOCKETCAN",   INT2NUM());		
  rb_define_const(rb_cPcap, "DLT_IPV4",   INT2NUM());			
  rb_define_const(rb_cPcap, "DLT_IPV6",   INT2NUM());			
