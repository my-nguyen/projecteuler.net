import java.util.*;

class test3 {
   public static void main(String[] args) {
      boolean[] array = new boolean[10];
      for (boolean element : array)
         System.out.println(element);
      Arrays.fill(array, true);
      for (boolean element : array)
         System.out.println(element);
   }
}
