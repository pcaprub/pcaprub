begin
  if RUBY_VERSION =~ /1.8/
    require '1.8/pcaprub_c'
  elsif RUBY_VERSION =~ /1.9/
    require '1.9/pcaprub_c'
  elsif RUBY_VERSION =~ /2.0/
    require '2.0/pcaprub_c'
  elsif RUBY_VERSION =~ /2.1/
    require '2.1/pcapru_c'
  else
    require 'pcaprub_c'
  end
rescue Exception
  require 'pcaprub_c'
end