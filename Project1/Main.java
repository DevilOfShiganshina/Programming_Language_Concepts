class Main
{
  //===========================================================================================
  //                                    MAIN
  //===========================================================================================

  public static void main(String[] args)
  {
    knights_tour(0, 0);
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
    board[0][0] = 1;
    find_path(board, row, col, 2);
    print_board(board);
  }

  //===========================================================================================
  //                                    FIND_PATH
  //===========================================================================================

  public static boolean find_path(int[][] board, int row, int col, int position)
  {
    if (position > 64)
    {
      return true;
    }

    int moveSetRow[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int moveSetCol[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for (int i = 0; i < 8; i++)
    {
      if (isValid(row + moveSetRow[i], col + moveSetCol[i]) && board[row + moveSetRow[i]][col + moveSetCol[i]] == -1)
      {
        board[row + moveSetRow[i]][col + moveSetCol[i]] = position;
        if(find_path(board, row + moveSetRow[i], col + moveSetCol[i], position + 1) == true)
        {
          return true;
        }

        else
        {
          board[row + moveSetRow[i]][col + moveSetCol[i]] = -1;
        }
      }
    }

    return false;
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