// Power digit sum
// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
// What is the sum of the digits of the number 2^1000?
//
import java.math.*;

public class euler_016
{
  public static void main(String[] args)
  {
    int[] exponents = { 15, 50, 100, 250, 500, 750, 1000 };
    BigInteger base = new BigInteger("2");
    for (int exponent : exponents)
    {
      BigInteger power = base.pow(exponent);
      String string = power.toString();
      int sum = 0;
      int zero = Character.getNumericValue('0');
      for (char digit : string.toCharArray())
        sum += Character.getNumericValue(digit) - zero;
      System.out.println("2^" + exponent + ": " + power + ", sum: " + sum);
    }
  }
}
