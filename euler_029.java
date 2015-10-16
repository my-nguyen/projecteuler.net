import java.util.*;
import java.math.BigInteger;

public class euler_029
{
  public static void main(String[] args)
  {
    Set<BigInteger> set = new HashSet<>();
    for (int base = 2; base <= 100; base++)
      for (int exponent = 2; exponent <= 100; exponent++)
      {
        BigInteger power = BigInteger.valueOf(base).pow(exponent);
        set.add(power);
      }
    System.out.println("Distinct terms: " + set.size());
  }
}
