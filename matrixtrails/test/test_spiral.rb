$LOAD_PATH << '.'
$LOAD_PATH.unshift(File.join( File.dirname(__FILE__), '..', 'lib' ))
require 'test/unit'
require 'matrixtrails'

include MatrixTrails

class TestMatrixTrails < Test::Unit::TestCase
  def setup
    @m1 = Core.new([
      [12, 32, 9, 11, 34],
      [8, 54, 76, 23, 7],
      [27, 18, 25, 9, 43],
      [11, 23, 78, 63, 19],
      [9, 22, 56, 31, 5]
    ])
    @m2 = Core.new([
      [1,2,3],
      [4,5,6],
      [7,8,9],
      [10,11,12],
    ])
    @m3 = Core.new([
      []
    ])
    @m4 = Core.new([
      [1, 2, 3, 4]
    ])
    @m5 = Core.new([
      [1],
      [2],
      [3],
      [4]
    ])
  end


  def test_spiral_indexes
    assert_equal(@m1.spiral_indexes, [[0,0], [0,1], [0,2], [0,3], [0,4], 
                                      [1,4], [2,4], [3,4], [4,4],
                                      [4,3], [4,2], [4,1], [4,0],
                                      [3,0], [2,0], [1,0], 
                                      [1,1], [1,2], [1,3],
                                      [2,3], [3,3], [3,2],
                                      [3,1], [2,1], [2,2]])
    assert_equal(@m2.spiral_indexes, [[0,0], [0,1], [0,2], 
                                      [1,2], [2,2], [3,2], 
                                      [3,1], [3,0], 
                                      [2,0], [1,0], 
                                      [1,1], [2,1]])
    assert_equal(@m3.spiral_indexes, [])
    assert_equal(@m4.spiral_indexes, [[0,0], [0,1], [0,2], [0,3]])
    assert_equal(@m5.spiral_indexes, [[0,0], [1,0], [2,0], [3,0]])
  end

  def test_spiral_trails
    assert_equal(@m1.spiral_trails, [12,32,9,11,34,7,43,19,5,31,56,22,9,11,27,8,54,76,23,9,63,78,23,18,25])
    assert_equal(@m2.spiral_trails, [1,2,3,6,9,12,11,10,7,4,5,8])
    assert_equal(@m3.spiral_trails, [])
    assert_equal(@m4.spiral_trails, [1,2,3,4])
    assert_equal(@m5.spiral_trails, [1,2,3,4])
  end

  def test_final_value
    assert_equal(@m1.final_value, 12+32+9+11+34+7+43+19+5+31+56+22+9+11+27+8+54+76+23+9+63+78+23+18+25)
    assert_equal(@m2.final_value, 1+2+3+6+9+12+11+10+7+4+5+8)
    assert_equal(@m3.final_value, 0)
    assert_equal(@m4.final_value, 1+2+3+4)
    assert_equal(@m5.final_value, 1+2+3+4)

    @m1.set_operation(Core::OP_MULTIPLY)
    @m2.set_operation(Core::OP_MULTIPLY)
    @m3.set_operation(Core::OP_MULTIPLY)
    @m4.set_operation(Core::OP_MULTIPLY)
    @m5.set_operation(Core::OP_MULTIPLY)
    assert_equal(@m1.final_value, 12*32*9*11*34*7*43*19*5*31*56*22*9*11*27*8*54*76*23*9*63*78*23*18*25)
    assert_equal(@m2.final_value, 1*2*3*6*9*12*11*10*7*4*5*8)
    assert_equal(@m3.final_value, 0)
    assert_equal(@m4.final_value, 1*2*3*4)
    assert_equal(@m5.final_value, 1*2*3*4)
  end

end
