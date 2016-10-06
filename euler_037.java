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

interface Callable {
   void call(Digits digits);
}

class ChopLeft implements Callable {
   public void call(Digits digits) {
      digits.chopLeft();
   }
}

class ChopRight implements Callable {
   public void call(Digits digits) {
      digits.chopRight();
   }
}

public class euler_037
{
   static final int MAX = 1000000;
   static Primes primes = new Primes(MAX);

   static boolean isPalindrome(Digits digits, Callable callable, Primes primes) {
      Digits clone = new Digits(digits);
      for (int j = 0; j < digits.size()-1; j++) {
         callable.call(clone);
         int number = clone.toInt();
         if (!primes.isPrime(number)) {
            return false;
         }
      }
      return true;
   }

   static int mySolution() {
      int sum = 0;
      for (int i = 11; i < MAX; i += 2) {
         if (primes.isPrime(i)) {
            Digits digits = new Digits(i);
            boolean isPalindrome = isPalindrome(digits, new ChopLeft(), primes);
            if (isPalindrome) {
               isPalindrome = isPalindrome(digits, new ChopRight(), primes);
            }

            if (isPalindrome) {
               System.out.println(i);
               sum += i;
            }
         }
      }
      return sum;
   }

   static int mathBlog1() {
      // the first prime to examine is 11, since 2, 3, 5, and 7 are not
      // considered as truncatable primes
      int i = 11;
      int result = 0;
      int count = 0;
      // there's a total of 11 primes that are both truncatable from left to
      // right and right to left.
      while (count < 11) {
         // right starts out with prime number 11
         int right = i;
         // left starts out with 0
         int left = 0;
         int multiplier = 1;
         boolean isPrime = true;
         while (right > 0 && isPrime) {
            // store the last digit of right as the first digit of left
            int lastDigit = right % 10;
            left += multiplier * lastDigit;
            // check if both left and right are prime numbers
            isPrime = primes.isPrime(left) && primes.isPrime(right);
            // remove last digit of right
            right /= 10;
            multiplier *= 10;
         }

         if (isPrime) {
            count++;
            result += i;
         }
         i++;
      }
      return result;
   }

   static int mathBlog2() {
      int result = 0;
      int count = 0;
      Deque<Integer> list = new ArrayDeque<>();
      // start with a small prime (3) and add digits to the beginning of it;
      // therefore each time the newly composed number is both a prime and is
      // truncatable from left to right
      list.add(3);
      list.add(7);
      // digits to append to the front of a prime that's truncatable from left
      // to right; 0, 4, 6 and 8 are eliminated because they will make the prime
      // not truncatable from right to left
      int[] appends = { 1, 2, 3, 5, 7, 9 };
      // there's a total of 11 primes that are both truncatable from left to
      // right and right to left.
      while (count < 11) {
         // start with a prime that's truncatable from left to right
         int candidate = (int)list.pop();
         if (primes.isPrime(candidate)) {
            boolean isPrime = true;
            int current = candidate;
            int multiplier = 1;

            // check if number is truncatable from right to left
            while (current > 0) {
               // check if truncated number is prime
               isPrime = primes.isPrime(current) && isPrime;
               // truncate from right
               current /= 10;
               multiplier *= 10;
            }

            // add to the result if a right-truncatable prime is found
            if (isPrime && candidate > 10) {
               result += candidate;
               count += 1;
            }

            // generate new primes
            for (int i = 0; i < appends.length; i++) {
               list.add(multiplier * appends[i] + candidate);
            }
         }
      }
      return result;
   }

   public static void main(String[] args) {
      System.out.println(mySolution());
      System.out.println(mathBlog1());
      System.out.println(mathBlog2());
   }
}
