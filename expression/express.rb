require "pry"
require 'minitest/autorun'

module Caculator
  class Token
    attr_reader :text, :token_type, :priority, :num

    def self.is_non_num c
      self.opertor_priority_map.has_key? c or self.brackets.include? c or c.nil?
    end

    def self.brackets
      ['(', ')']
    end

    def self.opertor_priority_map
      {
        "+" => 1,
        "-" => 1,
        "*" => 2,
        "/" => 2,
        "%" => 2,
        "^" => 3,
        "sqrt" => 3
      }
    end

    def self.opertor_argc_map
      {
        "+" => 2,
        "-" => 2,
        "*" => 2,
        "/" => 2,
        "%" => 2,
        "^" => 2,
        "sqrt" => 1
      }
    end

    def self.opertor_func_map
      {
        "+" => lambda{|x, y| x + y},
        "-" => lambda{|x, y| x - y},
        "*" => lambda{|x, y| x * y},
        "/" => lambda{|x, y| x / y},
        "%" => lambda{|x, y| x % y},
        "^" => lambda{|x, y| x ** y},
        "sqrt" => lambda{|x| Math.sqrt(x)},
      }
    end

    def init_as_number text
      Float(text)
      if text.include? '.'
        @num = text.to_f
      else
        @num = text.to_i
      end
      @text = @num.to_s
      @token_type = :number
    end

    def init_as_operator text
      @text = text
      @token_type = :operator
      @priority = Token.opertor_priority_map[text]
    end

    def init_as_bracket text
      @text = text
      @token_type = :bracket
    end

    def to_s
      @text
    end

    def is_open_bracket
      return @text == "("
    end

    def is_closed_bracket
      return @text == ")"
    end
  end

  class Parser
    def eat_string str
      return [nil, nil] if str.empty?
      token = Token.new

      if Token.brackets.include? str[0]
        token.init_as_bracket(str[0])
        return [str[1..-1], token]
      end

      Token.opertor_priority_map.each do |k, v|
        if str.length >= k.length and k == str[0...k.length]
          token.init_as_operator(str[0...k.length])
          return [str[k.length..-1], token]
        end
      end

      j = 0
      until Token.is_non_num(str[j])
        j += 1
      end
      token.init_as_number(str[0...j])

      return [str[j..-1], token]
    end

    def tokenize str
      @tokens = []
      express = str.gsub(/\p{Space}/,'')
      until not express.nil? and express.empty?
        express, token = eat_string express
        @tokens << token
      end
      @tokens
    end

    def postfixize
      @number_stack = []
      @operator_stack = []

      if @tokens.empty?
        raise "illegal expression"
      end

      @tokens.each do |token|
        if token.token_type == :number
          @number_stack.push token
          next
        end

        if token.token_type == :operator
          if @operator_stack.empty?
            @operator_stack.push token
            next
          end

          top_op = @operator_stack.last
          if top_op.token_type == :operator and top_op.priority < token.priority
            @operator_stack.push token
            next
          end

          while not @operator_stack.empty? and @operator_stack.last.token_type == :operator and @operator_stack.last.priority >= token.priority
            @number_stack.push @operator_stack.pop
          end
          @operator_stack.push token
        end

        if token.token_type == :bracket
          if token.is_open_bracket
            @operator_stack.push token
            next
          end

          until @operator_stack.empty? or @operator_stack.last.is_open_bracket
            @number_stack.push @operator_stack.pop
          end
          if not @operator_stack.empty? and @operator_stack.last.is_open_bracket
            @operator_stack.pop
          end
        end
      end

      until @operator_stack.empty?
        @number_stack.push @operator_stack.pop
      end
    end

    def exec
      @value_stack = []

      until @number_stack.empty?
        e = @number_stack.shift

        if e.token_type == :number
          @value_stack.push e.num
          next
        end

        argc = Token.opertor_argc_map[e.text]
        func = Token.opertor_func_map[e.text]
        if argc == 1
          v = @value_stack.pop
          if v.nil?
            raise "illegal expression"
          end
          @value_stack.push func.call(v)
        else
          # FILO Order
          v2 = @value_stack.pop
          v1 = @value_stack.pop
          if v2.nil? or v1.nil?
            raise "illegal expression"
          end
          @value_stack.push func.call(v1, v2)
        end
      end

      @value_stack.last
    end

    def tokens_string
      to_s_helper @tokens
    end

    def operator_stack_string
      to_s_helper @operator_stack
    end

    def number_stack_string
      to_s_helper @number_stack
    end

    private
      def to_s_helper tokens
        tokens.map do |t|
          t.to_s
        end
      end
  end

  def self.exec str
    parser = Parser.new
    parser.tokenize str
    parser.postfixize
    parser.exec
  end
end

