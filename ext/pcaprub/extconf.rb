require 'mkmf'
extension_name = 'pcaprub'

if /i386-mswin32/ =~ RUBY_PLATFORM
  pcap_dir        = with_config("pcap-dir", "C:\WpdPack")
  pcap_includedir = with_config("pcap-includedir", pcap_dir + "\\include")
  pcap_libdir     = with_config("pcap-libdir", pcap_dir + "\\lib")

  $CFLAGS  = "-DWIN32 -I#{pcap_includedir}"
  $LDFLAGS = "/link /LIBPATH:#{pcap_libdir}"
  have_library("wpcap", "pcap_open_live")
	have_library("wpcap", "pcap_setnonblock")
else
  have_library("pcap", "pcap_open_live")
	have_library("pcap", "pcap_setnonblock")
end

if ( RUBY_VERSION =~ /^1\.8/ and RUBY_PLATFORM !~ /java/ )
	$CFLAGS += " -DRUBY_18"
end


dir_config(extension_name)
create_makefile(extension_name)


