# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'gameoflife/version'

Gem::Specification.new do |spec|
  spec.name          = "gameoflife"
  spec.version       = Gameoflife::VERSION
  spec.authors       = ["athom"]
  spec.email         = ["athom@126.com"]
  spec.description   = %q{A demo of Conway's Game of Life}
  spec.summary       = %q{A demo of Conway's Game of Life, defination could be found on http://en.wikipedia.org/wiki/Conway's_Game_of_Life}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
end
