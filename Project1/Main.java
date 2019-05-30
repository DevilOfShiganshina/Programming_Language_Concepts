class Main
{
  public static boolean check_input(int row, int col)
  {
    if (row >= 0 && row < 8 && col >= 0 && col < 8)
    {
      return true;
    }

    return false;
  }

  public static void knights_tour(int row, int col)
  {
    System.out.println("Row: " + row);
    System.out.println("Col: " + col);
  }
  public static void main(String[] args)
  {
    if (args.length > 0 && check_input(Integer.parseInt(args[0]), Integer.parseInt(args[1])))
    {
      if (args.length == 1)
      {
        knights_tour(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
      }

      else 
      {
        knights_tour(0, 0);
      }
    }

    else
    {
      knights_tour(0, 0);
    }
  }
}