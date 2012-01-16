require 'test/unit/assertions'
require '../src/parser'
include Test::Unit::Assertions

p = Parser.new
assert_equal(p.commands, [])
assert_equal(p.board_size, 0)

#e = p.parse("../data/simple1.logo")
#assert_equal(RunTimeError, e)

p.parse("../data/simple.logo")
assert_equal(p.board_size, 61)
assert_equal(p.commands, [
			  ["RT", 135],
			  ["FD", 5],
			  ["RT", 90],
			  ["FD", 15],
			  ["RT", 90],
			  ["FD", 15],
			  ["RT", 90],
			  ["FD", 5],
			  ["RT", 45],
			  ["FD", 20]
			])

p.parse("../data/complex.logo")
p p.board_size
p p.commands.count
#assert_equal(p.board_size, 1001)
