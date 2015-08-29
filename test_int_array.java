import java.util.Random;

class test_int_array
{
  public static void main(String[] args)
  {
    int_array myv = new int_array();
    Random rand = new Random();
    for (int i = 0; i < 55; i++)
      myv.push(rand.nextInt(100));
    System.out.println("Int array UNSORTED:");
    myv.print();
    myv.sort();
    System.out.println("Int array SORTED:");
    myv.print();
  }
}
