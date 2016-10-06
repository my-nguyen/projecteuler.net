import java.util.*;

class Digits {
   // must declare as ArrayDeque and not Deque, to be able to call clone()
   ArrayDeque<Integer> digits;

   Digits(Digits rhs) {
      clone(rhs);
   }

   Digits(int number) {
      digits = new ArrayDeque<>();
      while (number > 0) {
         // extract the least-significant digit
         int digit = number % 10;
         // add the digit to the beginning of the Deque
         digits.push(digit);
         number /= 10;
      }
   }

   void clone(Digits rhs) {
      this.digits = rhs.digits.clone();
   }

   void chopLeft() {
      digits.removeFirst();
   }

   void chopRight() {
      digits.removeLast();
   }

   int size() {
      return digits.size();
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
      // 1 is not a prime
      primes[1] = false;
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

public class euler_037
{
   static boolean isPalindrome(Digits digits, boolean chopLeft, Primes primes) {
      Digits clone = new Digits(digits);
      for (int j = 0; j < digits.size()-1; j++) {
         if (chopLeft)
            clone.chopLeft();
         else
            clone.chopRight();
         int number = clone.toInt();
         if (!primes.isPrime(number)) {
            return false;
         }
      }
      return true;
   }

   static int mySolution() {
      final int MAX = 1000000;
      Primes primes = new Primes(MAX);
      int sum = 0;
      for (int i = 11; i < MAX; i += 2) {
         if (primes.isPrime(i)) {
            Digits digits = new Digits(i);
            boolean isPalindrome = isPalindrome(digits, true, primes);
            if (isPalindrome) {
               isPalindrome = isPalindrome(digits, false, primes);
            }

            if (isPalindrome) {
               System.out.println(i);
               sum += i;
            }
         }
      }
      return sum;
   }

   public static void main(String[] args) {
      System.out.println(mySolution());
   }
}
