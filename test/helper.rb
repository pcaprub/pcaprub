require 'rubygems'
require 'bundler/setup'
require 'test/unit'
require 'shoulda-context'

$LOAD_PATH.unshift(File.join(File.dirname(__FILE__), '..', 'lib'))
$LOAD_PATH.unshift(File.dirname(__FILE__))
require 'pcaprub'

class Test::Unit::TestCase
end
