def count(total, denominations):
  list = []
  # special case when there's only one denomination left: create and return a
  # array of array of integer where the inner array of integer contains only the
  # division of total over the one denomination.
  if (len(denominations) == 1):
    sublist = []
    sublist.append(total/denominations[0])
    list.append(sublist)
  else:
    # try different combinations by multiplying the head denomination with
    # 0, 1, 2, etc.
    for i in range(0, total/denominations[0]+1):
      new_total = total - denominations[0]*i
      sub_denominations = denominations[1:]
      # recursive call with a new total and a sub array formed by removing
      # the head element from the list of denominations.
      for sublist in count(new_total, sub_denominations):
        # generate a new array of array of integer by prepending the head
        # denomination to the array of array of integer returned from the recursive
        # call
        entry = []
        entry.append(i)
        entry += sublist
        list.append(entry)
  return list

denominations = [ 200, 100, 50, 20, 10, 5, 2, 1 ]
list = count(200, denominations)
for sublist in list:
  print sublist
print len(list)
