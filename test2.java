import java.util.*;

class test2 {
   public static void main(String[] args) {
      int number = Integer.parseInt(args[0]);
      // Stack stack = new Stack();
      Deque<Integer> stack = new LinkedList<>();
      while (number > 0) {
         int digit = number % 10;
         System.out.println("in: " + digit);
         stack.push(digit);
         number /= 10;
      }

      for (Iterator it = stack.iterator(); it.hasNext(); ) {
         int digit = (int)it.next();
         System.out.println("out: " + digit);
      }
      int pop = (int)stack.pop();
      System.out.println("pop: " + pop);
      stack.add(pop);
      for (Iterator it = stack.iterator(); it.hasNext(); ) {
         int digit = (int)it.next();
         System.out.println("out: " + digit);
      }
   }
}
