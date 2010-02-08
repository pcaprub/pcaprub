require 'rubygems'
require 'rake'
require 'rake/clean'

desc "Build the extension:"
task :compile => %W[ext/pcaprub/Makefile ext/pcaprub/pcaprub.c]


file "ext/pcaprub/Makefile" => ["ext/pcaprub/extconf.rb"] do
  Dir.chdir("ext/pcaprub") do 
    ruby "extconf.rb"
    sh "make"
  end
  cp "ext/pcaprub/pcaprub.so", "lib"  
end

CLEAN.include 'ext/**/Makefile'
CLEAN.include 'ext/**/*.o'
CLEAN.include 'ext/**/mkmf.log'
CLEAN.include 'ext/**/*.so'
CLEAN.include 'lib/**/*.so'

begin
  require 'jeweler'
  jeweler_tasks = Jeweler::Tasks.new do |gem|
    gem.name = "pcaprub"
    gem.summary = "libpcap bindings for ruby"
    gem.description = "libpcap bindings for ruby"
    gem.email = "shadowbq@gmail.com"
    gem.homepage = "http://github.com/shadowbq/pcaprub"
    gem.authors = ["shadowbq"]
    gem.extensions = FileList['ext/**/extconf.rb']
    gem.rubyforge_project   = 'pcaprub'
    gem.files.include('lib/pcaprub.*') # add native stuff
  end
  
  $gemspec          = jeweler_tasks.gemspec
  $gemspec.version  = jeweler_tasks.jeweler.version
  
  Jeweler::GemcutterTasks.new
rescue LoadError
  puts "Jeweler (or a dependency) not available. Install it with: gem install jeweler"
end

require 'rake/gempackagetask'
Rake::GemPackageTask.new($gemspec) do |package|
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

task :test => :check_dependencies

task :default => %w[clean compile test]

require 'rake/rdoctask'
Rake::RDocTask.new do |rdoc|
  version = File.exist?('VERSION') ? File.read('VERSION') : ""

  rdoc.rdoc_dir = 'rdoc'
  rdoc.title = "pcaprub #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
end
