class A
  def initialize
    @name = "Nguyen"
    @sum = 0
  end

  def sum
    @sum
  end
end

class B < A
  def initialize(a, b)
    super()
    @sum = a + b
  end
end

a = A.new
puts("#{a.sum}")
b = B.new(10, 15)
puts("#{b.sum}")
