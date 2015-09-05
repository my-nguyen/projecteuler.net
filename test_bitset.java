import java.util.BitSet;

class test_bitset
{
  private static void print(BitSet bits)
  {
    for (int i = 0; i < bits.size(); i++)
      System.out.print(bits.get(i) ? "1" : "0");
    System.out.println();
  }
  public static void main(String[] args)
  {
    BitSet bits = new BitSet();
    print(bits);
    for (int i = 0; i < 16; i++)
      bits.set(i*4);
    bits.set(100);
    print(bits);
  }
}
