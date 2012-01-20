if ARGV.empty?
  puts 'usage peng.rb a.in'
  exit 1
end

#for the damn 1.8.7
class String
  def ord
	self[0].ord
  end
end

f = File.open(ARGV[0])
str = f.read
head = str.lines.first
num = head.to_i
num %= 26
str.sub!(head, '')
str.gsub!(/./) do |c|
  if c.ord >= 'a'.ord and c.ord <= 'z'.ord
	x = c.ord - num 
	if x < 'a'.ord
	  x = x + 26
	end
	if x > 'z'.ord
	  x = x - 26
	end
	c = x.chr
  elsif c.ord >= 'A'.ord and c.ord <= 'Z'.ord
	x = c.ord - num 
	if x < 'A'.ord
	  x = x + 26
	end
	if x > 'Z'.ord
	  x = x - 26
	end
	c = x.chr
  else
	c = c
  end
end
puts str
f.close

