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
      for (char digit : string.toCharArray())
        sum += digit - '0';
      System.out.println("2^" + exponent + ": " + power + ", sum: " + sum);
    }
  }
}
