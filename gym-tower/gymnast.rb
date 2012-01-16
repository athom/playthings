#!/usr/bin/env ruby
class Point
  attr_accessor :x, :y, :links
  def initialize(x, y)
	@x = x
	@y = y
	@links = []
  end

  def ==(p)
	@x == p.x and @y == p.y
  end

  def <(p)
	@x < p.x and @y < p.y
  end

  def >(p)
	@x > p.x and @y > p.y
  end

  #ruby 1.8.7 get syntax error
  #def !=(p)
	#!(self > p or self < p or self == p)
  #end

  def to_s
	print ('(' + @x.to_s + ', ' + @y.to_s + ')')
  end
end

class Kudo
  attr_accessor :points
  def initialize
	@points = [Point.new(0,0)]
  end

  def clean_room_between?(a, b)
	if a == b or !(a < b  or a > b)
	  return false
	end
	others = @points.reject{|x| x == a and x == b}
	for o in others
	  return false if a < o and o < b
	  return false if a > o and o > b
	end
	return true
  end

  def link(p)
	@points.reject{|x| x == p}.each do |o|
	  p.links << o if clean_room_between?(p, o) and p < o
	end
  end

  def setup_tree()
	@points.each{|p| link p}
  end

  def height_of(point)
	if point.links.empty?
	  return 0
	end
	max = 0
	for q in point.links
	  tmp = 1 + height_of(q)
	  max = tmp if max < tmp
	end
	max
  end

  def input(file_name)
	f = File.open(file_name, 'r')
	f.each_line do |l|
	  l.delete! '('
	  l.rstrip!
	  zs = l.split(')')
	  zs.each do |z|
		z.lstrip!	
		ms = z.split(',')
		@points << Point.new(ms[0].to_i, ms[1].to_i)
	  end
	end
  end

  def output 
	setup_tree
	p height_of(@points[0])
  end
end

if ARGV.empty?
  puts 'usage ./gymnast.rb xxx.in'
  exit 1
end
k = Kudo.new
k.input(ARGV[0])
k.output
