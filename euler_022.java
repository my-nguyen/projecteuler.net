import java.io.*;
import java.util.*;

public class euler_022
{
  // this method opens a file, reads the only line in the file which contains
  // over 5,000 names, parse the names, store them in a list, then return the list
  static List<String> input() throws FileNotFoundException
  {
    // read from file. Luckily Scanner() can read a larger text file of 46447
    // characters!!
    Scanner scanner = new Scanner(new File("euler_022-names.txt"));
    // there's only one huge line (46447 characters) to read
    String line = scanner.nextLine();

    List<String> names = new ArrayList<>();
    // parse the line into strings (names) based on delimeter ",\""
    StringTokenizer tokenizer = new StringTokenizer(line, ",\"");
    while (tokenizer.hasMoreTokens())
    {
      String name = tokenizer.nextToken();
      // retain each name in a list
      names.add(name);
    }

    // sort the names alphabetically
    Collections.sort(names);
    scanner.close();

    return names;
  }

  // this method returns a list of scores of the corresponding names. each score
  // is calculated by taking the total of the alphabetical value of all letters
  // in a name before multiplying that total by the alphabetical position of
  // that name.
  static List<Integer> scores(List<String> names)
  {
    List<Integer> scores = new ArrayList<>();
    // go thru the name list
    for (int i = 0; i < names.size(); i++)
    {
      int sum = 0;
      for (char letter : names.get(i).toCharArray())
      {
        // sum of the alphabetical value of all letters of a name
        int value = letter - 'A' + 1;
        sum += value;
        // System.out.println("char: " + letter + ", value: " + value);
      }
      // System.out.println("total: " + sum + ", index: " + i);
      // multiply the sum with the alphabetical position of the name
      sum *= i + 1;

      // retain that product in a list
      scores.add(sum);
    }

    return scores;
  }

  // this method returns the sum of all integers in a list
  static int sum(List<Integer> list)
  {
    int sum = 0;
    for (int number : list)
      sum += number;
    return sum;
  }

  public static void main(String[] args) throws FileNotFoundException
  {
    List<String> names = input();
    // System.out.println("index of COLIN: " + names.indexOf("COLIN"));
    List<Integer> scores = scores(names);
    System.out.println("Total: " + sum(scores));
  }
}
