class Main
{
  //===========================================================================================
  //                                    MAIN
  //===========================================================================================

  public static void main(String[] args)
  {
    if (args.length == 2)
    {
      if (isValid(Integer.parseInt(args[1]), Integer.parseInt(args[1])))
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

  //===========================================================================================
  //                                    ISVALID
  //===========================================================================================

  public static boolean isValid(int row, int col)
  {
    if (row >= 0 && row < 8 && col >= 0 && col < 8)
    {
      return true;
    }

    return false;
  }

  //===========================================================================================
  //                                    KNIGHTS_TOUR
  //===========================================================================================

  public static void knights_tour(int row, int col)
  {
    int[][] board = new int[8][8];

    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        board[i][j] = -1;
      }
    }

    find_path(board, row, col, 1);
    print_board(board);
  }

  //===========================================================================================
  //                                    FIND_PATH
  //===========================================================================================

  public static void find_path(int[][] board, int row, int col, int position)
  {
    if (position > 64)
    {
      return;
    }

    boolean flag = false;

    board[row][col] = position;

    if (isValid(row + 2, col + 1) && board[row + 2][col + 1] == -1)
    {
      flag = true;
      find_path(board, row + 2, col + 1, position + 1);
    }

    if (isValid(row + 1, col + 2) && board[row + 1][col + 2] == -1)
    {
      flag = true;
      find_path(board, row + 1, col + 2, position + 1);
    }

    if (isValid(row - 1, col + 2) && board[row - 1][col + 2] == -1)
    {
      flag = true;
      find_path(board, row - 1, col + 2, position + 1);
    }

    if (isValid(row - 2, col + 1) && board[row - 2][col + 1] == -1)
    {
      flag = true;
      find_path(board, row - 2, col + 1, position + 1);
    }

    if (isValid(row - 2, col - 1) && board[row - 2][col - 1] == -1)
    {
      flag = true;
      find_path(board, row - 2, col - 1, position + 1);
    }

    if (isValid(row - 1, col - 2) && board[row - 1][col - 2] == -1)
    {
      flag = true;
      find_path(board, row - 1, col - 2, position + 1);
    }

    if (isValid(row + 1, col - 2) && board[row + 1][col - 2] == -1)
    {
      flag = true;
      find_path(board, row + 1, col - 2, position + 1);
    }

    if (isValid(row + 2, col - 1) && board[row + 2][col - 1] == -1)
    {
      flag = true;
      find_path(board, row + 2, col - 1, position + 1);
    }

    if (flag == false)
    {
      board[row][col] = -1;
    }
  }

  //===========================================================================================
  //                                    PRINT_BOARD
  //===========================================================================================

  public static void print_board(int [][] board)
  {
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        System.out.print(board[i][j] + "\t");
      }
      System.out.println("\n");
    }
  }
}