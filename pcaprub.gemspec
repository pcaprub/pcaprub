# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'pcaprub/version'

Gem::Specification.new do |spec|
  spec.name          = "pcaprub"
  spec.version       = PCAPRUB::Pcap.version
  spec.authors       = ["shadowbq", "crondaemon", "jmcavinee"]
  spec.email         = "shadowbq@gmail.com"
  spec.description   = "libpcap bindings for ruby compat with JRUBY Ruby1.8 Ruby1.9"
  spec.summary       = "libpcap bindings for ruby"
  spec.homepage      = "https://github.com/pcaprub/pcaprub"
  spec.requirements  = "libpcap"
  spec.license       = "MIT"

  spec.files = [
    ".document",
    ".travis.yml",
    "FAQ.rdoc",
    "Gemfile",
    "Gemfile.lock",
    "LICENSE",
    "README.rdoc",
    "Rakefile",
    "USAGE.rdoc",
    "VERSION.yml",
    "examples/dead_cap.rb",
    "examples/file_cap.rb",
    "examples/simple_cap.rb",
    "examples/telnet-raw.pcap",
    "ext/pcaprub/extconf.rb",
    "ext/pcaprub/pcaprub.c",
    "lib/pcaprub.rb",
    "lib/pcaprub.so",
    "lib/pcaprub/common.rb",
    "lib/pcaprub/ext.rb",
    "lib/pcaprub/version.rb",
    "pcaprub.gemspec",
    "test/helper.rb",
    "test/test_pcaprub.rb",
    "test/test_pcaprub_unit.rb"
  ]

  spec.extra_rdoc_files = [
    "FAQ.rdoc",
    "LICENSE",
    "README.rdoc",
    "USAGE.rdoc",
    "ext/pcaprub/pcaprub.c"
  ]
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "shoulda"
end
