import java.util.*; // Vector

class int_array
{
  int_array() {}

  public void push(int number) { _vector.add(number); }

  public void sort() { Collections.sort(_vector); }

  public int size() { return _vector.size(); }

  public int at(int index) { return _vector.get(index); }

  public int sum()
  {
    int sum = 0;
    for (int i = 0; i < _vector.size(); i++)
      sum += _vector.get(i);
    return sum;
  }

  public void print()
  {
    for (int i = 0; i < _vector.size(); i++)
    {
      System.out.print(" " + _vector.get(i));
      if ((i+1) % 10 == 0)
        System.out.println();
    }
    System.out.println();
  }

  private Vector<Integer> _vector = new Vector<Integer>();
};