class TestCauculator < Minitest::Test
  def test_eat_string
    parser = Caculator::Parser.new

    str, token = parser.eat_string "(3.14+2)-sqrt(2)"
    assert_equal("3.14+2)-sqrt(2)", str)
    assert_equal("(", token.to_s)
    assert_equal(:bracket, token.token_type)

    str, token = parser.eat_string "3.14+2)-sqrt(2)"
    assert_equal("+2)-sqrt(2)", str)
    assert_equal("3.14", token.to_s)
    assert_equal(:number, token.token_type)

    str, token = parser.eat_string "+2)-sqrt(2)"
    assert_equal("2)-sqrt(2)", str)
    assert_equal("+", token.to_s)
    assert_equal(:operator, token.token_type)

    str, token = parser.eat_string "2)-sqrt(2)"
    assert_equal(")-sqrt(2)", str)
    assert_equal("2", token.to_s)
    assert_equal(:number, token.token_type)

    str, token = parser.eat_string ")-sqrt(2)"
    assert_equal("-sqrt(2)", str)
    assert_equal(")", token.to_s)
    assert_equal(:bracket, token.token_type)

    str, token = parser.eat_string "-sqrt(2)"
    assert_equal("sqrt(2)", str)
    assert_equal("-", token.to_s)
    assert_equal(:operator, token.token_type)

    str, token = parser.eat_string "sqrt(2)"
    assert_equal("(2)", str)
    assert_equal("sqrt", token.to_s)
    assert_equal(:operator, token.token_type)

    str, token = parser.eat_string "(2)"
    assert_equal("2)", str)
    assert_equal("(", token.to_s)
    assert_equal(:bracket, token.token_type)

    str, token = parser.eat_string "2)"
    assert_equal(")", str)
    assert_equal("2", token.to_s)
    assert_equal(:number, token.token_type)

    str, token = parser.eat_string ")"
    assert_equal("", str)
    assert_equal(")", token.to_s)
    assert_equal(:bracket, token.token_type)

    str, token = parser.eat_string ""
    assert_equal(nil, str)
    assert_equal(nil, token)
  end

  def test_tokenize
    parser = Caculator::Parser.new
    parser.tokenize "1+1"
    assert_equal(["1", "+", "1"], parser.tokens_string)

    parser.tokenize "1+2*3"
    assert_equal(["1", "+", "2", "*", "3"], parser.tokens_string)

    parser.tokenize "1+2*3.14"
    assert_equal(["1", "+", "2", "*", "3.14"], parser.tokens_string)

    parser.tokenize "1+3.20-2*3.14"
    assert_equal(["1", "+", "3.2", "-", "2", "*", "3.14"], parser.tokens_string)

    parser.tokenize "1+3.204-2*3.14"
    assert_equal(["1", "+", "3.204", "-", "2", "*", "3.14"], parser.tokens_string)

    parser.tokenize "1+(3.204-2)*3.14"
    assert_equal(["1", "+", "(", "3.204", "-", "2", ")", "*", "3.14"], parser.tokens_string)

    parser.tokenize " ( 2 + ( ( 4 + 6 ) * (9 * 2) - ( 5 - 1)))"
    assert_equal(["(", "2", "+", "(", "(", "4", "+", "6", ")", "*", "(", "9", "*", "2", ")", "-", "(", "5", "-", "1", ")", ")", ")"], parser.tokens_string)

    parser.tokenize "( 2 + ( ( 4 + 6 ) * sqrt(5)) / 2 )"
    assert_equal(["(", "2", "+", "(", "(", "4", "+", "6", ")", "*", "sqrt", "(", "5", ")", ")", "/", "2", ")"], parser.tokens_string)
  end

  def test_postfixize
    parser = Caculator::Parser.new
    parser.tokenize("1+1")
    parser.postfixize
    assert_equal(["1", "1", "+"], parser.number_stack_string)

    parser.tokenize("1+2*3")
    parser.postfixize
    assert_equal(["1", "2", "3", "*", "+"], parser.number_stack_string)

    parser.tokenize("1+2*3.14")
    parser.postfixize
    assert_equal(["1", "2", "3.14", "*", "+"], parser.number_stack_string)

    parser.tokenize("1+3.20-2*3.14")
    parser.postfixize
    assert_equal(["1", "3.2", "+", "2", "3.14", "*", "-"], parser.number_stack_string)

    parser.tokenize("1+(3.204-2)*3.14")
    parser.postfixize
    assert_equal(["1", "3.204", "2", "-", "3.14", "*", "+"], parser.number_stack_string)

    parser.tokenize(" ( 2 + ( ( 4 + 6 ) * (9 * 2) - ( 5 - 1)))")
    parser.postfixize
    assert_equal(["2", "4", "6", "+", "9", "2", "*", "*", "5", "1", "-", "-", "+"], parser.number_stack_string)

    parser.tokenize("( 2 + ( ( 4 + 6 ) * sqrt(5)) / 2 )")
    parser.postfixize
    assert_equal(["2", "4", "6", "+", "5", "sqrt", "*", "2", "/", "+"], parser.number_stack_string)
  end

  def test_happy_paths
    assert_equal(2, (Caculator.exec "1+1"))
    assert_equal(7, (Caculator.exec "1+2*3"))
    assert_equal(7.28, (Caculator.exec "1+2*3.14"))
    assert_equal(-2.08, (Caculator.exec "1+3.20-2*3.14"))
    assert_in_delta(4.78056, (Caculator.exec "1+(3.204-2)*3.14"), 0.0001)
    assert_equal(178, (Caculator.exec "( 2 + ( ( 4 + 6 ) * (9 * 2) - ( 5 - 1)))"))
    assert_equal(13.180339887498949, (Caculator.exec "( 2 + ( ( 4 + 6 ) * sqrt(5)) / 2 )"))
  end

  def test_oops_paths
    assert_raises(RuntimeError) do
      Caculator.exec("")
    end

    assert_raises(RuntimeError) do
      Caculator.exec("1+")
    end

    assert_raises(RuntimeError) do
      Caculator.exec("+")
    end

    assert_raises(RuntimeError) do
      Caculator.exec("+1")
    end

    assert_raises(ArgumentError) do
      Caculator.exec("a+c")
    end

    assert_raises(ZeroDivisionError) do
      Caculator.exec("1/0")
    end
  end
end
