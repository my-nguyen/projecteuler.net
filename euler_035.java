import java.util.*;

public class euler_035
{
   static boolean[] getPrimes(int target)
   {
      // by default all elements in a boolean[] are initialized to false
      boolean[] primes = new boolean[target];
      // re-set all elements in the boolean[] to true
      Arrays.fill(primes, true);
      for (int i = 2; i < target; i++)
      {
         if (primes[i]) {
            int multiple = 2;
            while (i*multiple < target) {
               // all multiples of a prime numbers (2p, 3p, 4p, etc) are not primes.
               // So turn off bit at (i*multiple)th position.
               primes[i*multiple] = false;
               multiple += 1;
            }
         }
      }
      return primes;
   }

   static String toString(boolean[] primes) {
      final int PER_ROW = 10;
      int print = 0;
      StringBuilder builder = new StringBuilder();
      for (int i = 2; i < primes.length; i++) {
         if (primes[i]) {
            if (print != 0 && print % PER_ROW == 0)
               builder.append("\n");
            builder.append(i).append(" ");
            print += 1;
         }
      }
      return builder.toString();
   }

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

   static void rotateDigits(Deque<Integer> digits) {
      int head = (int)digits.pop();
      digits.add(head);
   }

   static int getNumber(Deque<Integer> digits) {
      Iterator it = digits.iterator();
      int number = (int)it.next();
      while (it.hasNext()) {
         int digit = (int)it.next();
         number = number*10 + digit;
      }
      return number;
   }

   static int mySolution() {
      final int MAX = 1000000;
      // calculate all the primes number up the MAX
      boolean[] primes = getPrimes(MAX);
      List<Integer> circulars = new ArrayList<>();
      for (int i = 2; i < primes.length; i++) {
         // if number at i is prime
         if (primes[i]) {
            // break up the number into digits
            Deque<Integer> digits = extractDigits(i);
            boolean isCirCular = true;
            // how many times to rotate
            int rotateCount = digits.size();
            for (int j = 0; j < rotateCount; j++) {
               // rotate the digits
               rotateDigits(digits);
               // compose a number out of the rotated digits
               int number = getNumber(digits);
               // if the rotated number is not a prime, then the original number
               // is not circular
               if (!primes[number]) {
                  isCirCular = false;
                  break;
               }
            }

            // only save circular numbers
            if (isCirCular) {
               // System.out.println(i);
               circulars.add(i);
            }
         }
      }
      return circulars.size();
   }

   public static void main(String[] args) {
      System.out.println(mySolution());
   }
}
