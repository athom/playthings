module MatrixTrails
  class Core
    OP_PLUS = 0
    OP_MULTIPLY = 1

    attr_reader :array

    def initialize array_2d
      @array = array_2d
      @height = @array.length
      @width = @height > 0 ? @array[0].length : 0
      @operation = OP_PLUS
    end

    def spiral_indexes
      positions = (0...@height).to_a.product((0...@width).to_a).to_a

      def positions.trim_line(need_revert, index)
        line = []
        self.reject! do |pair|
          if yield pair
            line.push pair
          end
        end

        if need_revert
          line.sort! do |pair1, pair2|
            pair2[index] <=> pair1[index]
          end
        end
        line
      end

      trails = []
      i = 0
      until positions.empty?
        trails += positions.trim_line(false, 0) {|pair| pair[0] == i}
        trails += positions.trim_line(false, 1) {|pair| pair[1] == @width -1 -i}
        trails += positions.trim_line(true, 1) {|pair| pair[0] == @height -1 -i}
        trails += positions.trim_line(true, 0) {|pair| pair[1] == i}
        i += 1
      end
      trails
    end

    def spiral_trails
      trails = []
      indexes = spiral_indexes
      indexes.each do |step|
        x = step[0]
        y = step[1]
        element = @array[x][y]
        trails.push element
      end
      trails
    end

    def set_operation op
      @operation = op
    end

    def final_value
      trails = spiral_trails
      if trails.empty?
        return 0
      end

      case @operation
      when OP_PLUS
        value = trails.inject(:+)
      when OP_MULTIPLY
        value = trails.inject(:*)
      end
      value
    end

  end
end
