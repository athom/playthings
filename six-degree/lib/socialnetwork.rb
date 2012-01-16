class SocialNetwork
  def initialize
	@friend_ship = {}
	@visited_list = []
  end

  def parse(fn)
	file_input = File.open(fn, 'r')
	file_input.each_line do |line|
	  a = line.split(":")
	  @friend_ship[a[0]] = [] if @friend_ship[a[0]].nil?

	  #find the name list metioned.
	  pattens = a[1].scan(/@\w+/)
	  pattens.each do |m|
		name = m.delete('@')
		@friend_ship[a[0]] << name if !@friend_ship[a[0]].include?(name)
	  end
	end
	file_input.close

	#fitter single link relation ship, make sure friend ship are double links
	tmp_hash = {}
	@friend_ship.each do |k, v|
	  tmp_hash[k] = []
	  v.each do |vv|
		if !@friend_ship[vv].nil? and @friend_ship[vv].include?(k)
		  tmp_hash[k]<<vv
		end
	  end
	end
	@friend_ship = tmp_hash
  end

  def relation_list(name, degree)
	@visited_list.clear
	get_relation_ship(name, degree)
  end

  def output(fn = 'output.txt')
	of = File.open(fn, 'w')
	ks = @friend_ship.keys.sort
	for i in 0 ... ks.count
	  of.puts ks[i]
	  6.times do  |t|
		fs = relation_list(ks[i], t+1)
		fs.sort!
		print_relation_ship(of, fs)
	  end

	  if i != ks.count - 1
		of.puts ''
	  end
	end
	of.close
  end

  private
  def print_relation_ship(of, fs)
	for i in 0 ... fs.count
	  if i == fs.count-1
		of.puts fs[i]
	  else
		of.print fs[i] + ', ' ,
	  end
	end
  end

  def get_relation_ship(name, d)
	if d == 1
	  return @friend_ship[name]
	else
	  friends = []
	  @visited_list << name

	  sub_friends = get_relation_ship(name, d-1)
	  sub_friends.each do |f|
		@visited_list << f
	  end

	  sub_friends.each do |f|
		fs = get_relation_ship(f, 1)
		fs.each do |new_f|
		  if !@visited_list.include?(new_f) and !friends.include?(new_f)
			friends << new_f
		  end
		end
	  end
	  friends
	end
  end
end
