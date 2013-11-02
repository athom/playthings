$: << '.'
require_relative 'test_helper'

class TestCoreOfLifeUnit < Test::Unit::TestCase
  def setup
    map = [
      [Core::DEAD,  Core::LIVE, Core::DEAD],
      [Core::DEAD,  Core::DEAD, Core::LIVE],
      [Core::LIVE,  Core::LIVE, Core::DEAD]
    ]
    @c = Core.new(map)
  end


  def test_neighbor_count
    assert_equal(@c.neighbor_count(0, 0), 1)
    assert_equal(@c.neighbor_count(0, 1), 1)
    assert_equal(@c.neighbor_count(0, 2), 2)

    assert_equal(@c.neighbor_count(1, 0), 3)
    assert_equal(@c.neighbor_count(1, 1), 4)
    assert_equal(@c.neighbor_count(1, 2), 2)

    assert_equal(@c.neighbor_count(2, 0), 1)
    assert_equal(@c.neighbor_count(2, 1), 2)
    assert_equal(@c.neighbor_count(2, 2), 2)
  end

  def test_next_state
    assert_equal(@c.next_state(0, 0), Core::DEAD)
    assert_equal(@c.next_state(0, 1), Core::DEAD)
    assert_equal(@c.next_state(0, 2), Core::DEAD)

    assert_equal(@c.next_state(1, 0), Core::LIVE)
    assert_equal(@c.next_state(1, 1), Core::DEAD)
    assert_equal(@c.next_state(1, 2), Core::LIVE)

    assert_equal(@c.next_state(2, 0), Core::DEAD)
    assert_equal(@c.next_state(2, 1), Core::LIVE)
    assert_equal(@c.next_state(2, 2), Core::DEAD)
  end

end
