$LOAD_PATH << '.'
$LOAD_PATH.unshift(File.join( File.dirname(__FILE__), '..', 'lib' ))
require 'socialnetwork'

path_prj = File.expand_path( File.join( File.dirname(__FILE__), '..' ) )
#file_input = File.join( path_prj, 'data', 'sample_input.txt' )
file_input = File.join( path_prj, 'data', 'complex_input.txt' )

sw=SocialNetwork.new
sw.parse(file_input)
sw.output('complex_output.txt')

