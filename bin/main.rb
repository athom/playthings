$LOAD_PATH << '.'
$LOAD_PATH.unshift(File.join( File.dirname(__FILE__), '..', 'lib' ))
require 'turtletrack'
include TurtleTrack

path_prj = File.expand_path( File.join( File.dirname(__FILE__), '..' ) )
#file_logo = File.join( path_prj, 'data', 'simple.logo' )
file_logo = File.join( path_prj, 'data', 'complex.logo' )

g = Game.new
g.input(file_logo)
g.run
g.output('./output.txt')
