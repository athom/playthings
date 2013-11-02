require 'optparse'

module GameOfLife
  class Runner
    def initialize(arguments, stdin, stdout)
      @arguments = arguments
      @game = Game.new
    end
    
    def run
      parse_options
      @game.run
    end
    
    private
    
    def parse_options
      options = OptionParser.new 
      options.banner = "Usage: gameoflife [options]"
      options.on('-h', '--help',          "Show this message")          { puts(options); exit }
      options.parse!(@arguments)
    end
  end
end
