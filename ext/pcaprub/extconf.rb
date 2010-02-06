require 'mkmf'

extension_name = 'pcaprub'
have_library("pcap", "pcap_open_live")
dir_config(extension_name)
 #$CPPFLAGS += " -DRUBY_19" if RUBY_VERSION =~ /1.9/
create_makefile(extension_name)
