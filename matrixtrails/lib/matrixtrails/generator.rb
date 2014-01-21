require 'colored' 
module MatrixTrails
  class Generator
    def initialize row, column
      array = []
      row.times do
        col = []
        column.times do 
          col.push(rand 100)
        end
        array.push col
      end
      @core = Core.new(array)
      @history_pos = []
    end

    def display
      @core.spiral_indexes.each do |pos|
        show_element(@core.array, pos)
        sleep(1)
      end
    end

    private

    def is_printed? x, y
      @history_pos.include? [x, y]
    end

    def is_current? pos, x, y
      pos[0] == x and pos[1] == y
    end

    def need_separated_display? pos, x, y
      is_current? pos, x, y or is_printed? x, y
    end

    def show_element(array, pos)
      array.each_with_index do |row, x| 
        row.each_with_index do |e, y|
          if need_separated_display? pos, x, y
            print e.to_s.green, " "
            @history_pos.push pos
          else
            print e, " "
          end
        end
        puts ""
      end
      puts ""
    end
  end
end
