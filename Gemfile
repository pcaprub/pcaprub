source 'https://rubygems.org'

# No more static spec file

platforms :ruby_18 do
    gem 'rdoc'
end

group :development, :test do
  # Prevent occasions where minitest is not bundled in packaged versions of ruby (see #3826)
  gem 'minitest', '~> 4.7.0'
  gem 'shoulda-context', '~> 1.1.6'
  platforms :ruby_19, :ruby_20, :ruby_21 do
    gem 'coveralls', :require => false
  end
end

gem 'rake', '>= 0.9.2'
gem 'rake-compiler', '>= 0.6.0'
gem 'rubygems-tasks'
gem 'git'
