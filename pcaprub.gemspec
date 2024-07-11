#require "bundler/gem_tasks"
require './lib/pcaprub/version.rb'

def java?
  /java/ === RUBY_PLATFORM
end

ENV['LANG'] = "en_US.UTF-8"

Gem::Specification.new do |spec|
  spec.name                  = "pcaprub"
  spec.version               = PCAPRUB::Pcap.version
  spec.authors               = ["shadowbq", "crondaemon", "jmcavinee", "unmarshal"]
  spec.email                 = "shadowbq@gmail.com"
  spec.description           = "libpcap bindings for Ruby 2.x"
  spec.summary               = "libpcap bindings for ruby"
  spec.homepage              = "https://github.com/pcaprub/pcaprub"
  spec.requirements          = "libpcap"
  spec.license               = "LGPL-2.1"
  spec.required_ruby_version = '>= 2.0'

  spec.files = [
    ".document",
    "FAQ.rdoc",
    "Gemfile",
    "LICENSE",
    "README.rdoc",
    "Rakefile",
    "USAGE.rdoc",
    "examples/dead_cap.rb",
    "examples/file_cap.rb",
    "examples/simple_cap.rb",
    "examples/telnet-raw.pcap",
    "ext/pcaprub_c/extconf.rb",
    "ext/pcaprub_c/pcaprub.c",
    "lib/pcaprub.rb",
    "lib/pcaprub/common.rb",
    "lib/pcaprub/ext.rb",
    "lib/pcaprub/version.rb",
    "test/test_helper.rb",
    "test/test_pcaprub_unit.rb"
  ]

  spec.extra_rdoc_files = [
    "FAQ.rdoc",
    "LICENSE",
    "README.rdoc",
    "USAGE.rdoc",
    "ext/pcaprub_c/pcaprub.c"
  ]
  spec.extensions = ["ext/pcaprub_c/extconf.rb"]
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake", '~> 0.9', '>= 0.9.2'
  spec.add_development_dependency "rake-compiler", '~> 0.6', '>= 0.6.0'
  spec.add_development_dependency "shoulda-context", '~> 1.1', '~> 1.1.6'
  spec.add_development_dependency "minitest", '~> 4.7', '>= 4.7.0'

end
