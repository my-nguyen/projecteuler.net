import java.util.*;

class test01
{
  static int func(int number)
  {
    return number;
  }
  static int func(int number1, int number2)
  {
    return number1 + number2;
  }

  public static void main(String[] args)
  {
    // System.out.println("func(5): " + func(5));
    // System.out.println("func(5, 3): " + func(5, 3));
    List<List<Integer>> list = new ArrayList<>();
    for (int i = 1; i < 4; i++)
    {
      List<Integer> array = new ArrayList<Integer>();
      for (int j = 0; j < 5; j++)
        array.add(j*i);
      list.add(array);
    }

    System.out.println(list);
    for (List<Integer> array : list)
      System.out.println(array);
  }
}
