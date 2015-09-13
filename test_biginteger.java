import java.math.*;

class test_biginteger
{
  public static void main(String[] args)
  {
    String[] strings =
    {
      "37107287533902102798797998220837590246510135740250",
      "46376937677490009712648124896970078050417018260538",
      "74324986199524741059474233309513058123726617309629"
    };
    BigInteger[] numbers = new BigInteger[3];

    for (int i = 0; i < 3; i++)
      numbers[i] = new BigInteger(strings[i]);

    for (BigInteger number : numbers)
      System.out.println("number: " + number);

BigInteger tmp = 37107287533902102798797998220837590246510135740250;
    BigInteger sum = numbers[0].add(numbers[1]);
    System.out.println("sum: " + sum);
    sum = sum.add(numbers[2]);
    System.out.println("sum: " + sum);
    String string = sum.toString();
    System.out.println("high 10: " + string.substring(0, 10) + ", low 10: "
      + string.substring(string.length()-10, string.length()));
  }
}
