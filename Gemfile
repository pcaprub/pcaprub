source 'https://rubygems.org'

group :development, :test do
  # Prevent occasions where minitest is not bundled in packaged versions of ruby (see #3826)
  gem 'minitest', '~> 4.7.0'
  gem 'shoulda-context', '~> 1.1.6'
  gem 'test-unit'
  gem 'coveralls', :require => false
end

gem 'rake-compiler', '>= 0.6.0'
gem 'rubygems-tasks'

if Bundler.current_ruby.mri? || Bundler.current_ruby.mingw? || Bundler.current_ruby.x64_mingw?
  gem 'rake', '>= 0.9.2'
  gem 'git', '~> 1.3.0'
end
