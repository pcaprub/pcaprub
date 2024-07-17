module PCAPRUB
  $:.unshift(File.dirname(__FILE__))
  require 'pcaprub/common'
  require 'pcaprub/version'

  add_dll_path = proc do |path, &block|
    if RUBY_PLATFORM =~/(mswin|mingw)/i && path && File.exist?(path)
      begin
        require 'ruby_installer/runtime'
        RubyInstaller::Runtime.add_dll_directory(path, &block)
      rescue LoadError
        old_path = ENV['PATH']
        ENV['PATH'] = "#{path};#{old_path}"
        begin
          block.call
        ensure
          ENV['PATH'] = old_path
        end
      end
    else
      block.call
    end
  end

  npcap_path = "C:\\Windows\\System32\\Npcap"
  add_dll_path.call(npcap_path) do
    require 'pcaprub/ext'
  end

end

#Force Include to allow backwards compatibility to ::PCAP.new
include PCAPRUB
