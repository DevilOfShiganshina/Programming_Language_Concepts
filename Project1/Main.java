class Main
{
  public static void knights_tour(int row, int col)
  {
    System.out.println("Row: " + row);
    System.out.println("Col: " + col);
  }
  public static void main(String[] args)
  {
    if (args.length > 0)
      knights_tour(Integer.parseInt(args[0]), Integer.parseInt(args[1]));

    else
      knights_tour(0, 0);
  }
}