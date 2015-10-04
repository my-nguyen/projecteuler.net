import java.math.BigInteger;

public class euler_025
{
  public static void main(String[] args)
  {
    BigInteger limit = new BigInteger("10").pow(999);
    BigInteger fib1 = BigInteger.valueOf(1);
    BigInteger fib2 = BigInteger.valueOf(1);
    BigInteger fib3 = fib1.add(fib2);
    int index = 3;
    while (fib3.compareTo(limit) < 0)
    {
      fib1 = fib2;
      fib2 = fib3;
      fib3 = fib1.add(fib2);
      index += 1;
    }

    System.out.println("index: " + index);
  }
}
