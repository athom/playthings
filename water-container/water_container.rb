def find_water_container array
  i = 0
  j = array.count - 1

  area = 0
  while i < j
    new_area = (j-i) * (array[i] < array[j] ? array[i] : array[j])
    if new_area > area
      area = new_area
    end

    if array[i] < array[j]  # 因为左右夹逼,所以底边越来越小,所以要淘汰矮的元素, 位置高的元素保持,位置低的继续收敛夹逼,这样能保持面积单调递增
      k = i
      i += 1 while array[i] <= array[k]  #前面如果都是短板, 面积肯定不如原来, 可以快进到比原来高的元素
    else
      k = j
      j -= 1 while array[j] <= array[k]
    end

  end
  area
end

p find_water_container [4, 3, 1, 2]
p find_water_container [1, 1, 1, 1, 1, 7, 9,3,4]
