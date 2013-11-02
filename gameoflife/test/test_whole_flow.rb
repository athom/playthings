$: << '.'
require_relative 'test_helper'

class TestGameOfLifeFlow < Test::Unit::TestCase
  def test_via_data
    get_test_cases().each do |catalog, suites|
      suites.each do |suite, cases|
        map = parse_to_array(catalog + "/" + suite + "/" + cases[0])
        c = Core.new(map)
        cases.each_with_index do |name, i|
          index = i+1
          if index == cases.length 
            catalog == "spaceships" ? break : index = 0
          end
          assert_equal(c.next_world, parse_to_map(catalog + "/" + suite + "/" + cases[index]))
        end
      end
    end
  end
end
