module Chess
  class Unit
	TYPE = {"B" => :bishop, "N" => :knight, "K" => :king, "P" => :pawn, "Q" => :queen, "R" => :rook}
	attr_reader :current_pos, :color, :type
	def initialize(pos, color, type)
		@current_pos = pos
		@color = color
		@type = type
	end

	def setup(wm)
	  @wm = wm
	end

	def next_movements
	  @wm.next_movements(self)
	end

	def protected?
	  @wm.protected?(self)
	end

	def legal_move_to?(pos)
	  next_movements.include?(pos)
	end

	def to_s
	  puts "color:" + @color.to_s + ",	type:" + @type.to_s + ',	  pos:' + @current_pos.to_s
	end
  end
end
