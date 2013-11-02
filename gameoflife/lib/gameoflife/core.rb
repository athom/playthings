module GameOfLife
  class Core
    LIVE = 1
    DEAD = nil
    attr_reader :world
    def initialize array
      @world = {}
      array.each_with_index do |row, row_index|
        row.each_with_index do |e, col_index| 
          @world[[row_index, col_index]]  = e
        end
      end

      @world.reject!{|k, v|v.nil? || v == 0}
      @static_world = @world.clone
    end

    def neighbor_count x, y
      count_map = {}
      (-1..1).each do |i|
        (-1..1).each do |j|
          count_map[[x+i,y+j]] = @static_world[[x+i,y+j]]
        end
      end
      count_map.reject! {|k, v| v.nil?}
      count_map.count - count_map[[x,y]].to_i
    end

    def next_world
      visited_pos = {}
      @static_world.each do |k, v|
        x,y = k[0], k[1]
        (-1..1).each do |i|
          (-1..1).each do |j|
            if not visited_pos[[x+i,y+j]]
              @world[[x+i,y+j]] = next_state(x+i, y+j)
              visited_pos[[x+i,y+j]] = true
            end
          end
        end
      end

      @world.reject!{|k, v|v.nil?}
      @static_world = @world.clone
    end

    def next_state x, y
      conditions = {
        1 => DEAD,
        2 => @static_world[[x,y]],
        3 => LIVE,
        4 => DEAD,
        5 => DEAD,
        6 => DEAD,
        7 => DEAD,
        8 => DEAD
      }[neighbor_count x, y]
    end

  end
end
