$: << '.'
require_relative 'test_helper'
class TestChessValidate < Test::Unit::TestCase
  include Chess
  def setup
	path_prj = File.expand_path( File.join( File.dirname(__FILE__), '..' ) )
  end

  def test_unit_attributes
	k = Unit.new([1,0], :black, :knight)
	assert(k.current_pos == [1,0])
	assert(k.type == :knight, 'unint type should be :kight')
	assert(k.color == :black, 'knight color should be black')
  end

  def test_bishop_movements
	u = Unit.new([3,3], :white, :bishop)
	wm = WorldModel.new
	wm.add_unit(u)
	assert(u.legal_move_to?([0,0]) == true, 'bishop can go very far')
	assert(u.legal_move_to?([7,7]) == true, 'bishop can go very far')
	assert(u.legal_move_to?([6,0]) == true, 'bishop can go very far')
	assert(u.legal_move_to?([0,6]) == true, 'bishop can go very far')
	assert(u.legal_move_to?([2,2]) == true, 'bishop can go near by')
	assert(u.legal_move_to?([4,4]) == true, 'bishop can go near by')
	assert(u.legal_move_to?([2,4]) == true, 'bishop can go near by')
	assert(u.legal_move_to?([4,2]) == true, 'bishop can go near by')

	assert(u.legal_move_to?([3,3]) == false, 'bishop can not kill himself')
	assert(u.legal_move_to?([8,8]) == false, 'bishop can not go too far')
	assert(u.legal_move_to?([-1,-1]) == false, 'bishop can not go too far')

	q = Unit.new([2,2], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'bishop can kill enemy near by')

	q = Unit.new([7,7], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'bishop can kill enemy far away')

	q = Unit.new([2,2], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'bishop can not kill friend')

	q = Unit.new([7,7], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'bishop can not kill friend')
  end

  def test_king_movements
	u = Unit.new([3,3], :white, :king)
	wm = WorldModel.new
	wm.add_unit(u)
	assert(u.legal_move_to?([3,2]) == true, 'king can go ahead')
	assert(u.legal_move_to?([3,4]) == true, 'king can go back')
	assert(u.legal_move_to?([4,3]) == true, 'king can go right')
	assert(u.legal_move_to?([4,2]) == true, 'king can go right down')
	assert(u.legal_move_to?([4,4]) == true, 'king can go right up')
	assert(u.legal_move_to?([3,1]) == false, 'king can not go too far')
	assert(u.legal_move_to?([7,7]) == false, 'king can not fly')
	assert(u.legal_move_to?([-1,3]) == false, 'king can not go out of board')
	assert(u.legal_move_to?([3,3]) == false, 'king can not kill himself')

	q = Unit.new([3,2], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'king can kill enemy')
	assert(u.legal_move_to?([2,3]) == false, 'king can go to dangerous position')
	assert(u.legal_move_to?([4,3]) == false, 'king can go to dangerous position')

	k = Unit.new([1,1], :black, :knight)
	wm.add_unit(k)
	assert(q.protected?, 'enemy queen should be protected by her knight')
	assert(u.legal_move_to?(q.current_pos) == false, 'king can not kill protected enemy')

	q = Unit.new([0,2], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'king can not kill friend')
  end


  def test_knight_movements
	k = Unit.new([3,3], :black, :knight)
	wm = WorldModel.new
	wm.add_unit(k)
	assert(k.next_movements.include?([1,4]) == true, 'knight next movements should contains [1, 4]')
	assert(k.next_movements.include?([1,2]) == true, 'knight next movements should contains [1, 2]')
	assert(k.next_movements.include?([2,1]) == true, 'knight next movements should contains [2, 1]')
	assert(k.next_movements.include?([2,5]) == true, 'knight next movements should contains [2, 5]')
	assert(k.next_movements.include?([4,1]) == true, 'knight next movements should contains [4, 1]')
	assert(k.next_movements.include?([4,5]) == true, 'knight next movements should contains [4, 5]')
	assert(k.next_movements.include?([5,2]) == true, 'knight next movements should contains [5, 2]')
	assert(k.next_movements.include?([5,4]) == true, 'knight next movements should contains [5, 4]')
	assert(k.next_movements.include?([4,4]) == false, 'knight next movements should not contains [4, 4]')

	q = Unit.new([1,4], :black, :queen)
	wm.add_unit(q)
	assert(k.next_movements.include?([1,4]) == false, 'knight next movements should not contains friend unit')

	q = Unit.new([1,2], :white, :queen)
	wm.add_unit(q)
	assert(k.next_movements.include?([1,2]) == true, 'knight next movements should contains enemy unit')
  end

  def test_queen_movements
	u = Unit.new([3,3], :white, :queen)
	wm = WorldModel.new
	wm.add_unit(u)
	assert(u.legal_move_to?([0,0]) == true, 'queen can go very far')
	assert(u.legal_move_to?([7,7]) == true, 'queen can go very far')
	assert(u.legal_move_to?([6,0]) == true, 'queen can go very far')
	assert(u.legal_move_to?([0,6]) == true, 'queen can go very far')
	assert(u.legal_move_to?([2,2]) == true, 'queen can go near by')
	assert(u.legal_move_to?([4,4]) == true, 'queen can go near by')
	assert(u.legal_move_to?([2,4]) == true, 'queen can go near by')
	assert(u.legal_move_to?([4,2]) == true, 'queen can go near by')
	assert(u.legal_move_to?([3,0]) == true, 'queen can go very far')
	assert(u.legal_move_to?([3,7]) == true, 'queen can go very far')
	assert(u.legal_move_to?([0,3]) == true, 'queen can go very far')
	assert(u.legal_move_to?([7,3]) == true, 'queen can go very far')
	assert(u.legal_move_to?([2,3]) == true, 'queen can go near by')
	assert(u.legal_move_to?([4,3]) == true, 'queen can go near by')
	assert(u.legal_move_to?([3,2]) == true, 'queen can go near by')
	assert(u.legal_move_to?([3,4]) == true, 'queen can go near by')

	assert(u.legal_move_to?([3,3]) == false, 'queen can not kill himself')
	assert(u.legal_move_to?([3,8]) == false, 'queen can not go too far')
	assert(u.legal_move_to?([3,-1]) == false, 'queen can not go too far')
	assert(u.legal_move_to?([8,8]) == false, 'queen can not go too far')
	assert(u.legal_move_to?([-1,-1]) == false, 'queen can not go too far')


	q = Unit.new([2,2], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'queen can kill enemy near by')

	q = Unit.new([7,7], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'queen can kill enemy far away')

	q = Unit.new([2,2], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'queen can not kill friend')

	q = Unit.new([7,7], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'queen can not kill friend')



	q = Unit.new([3,2], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'queen can kill enemy near by')

	q = Unit.new([3,7], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'queen can kill enemy far away')

	q = Unit.new([3,2], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'queen can not kill friend')

	q = Unit.new([3,7], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'queen can not kill friend')
  end

  def test_pawn_movements
	p = Unit.new([3,3], :black, :pawn)
	wm = WorldModel.new
	wm.add_unit(p)
	assert(p.legal_move_to?([3,2]) == true, 'pawn can go ahead')
	assert(p.legal_move_to?([2,2]) == false, 'pawn can not go aside')
	assert(p.legal_move_to?([4,2]) == false, 'pawn can not go aside')

	q = Unit.new([3,2], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(p.legal_move_to?(q.current_pos) == false, 'pawn can not go ahead if friend unit is under the way')


	q = Unit.new([3,2], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(p.legal_move_to?(q.current_pos) == false, 'pawn can not go ahead if enemy is in the way')

	q = Unit.new([2,2], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(p.legal_move_to?(q.current_pos) == false, 'pawn can not go aside if friend is in the way')

	q = Unit.new([2,2], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(p.legal_move_to?(q.current_pos) == true, 'pawn can go aside if enemy is in the way')
  end

  def test_rook_movements
	u = Unit.new([3,3], :white, :rook)
	wm = WorldModel.new
	wm.add_unit(u)
	assert(u.legal_move_to?([3,0]) == true, 'rook can go very far')
	assert(u.legal_move_to?([3,7]) == true, 'rook can go very far')
	assert(u.legal_move_to?([0,3]) == true, 'rook can go very far')
	assert(u.legal_move_to?([7,3]) == true, 'rook can go very far')
	assert(u.legal_move_to?([2,3]) == true, 'rook can go near by')
	assert(u.legal_move_to?([4,3]) == true, 'rook can go near by')
	assert(u.legal_move_to?([3,2]) == true, 'rook can go near by')
	assert(u.legal_move_to?([3,4]) == true, 'rook can go near by')

	assert(u.legal_move_to?([3,3]) == false, 'rook can not kill himself')
	assert(u.legal_move_to?([3,8]) == false, 'rook can not go too far')
	assert(u.legal_move_to?([3,-1]) == false, 'rook can not go too far')

	q = Unit.new([3,2], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'rook can kill enemy near by')

	q = Unit.new([3,7], :black, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == true, 'rook can kill enemy far away')

	q = Unit.new([3,2], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'rook can not kill friend')

	q = Unit.new([3,7], :white, :queen)
	wm.clear_units
	wm.add_unit(q)
	assert(u.legal_move_to?(q.current_pos) == false, 'rook can not kill friend')
  end
end


