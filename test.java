import java.util.*;

class test
{
  public static void main(String[] args)
  {
    List<Integer> list = new ArrayList<>();
    for (int i = 0; i < 10; i++)
      list.add(i);

    // int[] array = new int[10];
    Integer[] array = new Integer[10];
    for (int i = 0; i < 10; i++)
      array[i] = i;

    // String string = "0123456789";

    System.out.println("list: " + list);
    System.out.println("array: " + array);
    System.out.println("asList: " + Arrays.asList(array));
    // System.out.println("string: " + string);
    /*
    int[] array = new int[10];
    for (int i = 0; i < 10; i++)
      array[i] = i;

    Integer[] copy = Arrays.copyOf(array);
    */
  }
}
