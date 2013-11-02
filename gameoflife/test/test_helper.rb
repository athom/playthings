$LOAD_PATH << '.'
$LOAD_PATH.unshift(File.join( File.dirname(__FILE__), '..', 'lib' ))

require 'test/unit'
require 'gameoflife'

$prj_path = File.expand_path( File.join( File.dirname(__FILE__), '..' ) )

include GameOfLife

def get_test_cases
  test_cases = {}
  path = $prj_path + "/data/"
  Dir.entries(path).reject!{|f|  f == '.' or f == ".."}.each do |catalog|
    test_suites = {}
    Dir.entries(path + catalog).reject!{|f|  f == '.' or f == ".."}.each do |suite|
      test_suites[suite] = Dir.entries(path+catalog+"/"+suite).reject!{|f|  f == '.' or f == ".."}
    end
    test_cases[catalog] = test_suites
  end
  test_cases
end

def get_file_content filename
  file = File.join($prj_path, 'data', filename)
  f = File.open(file, 'r')
  content =  f.read
  f.close
  content
end

def parse_to_map filename
  hash ={}
  lines = get_file_content(filename).split("\n")
  lines.each_with_index do |line, row_index|
    cols = line.split
    cols.each_with_index do |c, col_index|
      if c == '1'
        hash[[row_index,col_index]] = Core::LIVE
      end
    end
  end
  hash
end

def parse_to_array filename
  array = []
  lines = get_file_content(filename).split("\n")
  lines.each_with_index do |line, row_index|
    row = []
    cols = line.split
    cols.each_with_index do |c, col_index|
      if c == '1'
        row.push Core::LIVE
      else
        row.push Core::DEAD
      end
    end
    array.push row
  end
  array
end
