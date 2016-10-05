import java.util.*;

class Digits {
   Deque<Integer> digits;

   Digits(int number) {
      digits = new LinkedList<>();
      while (number > 0) {
         // extract the least-significant digit
         int digit = number % 10;
         // add the digit to the beginning of the Deque
         digits.push(digit);
         number /= 10;
      }
   }

   int size() {
      return digits.size();
   }

   void rotate() {
      int head = (int)digits.pop();
      digits.add(head);
   }

   int toInt() {
      Iterator it = digits.iterator();
      int number = (int)it.next();
      while (it.hasNext()) {
         int digit = (int)it.next();
         number = number*10 + digit;
      }
      return number;
   }
}

class Primes {
   boolean[] primes;

   Primes(int target)
   {
      // by default all elements in a boolean[] are initialized to false
      primes = new boolean[target];
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
   }

   boolean isPrime(int number) {
      return primes[number];
   }

   public String toString() {
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
}

public class euler_035
{
   static int mySolution() {
      final int MAX = 1000000;
      // calculate all the primes number up the MAX
      Primes primes = new Primes(MAX);
      List<Integer> circulars = new ArrayList<>();
      for (int i = 2; i < MAX; i++) {
         // if number at i is prime
         if (primes.isPrime(i)) {
            // break up the number into digits
            Digits digits = new Digits(i);
            boolean isCirCular = true;
            // how many times to rotate
            int rotateCount = digits.size();
            for (int j = 0; j < rotateCount; j++) {
               // rotate the digits
               digits.rotate();
               // compose a number out of the rotated digits
               int number = digits.toInt();
               // if the rotated number is not a prime, then the original number
               // is not circular
               if (!primes.isPrime(number)) {
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
