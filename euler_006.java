import java.math.*;

class euler_006
{
  static BigInteger mine_square_sum(long max)
  {
    BigInteger sum = BigInteger.ZERO;
    for (int i = 1; i <= max; i++)
      sum = sum.add(BigInteger.valueOf(i));
    return sum.pow(2);
  }

  static BigInteger mine_sum_squares(long max)
  {
    BigInteger sum = BigInteger.ZERO;
    for (int i = 1; i <= max; i++)
      sum = sum.add(BigInteger.valueOf(i).pow(2));
    return sum;
  }

  // 1+2+3+4+…+N = N*(N+1)/2
  static BigInteger arith_square_sum(long max)
  {
    BigInteger but = BigInteger.valueOf(max);
    return but.multiply(but.add(BigInteger.ONE)).divide(BigInteger.valueOf(2)).pow(2);
  }

  // sum of squares = N*(N+1)*(2*N+1)/6;
  static BigInteger arith_sum_squares(long max)
  {
    BigInteger but = BigInteger.valueOf(max);
    return but.multiply(but.add(BigInteger.ONE)).multiply(BigInteger.valueOf(2).multiply(but).add(BigInteger.ONE)).divide(BigInteger.valueOf(6));
  }

  public static void main(String[] args)
  {
    int targets[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    for (long target : targets)
      System.out.println("Mine(" + target + "): " + mine_square_sum(target).subtract(mine_sum_squares(target)));
    for (long target : targets)
      System.out.println("Arithmetic(" + target + "): " + arith_square_sum(target).subtract(arith_sum_squares(target)));
  }
}
