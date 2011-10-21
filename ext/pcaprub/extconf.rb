require 'mkmf'
extension_name = 'pcaprub'

puts "\n[*] Running checks for #{extension_name} code..."
puts("platform is #{RUBY_PLATFORM}")

if /i386-mingw32/ =~ RUBY_PLATFORM
	
	unless  have_library("ws2_32" ) and 
		have_library("iphlpapi") and 
		have_header("windows.h") and 
		have_header("winsock2.h") and 
		have_header("iphlpapi.h")
			puts "\nNot all dependencies are satisfied for #{RUBY_PLATFORM} platform requirements"
			exit
	end
	
	pcap_dir        = with_config("pcap-dir", "C:/WpdPack")
  pcap_includedir = with_config("pcap-includedir", pcap_dir + "/include")
  pcap_libdir     = with_config("pcap-libdir", pcap_dir + "/lib")

  have_library("wpcap", "pcap_open_live")
	have_library("wpcap", "pcap_setnonblock")
	
elsif /i386-mswin32/ =~ RUBY_PLATFORM
  pcap_dir        = with_config("pcap-dir", "C:\\WpdPack")
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

if ( RUBY_VERSION =~ /^1\.8/ && !defined?(JRUBY_VERSION) )
	$CFLAGS += " -DMAKE_TRAP"
end


dir_config(extension_name)
create_makefile(extension_name)


