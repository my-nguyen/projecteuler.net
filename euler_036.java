import java.util.*;

public class euler_036
{
   static final int MAX = 1000000;

   static String reverse(String number)
   {
      StringBuilder builder = new StringBuilder(number);
      return builder.reverse().toString();
   }

   static boolean isPalindrome(String number)
   {
      return number.equals(reverse(number));
   }

   static int mySolution() {
      int sum = 0;
      // there can be no leading zeroes, so in binary there can be no trailing
      // zeroes either, which means even numbers are eliminated
      for (int i = 1; i < MAX; i += 2) {
         String decimal = Integer.toString(i);
         if (isPalindrome(decimal)) {
            String binary = Integer.toBinaryString(i);
            if (isPalindrome(binary)) {
               System.out.println(decimal + " " + binary);
               sum += i;
            }
         }
      }
      return sum;
   }

   static boolean isPalindrome(int number, int base) {
      int reversed = 0;
      int current = number;
      while (current > 0) {
         int digit = current % base;
         reversed = base*reversed + digit;
         current /= base;
      }
      return number == reversed;
   }

   static int mathBlog1() {
      int sum = 0;
      for (int i = 1; i < MAX; i += 2) {
         if (isPalindrome(i, 10) && isPalindrome(i, 2)) {
            sum += i;
         }
      }
      return sum;
   }

   static int makePalindrome(int number, int base, boolean isOdd) {
      int current = number;
      int palindrome = number;
      // if the resulting palindrome must have an odd number of digits, then
      // chop off one digit in the reversed part of the palindrome
      if (isOdd)
         current /= base;

      // reverse the parameter number and append the reverse to the number
      while (current > 0) {
         palindrome = palindrome*base + current%base;
         current /= base;
      }

      return palindrome;
   }

   static int mathBlog2() {
      int sum = 0;
      int number;
      for (int j = 0; j < 2; j++) {
         boolean isOdd = (j % 2 == 0);
         int i = 1;
         while ((number = makePalindrome(i, 10, isOdd)) < MAX) {
            if (isPalindrome(number, 2)) {
               sum += number;
            }
            i += 1;
         }
      }
      return sum;
   }

   public static void main(String[] args) {
      System.out.println(mySolution());
      System.out.println(mathBlog1());
      System.out.println(mathBlog2());
   }
}
