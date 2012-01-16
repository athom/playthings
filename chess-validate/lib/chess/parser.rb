module Chess
  class Parser
	attr_reader :cmds
	def initialize
	  @cmds = []
	  @wm = WorldModel.new
	end

	def parse_moves(fn)
	  f = File.open(fn, 'r')
	  txt =  f.read
	  lines = txt.split("\n")
	  @cmds = []
	  lines.each do |line|
		a=line.split
		@cmds << [moves2pos(a[0]), moves2pos(a[1])]
	  end
	  @cmds
	  f.close
	end

	def parse_board(fn)
	  f = File.open(fn, 'r')
	  txt = f.read
	  lines = txt.split("\n")
	  for i in 0 ... lines.count
		objects = lines[i].split
		for j in 0 ... objects.count
		  if objects[j] != "--"
			color = objects[j][0] == 'b' ? :black : :white
			type = Unit::TYPE[objects[j][1]]
			u = Unit.new([j,7-i], color, type)
			@wm.add_unit u
		  end
		end
	  end
	  f.close
	end

	def output(fn = './output.txt')
	  of = File.open(fn, 'w')
	  @cmds.each do |cmd|
		u = @wm.unit_at(cmd[0])
		if u.nil?
		  of.puts 'ILLEGAL'
		else
		  if u.legal_move_to?(cmd[1])
			of.puts 'LEGAL'
		  else
			of.puts 'ILLEGAL'
		  end
		end
	  end
	  of.close
	end

	private
	def moves2pos(str) #notice! only support ruby-1.9.2, ruby-1.8.7 does not work
	  pos = [str[0].ord - 97, str[1].to_i-1]
	end
  end
end
