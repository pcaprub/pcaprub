require 'rubygems'
require 'rake'
require 'rake/extensiontask'
require './lib/pcaprub/version'

begin
  require 'jeweler'
  jeweler_tasks = Jeweler::Tasks.new do |gem|
    gem.name = "pcaprub"
    gem.summary = "libpcap bindings for ruby"
    gem.description = "libpcap bindings for ruby compat with JRUBY Ruby1.8 Ruby1.9"
    gem.email = "shadowbq@gmail.com"
    gem.homepage = "http://github.com/shadowbq/pcaprub"
    gem.authors = ["shadowbq"]
    gem.extensions = ['ext/pcaprub/extconf.rb']
    gem.rubyforge_project   = 'pcaprub'
    gem.version = PCAPRUB::VERSION::STRING
    gem.files.include('lib/pcaprub.*') # add native stuff
    gem.add_development_dependency("jeweler")
    gem.add_development_dependency("shoulda")
    gem.add_dependency("rake")
    gem.add_dependency("rake-compiler")
    gem.extra_rdoc_files = FileList['README*', 'ChangeLog*', 'LICENSE*', 'FAQ*', 'USAGE*', 'ext/**/*.c']
  end

  $gemspec          = jeweler_tasks.gemspec
  $gemspec.version  = jeweler_tasks.jeweler.version

  Jeweler::GemcutterTasks.new
rescue LoadError
  puts "Jeweler (or a dependency) not available. Install it with: gem install jeweler"
end

Rake::ExtensionTask.new("pcaprub", $gemspec)

require "rubygems/package_task"
Gem::PackageTask.new($gemspec) do |package|
  package.need_zip = false
  package.need_tar = false
end


require 'rake/testtask'
Rake::TestTask.new(:test) do |test|
  test.libs << 'lib' << 'test'
  test.pattern = 'test/**/test_*.rb'
  test.verbose = true
end

begin
  require 'rcov/rcovtask'
  Rcov::RcovTask.new do |test|
    test.libs << 'test'
    test.pattern = 'test/**/test_*.rb'
    test.verbose = true
  end
rescue LoadError
  task :rcov do
    abort "RCov is not available. In order to run rcov, you must: sudo gem install spicycode-rcov"
  end
end

task :test

task :default => %w[clean compile test]

require 'rdoc/task'
RDoc::Task.new do |rdoc|
  version = PCAPRUB::VERSION::STRING
  rdoc.rdoc_dir = 'rdoc'
  rdoc.title = "pcaprub #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('FAQ*')
  rdoc.rdoc_files.include('LICENSE*')
  rdoc.rdoc_files.include('lib/**/*.rb')
  rdoc.rdoc_files.include('ext/**/*.c')
end
