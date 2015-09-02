import java.util.*; // Vector

class int_array
{
  int_array() {}

  public void push(int number) { _list.add(number); }

  public void sort() { Collections.sort(_list); }

  public int size() { return _list.size(); }

  public int at(int index) { return _list.get(index); }

  public int sum()
  {
    int sum = 0;
    for (int element : _list)
      sum += element;
    return sum;
  }

  public void print()
  {
    for (int i = 0; i < _list.size(); i++)
    {
      System.out.print(" " + _list.get(i));
      if ((i+1) % 10 == 0)
        System.out.println();
    }
    System.out.println();
  }

  // Vector is deprecated.
  private List<Integer> _list = new ArrayList<Integer>();
};
