import java.math.BigInteger;

public class euler_020
{
  static BigInteger factorial(int number)
  {
    BigInteger product = BigInteger.valueOf(1);
    for (int i = 1; i <= number; i++)
      product = product.multiply(BigInteger.valueOf(i));
    return product;
  }

  public static void main(String[] args)
  {
    int[] targets = { 10, 100 };
    for (int target : targets)
    {
      int sum = 0;
      // take the factorial of target number, the factorial being a BigInteger,
      // convert the BigInteger into a String, then convert the String into an
      // array of digit-characters, before summing up all the digits in the array
      BigInteger factorial = factorial(target);
      for (char digit : factorial.toString().toCharArray())
        sum += digit - '0';
      System.out.println("factorial(" + target + "): " + factorial + ", sum: " + sum);
    }
  }
}
