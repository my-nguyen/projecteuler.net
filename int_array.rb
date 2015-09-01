module IntArray
  def output numbers
    numbers.each_index do |i|
      print " #{numbers[i]}"
      puts if ((i+1) % 10 == 0 && i != (numbers.size-1))
    end
    puts
  end
end
