module Chess
  class WorldModel
	attr_reader :units
	def initialize
	  @units = []
	end

	def add_unit unit
	  unit.setup(self)
	  @units << unit
	end

	def delete_unit unit
	  @units.delete(unit)
	end

	def clear_units
	  @units.clear
	end

	def unit_at(pos)
	  @units.each do |u|
		if u.current_pos == pos
		  return u
		end
	  end
	  return nil
	end

	def next_movements(unit)
	  case unit.type
	  when :knight
		next_movements_for_knight(unit)
	  when :pawn
		next_movements_for_pawn(unit)
	  when :rook
		next_movements_for_rook(unit)
	  when :king
		next_movements_for_king(unit)
	  when :queen
		next_movements_for_queen(unit)
	  when :bishop
		next_movements_for_bishop(unit)
	  else
		raise 'type error'
	  end
	end

	def protected?(unit)
	  friends = friends(unit)
	  pos = unit.current_pos
	  delete_unit(unit)
	  friends.each do |u|
		if u.next_movements.include? pos
		  add_unit(unit)
		  return true
		end
	  end
	  add_unit(unit)
	  return false
	end
	
	private 
	def enemies(unit)
	  uu = []
	  @units.each do |u|
		uu << u if u.color != unit.color
	  end
	  uu
	end
	
	def friends(unit)
	  uu = []
	  @units.each do |u|
		uu << u if u.color == unit.color and u != unit
	  end
	  uu
	end

	def enemy_at?(unit, pos)
	  enemies(unit).each do |u|
		return true if u.current_pos == pos
	  end
	  return false
	end

	def friend_at?(unit, pos)
	  friends(unit).each do |u|
		return true if u.current_pos == pos
	  end
	  return false
	end


	def dangerous_at?(unit, pos)
	  enemies = enemies(unit)
	  delete_unit(unit)
	  enemies.each do |u|
		if u.current_pos == pos and u.protected?
		  add_unit(unit)
		  return true
		else
		  if u.next_movements.include? pos
			add_unit(unit)
			return true
		  end
		end
	  end
	  add_unit(unit)
	  return false
	end

	def next_movements_for_knight(unit)
	  x, y = unit.current_pos
	  pp = []
	  pp << [x+1, y+2]
	  pp << [x+1, y-2]
	  pp << [x-1, y+2]
	  pp << [x-1, y-2]
	  pp << [x+2, y+1]
	  pp << [x+2, y-1]
	  pp << [x-2, y+1]
	  pp << [x-2, y-1]

	  pp.delete_if do |p|
		 p[0] < 0 or p[0] > 7 or p[1] < 0 or p[1] > 7 
	  end

	  friends(unit).each do |u|
		if pp.include? u.current_pos
		  pp.delete u.current_pos
		end
	  end
	  pp
	end

	def next_movements_for_pawn(unit)
	  x, y = unit.current_pos
	  pp = []
	  white_init_pos = [[0,1], [1,1], [2,1], [3,1], [4,1], [5,1], [6,1], [7,1]]
	  black_init_pos = [[0,6], [1,6], [2,6], [3,6], [4,6], [5,6], [6,6], [7,6]]
	  init_pos = unit.color == :white ? white_init_pos : black_init_pos
	  step = unit.color == :white ? 1 : -1

	  pp << [x, y+step] unless enemy_at?(unit, [x, y+step])
	  pp << [x+1, y+step] if enemy_at?(unit, [x+1, y+step])
	  pp << [x-1, y+step] if enemy_at?(unit, [x-1, y+step])
	  pp << [x, y+2*step] if init_pos.include? unit.current_pos

	  pp.delete_if do |p|
		p[0] < 0 or p[0] > 7 or p[1] < 0 or p[1] > 7
	  end

	  friends(unit).each do |u|
		if pp.include? u.current_pos
		  pp.delete u.current_pos
		end
	  end
	  pp
	end

	def next_movements_for_rook(unit)
	  x, y = unit.current_pos
	  pp = []

	  for i in x+1 .. 7
		if friend_at?(unit, [i, y])
		  break
		elsif enemy_at?(unit, [i, y])
		  pp << [i, y]
		  break
		else
		  pp << [i, y]
		end
	  end

	  i = x-1
	  while i >= 0
		if friend_at?(unit, [i, y])
		  break
		elsif enemy_at?(unit, [i, y])
		  pp << [i, y]
		  break
		else
		  pp << [i, y]
		end
		i -= 1
	  end

	  i = y-1
	  while i >= 0
		if friend_at?(unit, [x, i])
		  break
		elsif enemy_at?(unit, [x, i])
		  pp << [x, i]
		  break
		else
		  pp << [x, i]
		end
		i -= 1
	  end

	  for i in y+1 .. 7
		if friend_at?(unit, [x, i])
		  break
		elsif enemy_at?(unit, [x, i])
		  pp << [x, i]
		  break
		else
		  pp << [x, i]
		end
	  end

	  pp.delete_if do |p|
		p[0] < 0 or p[0] > 7 or p[1] < 0 or p[1] > 7
	  end

	  pp
	end

	def next_movements_for_king(unit)
	  x, y = unit.current_pos
	  pp = []
	  pp << [x+1, y+1]
	  pp << [x+1, y]
	  pp << [x+1, y-1]
	  pp << [x, y-1]
	  pp << [x-1, y-1]
	  pp << [x-1, y]
	  pp << [x-1, y+1]
	  pp << [x, y+1]

	  pp.delete_if do |p|
		p[0] < 0 or p[0] > 7 or p[1] < 0 or p[1] > 7 or dangerous_at?(unit, p)
	  end

	  friends(unit).each do |u|
		if pp.include? u.current_pos
		  pp.delete u.current_pos
		end
	  end
	  pp
	end

	def next_movements_for_queen(unit)
	  next_movements_for_bishop(unit) + 
	  next_movements_for_rook(unit)  
	end

	def next_movements_for_bishop(unit)
	  x, y = unit.current_pos
	  pp = []
	  for i in 1 .. 7
		p = [x+i, y+i]
		if friend_at?(unit, p)
		  break
		elsif enemy_at?(unit, p)
		  pp << p
		  break
		else
		  pp << p
		end
	  end

	  for i in 1 .. 7
		p = [x+i, y-i]
		if friend_at?(unit, p)
		  break
		elsif enemy_at?(unit, p)
		  pp << p
		  break
		else
		  pp << p
		end
	  end

	  for i in 1 .. 7
		p = [x-i, y+i]
		if friend_at?(unit, p)
		  break
		elsif enemy_at?(unit, p)
		  pp << p
		  break
		else
		  pp << p
		end
	  end

	  for i in 1 .. 7
		p = [x-i, y-i]
		if friend_at?(unit, p)
		  break
		elsif enemy_at?(unit, p)
		  pp << p
		  break
		else
		  pp << p
		end
	  end

	  pp.delete_if do |p|
		p[0] < 0 or p[0] > 7 or p[1] < 0 or p[1] > 7
	  end
	  pp
	end
  end
end
