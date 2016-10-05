import java.util.*;

public class euler_034
{
   // a cache of the factorial of the digits from 0 to 9
   static int[] factorials = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

   // this method extracts digits from a number and return the digits in a Deque
   // e.g. if number is 145, then the returned Deque is { 1, 4, 5 }
   static Deque<Integer> extractDigits(int number) {
      Deque<Integer> digits = new LinkedList<>();
      while (number > 0) {
         // extract the least-significant digit
         int digit = number % 10;
         // add the digit to the beginning of the Deque
         digits.push(digit);
         number /= 10;
      }
      return digits;
   }

   // this method returns the sum of the factorial of all digits in a number
   static long sumFactorials(int number) {
      long sum = 0;
      Deque<Integer> digits = extractDigits(number);
      Iterator it = digits.iterator();
      while (it.hasNext()) {
         // get a single digit
         int digit = (int)it.next();
         // take the factorial of the digit
         int factorial = factorials[digit];
         // sum up the factorial
         sum += factorial;
      }
      return sum;
   }

   // mathblog has no other solution than brute force
   static List<Integer> mySolution() {
      List<Integer> list = new ArrayList<>();
      for (int i = 10; i < 50000; i++) {
         long sum = sumFactorials(i);
         // the number equals the sum of the factorial of all its digits
         if (i == sum) {
            list.add(i);
            // System.out.print(i + " = ");
            System.out.println(i);
            Deque<Integer> digits = extractDigits(i);
            Iterator it = digits.iterator();
            while (it.hasNext()) {
               int digit = (int)it.next();
               int factorial = factorials[digit];
               // System.out.print(factorial + "+");
            }
         }
      }
      return list;
   }

   public static void main(String[] args)
   {
      List<Integer> numbers = mySolution();
      int sum = 0;
      for (int number : numbers) {
         sum += number;
      }
      System.out.println(sum);
   }
}
