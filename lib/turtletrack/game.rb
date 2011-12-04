module TurtleTrack
  class Game
	Map = {'FD' => :forward, 'BK' => :backward, 'LT' => :left_rotate, 'RT' => :right_rotate}

	def initialize
	  @parser = Parser.new
	  @turtle = Turtle.new
	end

	def input(ifile)
	  @parser.parse(ifile)
	end

	def run
	  @parser.commands.each do |c|
		@turtle.send(Map[c[0]], c[1])
	  end

	  n = @parser.board_size
	  @board = Array.new(n){Array.new(n){'. '}}
	  @turtle.track.each do |x|
		@board[-x[1] + n/2][x[0] + n/2] = 'X '
	  end
	end

	def output(ofile)
	  #def output
	  fo = File.open(ofile, 'w')
	  @board.each_with_index do |col, col_index|
		col.last.chomp!(' ')
		col.each_with_index do |row, row_index|
		  fo.print row 
		end
		fo.puts ''
	  end
	  fo.close
	end

  end
end
