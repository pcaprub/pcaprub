require 'mkmf'
extension_name = 'pcaprub_c'

puts "\n[*] Running checks for #{extension_name} code..."
puts("platform is #{RUBY_PLATFORM}")
default_npcap_sdk = 'C:/npcap-sdk'
default_winpcap_sdk = 'C:/WpdPack'
# Default to npcap if it exists, otherwise fallback to winpcap
default_pcap_sdk = File.directory?(default_npcap_sdk) ? default_npcap_sdk : default_winpcap_sdk

if /i386-mingw32/ =~ RUBY_PLATFORM || /x64-mingw32/ =~ RUBY_PLATFORM || /x64-mingw-ucrt/ =~ RUBY_PLATFORM
  unless  have_library("ws2_32" ) and
    have_library("iphlpapi") and
    have_header("windows.h") and
    have_header("winsock2.h") and
    have_header("iphlpapi.h")
    puts "\nNot all dependencies are satisfied for #{RUBY_PLATFORM} platform requirements"
    exit
  end

  pcap_dir        = with_config("pcap-dir", default_pcap_sdk)
  pcap_includedir = with_config("pcap-includedir", pcap_dir + "/include")
  pcap_libdir     = with_config("pcap-libdir", pcap_dir + "/lib")

  if /x64-mingw32/ =~ RUBY_PLATFORM || /x64-mingw-ucrt/ =~ RUBY_PLATFORM
    pcap_libdir += "/x64"
  end

  $CFLAGS  = "-DWIN32 -I#{pcap_includedir}"
  $CFLAGS += " -g" if with_config("debug")
  $LDFLAGS = "-L#{pcap_libdir}"
  $LDFLAGS += " -g" if with_config("debug")

  have_header("ruby/thread.h")
  if have_header(pcap_includedir + "/Win32-Extensions.h", pcap_includedir + "/pcap.h")
    append_cflags("-DHAVE_WIN32_EXTENSIONS_H")
  end
  have_func("rb_thread_blocking_region") # Pre ruby 2.2
  have_func("rb_thread_call_without_gvl") # Post ruby 2.2
  have_library("wpcap", "pcap_open_live")
  have_library("wpcap", "pcap_setnonblock")
elsif /i386-mswin32/ =~ RUBY_PLATFORM || /x64-mswin32/ =~ RUBY_PLATFORM
  pcap_dir        = with_config("pcap-dir", default_pcap_sdk)
  pcap_includedir = with_config("pcap-includedir", pcap_dir + "\\include")
  pcap_libdir     = with_config("pcap-libdir", pcap_dir + "\\lib")

  if /x64-mingw32/ =~ RUBY_PLATFORM
    pcap_libdir += "\\x64"
  end

  $CFLAGS  = "-DWIN32 -I#{pcap_includedir}"
  $CFLAGS += " -g" if with_config("debug")
  $LDFLAGS = "/link /LIBPATH:#{pcap_libdir}"
  $LDFLAGS += " -g" if with_config("debug")
  have_header("ruby/thread.h")
  if have_header(pcap_includedir + "/Win32-Extensions.h", pcap_includedir + "/pcap.h")
    append_cflags("-DHAVE_WIN32_EXTENSIONS_H")
  end
  have_func("rb_thread_blocking_region") # Pre ruby 2.2
  have_func("rb_thread_call_without_gvl") # Post ruby 2.2

  have_library("wpcap", "pcap_open_live")
  have_library("wpcap", "pcap_setnonblock")
else
  libdir = RbConfig::CONFIG['libdir']
  includedir = RbConfig::CONFIG['includedir']

  header_dirs = [
    # macports
    '/opt/local/include',
    # source installations
    '/usr/local/include',
    # ruby install locations
    includedir,
    # finally fall back to usr
    '/usr/include'
  ]

  lib_dirs = [
    # macports
    '/opt/local/lib',
    # source installations
    '/usr/local/lib',
    # ruby install locations
    libdir,
    # usr
    '/usr/lib'
  ]

  dir_config("pcap", header_dirs, lib_dirs)

  have_header("ruby/thread.h")
  have_func("rb_thread_blocking_region") # Pre ruby 2.2
  have_func("rb_thread_call_without_gvl") # Post ruby 2.2

  have_library("pcap", "pcap_open_live", ["pcap.h"])
  have_library("pcap", "pcap_setnonblock", ["pcap.h"])

  $CFLAGS = "-g" if with_config("debug")
  $LDFLAGS = "-g" if with_config("debug")
end

create_makefile(extension_name)
