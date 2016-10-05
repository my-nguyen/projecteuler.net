class test1 {
   static long gcd(long one, long two)
   {
     while (one != 0)
     {
       long tmp = one;
       one = two % one;
       two = tmp;
     }
     return two;
   }

   public static void main(String[] args) {
      int one = Integer.parseInt(args[0]);
      int two = Integer.parseInt(args[1]);
      System.out.println("gcd: " + gcd(one, two));
   }
}
