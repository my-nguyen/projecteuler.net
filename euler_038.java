import java.util.*;

public class euler_038
{
   // What is the largest 1 to 9 pandigital 9-digit number that can be formed as
   // the concatenated product of an integer with (1,2, ... , n) where n > 1?
   // http://www.mathblog.dk/project-euler-38-pandigital-multiplying-fixed-number/
   // we're looking for a fixed number, and the concatenation of the product
   // of the fixed number with 1,..n is a 1-9 9-digit pandigital
   // (1) since n is greater than 1, or at least 2, the fixed number must
   // contain at most 4 digits; otherwise with 5 digits, the concatenation of 2
   // such numbers would result in a 10-digit number, not a 1-9 pandigital
   // 9-digit number.
   // (2) the description gives 918273645 as an example of a 9-digit pandigital.
   // the target number must also start at 9, because the product of such a
   // fixed number and 1 will start with 9, and the concatenation will also
   // start with 9.
   // (3) the fixed number must not contain 2 digits; otherwise with n=3, the
   // concatenated number has 8 digits, and with n=4, the concatenation results
   // in 11 digits.
   // (4) similarly the fixed number must not contain 3 digits; otherwise with
   // n=2 we have 7 digits, and with n=3, we have 11 digits.
   // (5) so the fixed number must contain 4 digits
   // (6) with the first digit being 9 (see (2) above), the fixed number must
   // be within the range from 9123 to 9876, a total of 753 numbers
   // (7) the second digit of the fixed number must be at most 4; otherwise with
   // 5 or above, the multiplication with 2 would result in 19, and there would
   // be two 9's in the concatenation.
   // (8) the fixed number must not contain a 1; otherwise the concatenation
   // would contain two 1's (???)
   // (9) so the range now becomes 9234 to 9487
   static int concatenate(int first, int second) {
      // to accommodate length of 4
      int multiplier = 10000;
      // length can only be either 4 or 5
      int length = String.valueOf(second).length();
      if (length == 5)
         multiplier *= 10;
      return first*multiplier + second;
   }

   static boolean isPandigital(int number) {
      if (String.valueOf(number).length() != 9)
         return false;

      // all are initialized to false
      boolean[] array = new boolean[9];
      while (number > 0) {
         // extract the least significant digit
         int digit = number % 10;
         // the 9-digit pandigital contains digits from 1 to 9 only, not 0.
         if (digit == 0)
            return false;

         // mark the array
         array[digit-1] = true;
         number /= 10;
      }

      for (boolean digit : array) {
         // if the 9-element array is not filled, it's not a pandigital
         if (!digit)
            return false;
      }
      return true;
   }

   public static void main(String[] args) {
      int result = 0;
      for (int i = 9487; i >= 9234; i--) {
         result = concatenate(i, 2*i);
         // System.out.println("i: " + i + ", 2i: "  + 2*i + ", result: " + result);
         if (isPandigital(result)) {
            System.out.println(result);
            break;
         }
      }
   }
}
