# for an explanation on how to find the recurring cycles, refer to
# http://www.mathblog.dk/project-euler-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/

# this is a convenience class to bundle several pieces of information to return
# to the caller
class Decimal
  attr_accessor :data, :recurring, :start, :length

  def initialize(info, repeating, commencement=0, longueur=0)
    @data = info
    @recurring = repeating
    @start = commencement
    @length = longueur
  end
end

def decimal(number)
  remainders = []
  builder = ""
  divider = 10
  while (divider != 0)
    remainder = divider % number
    start = remainders.index(remainder)
    # a cycle recurs when a remainder repeats
    if (start != nil)
      # record the length of the recurring cycle
      length = builder.length - start
      return Decimal.new(builder, true, start, length)
    # no cycle found: keep recording divisor
    else
      remainders << remainder
      builder << (divider/number + '0'.ord).chr
    end
    divider = (divider%number) * 10
  end
  Decimal.new(builder, false)
end

max = 0
number = 999
recurrence = ""
999.downto(2) do |i|
  decim = decimal(i)
  print("1/#{i}: ")
  if (!decim.recurring)
    puts("non-recurring")
  else
    length = decim.data.length - decim.start
    puts("recurring, length: #{length}")

    # look for and record the max cycle length and other useful info
    if (length > max)
      max = length
      number = i
      recurrence = decim.data[decim.start..-1]
    end
  end
end
puts("number: #{number}, length: #{max}")
