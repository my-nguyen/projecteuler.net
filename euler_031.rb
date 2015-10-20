def count(total, denominations)
  list = []
  # special case when there's only one denomination left: create and return a
  # array of array of integer where the inner array of integer contains only the
  # division of total over the one denomination.
  if (denominations.size == 1)
    sublist = []
    sublist << total/denominations[0]
    list << sublist
  else
    # try different combinations by multiplying the head denomination with
    # 0, 1, 2, etc.
    (0..total/denominations[0]).each do |i|
      new_total = total - denominations[0]*i
      sub_denominations = denominations[1..-1]
      # recursive call with a new total and a sub array formed by removing
      # the head element from the list of denominations.
      count(new_total, sub_denominations).each do |sublist|
        # generate a new array of array of integer by prepending the head
        # denomination to the array of array of integer returned from the recursive
        # call
        entry = []
        entry << i
        entry += sublist
        list << entry
      end
    end
  end
  list
end

denominations = [ 200, 100, 50, 20, 10, 5, 2, 1 ]
list = count(200, denominations)
list.each do |sublist|
  print(sublist)
  puts
end
puts(list.size)
