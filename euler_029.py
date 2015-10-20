collection = set()
for base in range(2, 101):
  for exponent in range(2, 101):
    power = base**exponent
    collection.add(power)
print "Distinct terms:", len(collection)
