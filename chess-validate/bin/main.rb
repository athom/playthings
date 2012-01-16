$LOAD_PATH << '.'
$LOAD_PATH.unshift(File.join( File.dirname(__FILE__), '..', 'lib' ))
require 'chess'
include Chess

path_prj = File.expand_path( File.join( File.dirname(__FILE__), '..' ) )
#file_moves = File.join( path_prj, 'data', 'simple_moves.txt' )
#file_board = File.join( path_prj, 'data', 'simple_board.txt' )
file_moves = File.join( path_prj, 'data', 'complex_moves.txt' )
file_board = File.join( path_prj, 'data', 'complex_board.txt' )

p=Parser.new
p.parse_moves(file_moves)
p.parse_board(file_board)
p.output('./complex_result.txt')
