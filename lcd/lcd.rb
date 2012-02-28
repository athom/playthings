require 'optparse'

module Lcd
  class Runner
    def initialize(arguments, stdin, stdout)
      @arguments = arguments
      @stdin = stdin
      @stdout = stdout
      @size = 2
      @x = '-'
      @y = '|'
      @b = ' '
    end
    
    def run
      parse_options
      @num = @arguments[0]
      setup_board
      puts get_map
    end

    
    private

	def setup_board
	  @board = {
		'0' => [@b,@x,@b,  
				@y,@b,@y,  
				@b,@b,@b,  
				@y,@b,@y,  
				@b,@x,@b],
		'1' => [@b,@b,@b,  
				@b,@b,@y,  
				@b,@b,@b,  
				@b,@b,@y,  
				@b,@b,@b],
		'2' => [@b,@x,@b,  
				@b,@b,@y,  
				@b,@x,@b,  
				@y,@b,@b,  
				@b,@x,@b],
		'3' => [@b,@x,@b,  
				@b,@b,@y,  
				@b,@x,@b,  
				@b,@b,@y,  
				@b,@x,@b],
		'4' => [@b,@b,@b,  
				@y,@b,@y,  
				@b,@x,@b,  
				@b,@b,@y,  
				@b,@b,@b],
		'5' => [@b,@x,@b,  
				@y,@b,@b,  
				@b,@x,@b,  
				@b,@b,@y,  
				@b,@x,@b],
		'6' => [@b,@x,@b,  
				@y,@b,@b,  
				@b,@x,@b,  
				@y,@b,@y,  
				@b,@x,@b],
		'7' => [@b,@x,@b,  
				@b,@b,@y,  
				@b,@b,@b,  
				@b,@b,@y,  
				@b,@b,@b],
		'8' => [@b,@x,@b,  
				@y,@b,@y,  
				@b,@x,@b,  
				@y,@b,@y,  
				@b,@x,@b],
		'9' => [@b,@x,@b,  
				@y,@b,@y,  
				@b,@x,@b,  
				@b,@b,@y,  
				@b,@x,@b],
	  }
	end

	def get_map
	  line = ''
	  (0 .. @size*2+2).each do |i|
		@num.each_char do |e|
		  line += (get_line(e, i, @size) + @b )
		end
		line += "\n"
	  end
	  line
	end

	def get_line(e, index, size)
	  m= @board[e]
	  return m[0] + m[1]*(size) + m[2] if index == 0
	  return m[3] + m[4]*(size) + m[5] if index > 0 and index < size +1
	  return m[6] + m[7]*(size) + m[8] if index == size + 1
	  return m[9] + m[10]*(size) + m[11] if index > size+ 1 and index < size*2 + 2
	  return m[12] + m[13]*(size) + m[14] if index == size*2+2
	end
    
  def parse_options
    options = OptionParser.new 
    options.banner = "Usage:\n    lcd.rb [options] <numbers>\nexample:\n    lcd.rb 1234 \n    lcd.rb -s 3 1234\n    lcd.rb -s 4 -x '_' -y '\\' 1234\noptions:"
    options.on('-s', '--size SIZE',          "specify the size of bars")            {|size| @size = size.to_i }
    options.on('-x', '--xbar XBAR',          "specify the bar of horizon")            {|x| @x = x }
    options.on('-y', '--ybar YBAR',          "specify the bar of vertical")            {|y| @y = y }
    options.on('-b', '--blankbar BBAR',          "specify the bar of blank")            {|b| @b = b }
    options.on('-h', '--help',          "Show this message")          { puts(options); exit }
    options.parse!(@arguments)
    if @arguments.empty?
      puts options 
      exit
    end
  end
  end
end

runner = Lcd::Runner.new(ARGV, STDIN, STDOUT)
runner.run
