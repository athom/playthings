require 'optparse'

module MatrixTrails
  class Runner
    def initialize(arguments, stdin, stdout)
      @arguments = arguments
      parse_options
      row = @arguments[0].to_i
      column = @arguments[1].to_i
      if row <=0 or column <= 0
        puts @options
        exit
      end

      @game = Generator.new row, column
    end
    
    def run
      #p @arguments
      @game.display
    end
    
    private
    
    def parse_options
      @options = OptionParser.new 
      @options.banner = "Usage: spiral <height> <width> [options]"
      @options.on('-h', '--help',          "Show this message")          { puts(@options); exit }
      @options.parse!(@arguments)
    end
  end
end
