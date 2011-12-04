module TurtleTrack
  class Turtle
	N = 0
	NE = 45
	E = 90
	SE = 135
	S = 180
	SW = 225
	W = 270
	NW = 315

	attr_accessor :facing
	attr_reader :last_pos, :track

	def initialize
	  @facing =N
	  @last_pos = [0, 0]
	  @track = [[0, 0]]
	end


	def forward(step)
	  move(step, :forward)
	end

	def backward(step)
	  move(step, :backward)
	end

	def right_rotate(degree)
	  @facing = get_dir(@facing + degree)
	end

	def left_rotate(degree)
	  @facing = get_dir(@facing - degree)
	end

	private
	def move(step, derection)
	  u = derection == :forward ? 1:-1
	  step.times do 
		new_pos = @last_pos.clone
		if @facing == N
		  new_pos[0] += 0
		  new_pos[1] += u
		elsif @facing == NE
		  new_pos[0] += u
		  new_pos[1] += u
		elsif @facing == E
		  new_pos[0] += u
		  new_pos[1] += 0
		elsif @facing == SE
		  new_pos[0] += u
		  new_pos[1] += -u
		elsif @facing == S
		  new_pos[0] += 0
		  new_pos[1] += -u
		elsif @facing == SW
		  new_pos[0] += -u
		  new_pos[1] += -u
		elsif @facing == W
		  new_pos[0] += -u
		  new_pos[1] += 0
		elsif @facing == NW
		  new_pos[0] += -u
		  new_pos[1] += u
		else 
		  raise 'ratation degree error'
		end
		@last_pos = new_pos
		@track << new_pos
	  end
	end

	def get_dir(degree)
	  dir = [N, NE, E, SE, S, SW, W, NW]
	  dir.each do |d|
		return d if degree % 360 == d
	  end
	end
  end
end
