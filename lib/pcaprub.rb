module PCAPRUB
  $:.unshift(File.dirname(__FILE__))
  require 'pcaprub/common'
  require 'pcaprub/version'

  if RUBY_PLATFORM =~/(mswin|mingw)/i
    # On Windows load npcap first if it exists, will fall back to winpcap if that's installed
    npcap_path = "C:\\Windows\\System32\\Npcap"
    if File.directory?(npcap_path)
      RubyInstaller::Runtime.add_dll_directory(npcap_path)
    end
  end

  require 'pcaprub/ext'
end

#Force Include to allow backwards compatibility to ::PCAP.new
include PCAPRUB
