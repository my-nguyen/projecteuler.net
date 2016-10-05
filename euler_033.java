import java.util.*;

class Pair {
   int one;
   int two;

   Pair(int one, int two) {
      this.one = one;
      this.two = two;
   }

   public String toString() {
      return one + "/" + two;
   }
}

public class euler_033 {
   static List<Pair> findNonTrivials() {
      List<Pair> result = new ArrayList<>();
      // search all 2-digit numerators and 2-digit denominators where the
      // numerator is smaller than the denominator
      for (int numerator = 10; numerator < 99; numerator++) {
         for (int denominator = numerator+1; denominator < 100; denominator++) {
            if (numerator % 10 != 0 || denominator % 10 != 0) {
               int numerTens = numerator / 10;
               int numerDigits = numerator % 10;
               int denomTens = denominator / 10;
               int denomDigits = denominator % 10;

               if (numerTens == denomTens || numerTens == denomDigits || numerDigits == denomTens || numerDigits == denomDigits) {
                  float ratio = (float)numerator / denominator;
                  Pair pair = new Pair(numerator, denominator);
                  if (numerTens == denomTens) {
                     if ((float)numerDigits / denomDigits == ratio) {
                        result.add(pair);
                     }
                  } else if (numerTens == denomDigits) {
                     if ((float)numerDigits / denomTens == ratio) {
                        result.add(pair);
                     }
                  } else if (numerDigits == denomTens) {
                     if ((float)numerTens / denomDigits == ratio) {
                        result.add(pair);
                     }
                  } else {
                     if ((float)numerTens / denomTens == ratio) {
                        result.add(pair);
                     }
                  }
               }
            }
         }
      }
      for (Pair pair : result) {
         ; // System.out.println(pair);
      }
      return result;
   }

   static int gcd(int one, int two)
   {
     while (one != 0)
     {
       int tmp = one;
       one = two % one;
       two = tmp;
     }
     return two;
   }

   static int lowestDenominator(int numerator, int denominator) {
      // find the greatest common divisor of the numerator-product and the
      // denominator-product; this is to reduce the product of the 4 fractions
      // in its lowest common terms
      int divisor = gcd(numerator, denominator);
      // the end result is the division of the denominator-product by the
      // greatest common divisor
      int result = denominator / divisor;
      // System.out.println("numerator: " + numerator + ", denominator: " + denominator + ", divisor: " + divisor + ", result: " + result);
      return result;
   }

   static int mySolution() {
      // first find the list of all non-trivial numbers between 10 and 99
      // there's 4 such numbers according to the problem description
      List<Pair> nonTrivials = findNonTrivials();

      // take the product of all numerators and all denominators
      int numerator = 1, denominator = 1;
      for (Pair nonTrivial : nonTrivials) {
         numerator *= nonTrivial.one;
         denominator *= nonTrivial.two;
         // System.out.println("non-trivial: " + nonTrivial + ", numerator: " + numerator + ", denominator: " + denominator);
      }

      return lowestDenominator(numerator, denominator);
   }

   // http://www.mathblog.dk/project-euler-33-fractions-unorthodox-cancelling-method/
   static int mathblogSolution() {
      int denproduct = 1;
      int numproduct = 1;
      for (int i = 1; i < 10; i++) {
         for (int den = 1; den < i; den++) {
            for (int num = 1; num < den; num++) {
               if ((num * 10 + i) * den == num * (i * 10 + den)) {
                  denproduct *= den;
                  numproduct *= num;
               }
            }
         }
      }
      return lowestDenominator(numproduct, denproduct);
   }

   public static void main(String[] args) {
      System.out.println(mySolution());
      System.out.println(mathblogSolution());
   }
}
