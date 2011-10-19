module PCAPRUB
  $:.unshift(File.dirname(__FILE__))
  require 'pcaprub/common'
  require 'pcaprub/ext'
end

#Force Include to allow backwards compatibility to ::PCAP.new
include PCAP
