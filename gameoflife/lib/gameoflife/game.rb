module GameOfLife
  MAX_WIDTH = 30
  MAX_HEIGH = 25

  RAND_MIN_WIDTH = 3
  RAND_MAX_WIDTH = 10
  RAND_MIN_HEITG = 3
  RAND_MAX_HEITG = 10

  class Game
    def initialize 
      if block_given?
        yield self 
      end

      @core = load_map generate_random_array
    end

    def generate_random_array
      rd = Random.new(Random.new_seed)
      width = rd.rand(RAND_MIN_WIDTH..RAND_MAX_WIDTH)
      heigth = rd.rand(RAND_MIN_HEITG..RAND_MAX_HEITG)
      array = []
      (0..heigth).each do 
        row = []
        (0..width).each do
          row.push rd.rand(0..1) 
        end
        array.push row
      end
      array
    end

    def load_map array
      @core = Core.new(array)
    end

    def display_world
      (-MAX_HEIGH..MAX_HEIGH).each do |i|
        (-MAX_WIDTH..MAX_WIDTH).each do |j|
          if @core.world[[i,j]].nil?
            print "   "
          else
            print " 1 "
          end
        end
        puts ""
      end
    end

    def single_step
      @core.next_world
      display_world
    end

    def run
      while true
        single_step
        sleep 1
      end
    end
  end
end
