module TurtleTrack
  class Parser
	attr_reader :commands, :board_size

	def initialize
	  @commands = []
	  @board_size = 0
	end

	def parse(file)
	  raise 'no such file' unless File.exist?(file)

	  f = File.open(file, "r")
	  @board_size =  f.readline.chomp.to_i
	  @commands.clear
	  a = f.read.split
	  parse_str(a)

	  f.close
	end

	def parse_str(a)
	  i = 0
	  while i < a.length
		if a[i] == "FD" or a[i] == "RT" or a[i] == "LT" or a[i] == "BK"
		  @commands << [a[i], a[i+1].to_i]
		  i += 2
		elsif a[i] == "REPEAT"
		  n = a[i+1].to_i
		  l_index = a.index("[")
		  r_index = a.rindex("]")
		  sub_a = a[l_index+1 ... r_index]
		  n.times do
			parse_str(sub_a)
		  end
		  i = r_index + 1
		else
		  raise 'parse error'
		end
	  end
	end

	def add_cmd(str)
	  c = str.split
	  @commands << [s[0], s[1]]
	end

	def commands
	  @commands
	end
  end
end
