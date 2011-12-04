$: << '.'
require_relative 'test_helper'
class TestTurtleTrack < Test::Unit::TestCase
  def setup
	path_prj = File.expand_path( File.join( File.dirname(__FILE__), '..' ) )
	@file_logo_simple = File.join( path_prj, 'data', 'simple.logo' )
	@file_logo_complex = File.join( path_prj, 'data', 'complex.logo' )
	@parser = Parser.new
	@t = Turtle.new
  end

  def test_pass
	assert_equal(0, 0)
  end

  def test_parser_initial_state
	assert_equal(@parser.commands, [])
	assert_equal(@parser.board_size, 0)
  end

  def test_simple_board_size_parse
	@parser.parse(@file_logo_simple)
	assert_equal(@parser.board_size, 61)
  end

  def test_complex_board_size_parse
	@parser.parse(@file_logo_complex)
	assert_equal(@parser.board_size, 1001)
  end

  def test_parser_simple_logo_command
	@parser.parse(@file_logo_simple)
	assert_equal(@parser.commands, [
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
  end

  def test_turtle_base_functions
	assert_equal(@t.facing, Turtle::N)
	assert_equal(@t.track, [[0,0]])

	@t.forward(4)
	assert_equal(@t.track, [[0,0], [0,1], [0,2], [0, 3], [0, 4]])
	assert_equal(@t.last_pos, [0, 4])

	@t.right_rotate(90)
	assert_equal(@t.facing, Turtle::E)

	@t.forward(4)
	assert_equal(@t.track, [[0,0], [0,1], [0,2], [0, 3], [0, 4], [1,4], [2, 4], [3, 4], [4, 4]])
	assert_equal(@t.last_pos, [4, 4])

	@t.left_rotate(45)
	assert_equal(@t.facing, Turtle::NE)

	@t.backward(4)
	assert_equal(@t.track, [[0,0], [0,1], [0,2], [0, 3], [0, 4], [1,4], [2, 4], [3, 4], [4, 4], [3,3], [2,2], [1,1], [0,0]])
	assert_equal(@t.last_pos, [0, 0])
  end
end


