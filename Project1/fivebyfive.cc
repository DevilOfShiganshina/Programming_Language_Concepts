#include <iostream> // Input / Output
#include <sstream>  // Stringstream, for converting command line arguments to integers

bool isValid(int row, int col);

void knights_tour(int row, int col);

int find_path(int board[5][5], int row, int col, int position);

void print_board(int board[5][5]);

int main(int argc, char **argv)
{
  if (argc == 3)
  {
    std::stringstream ss;
    ss << argv[1];
    int row, col;
    ss >> row;
    ss.clear();
    ss << argv[2];
    ss >> col;
    if (isValid(row, col))
    {
      knights_tour(row, col);
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
  return 0;
}

bool isValid(int row, int col)
{
  if (row >= 0 && row < 5 && col >= 0 && col < 5)
  {
    return true;
  }
  return false;
}

void knights_tour(int row, int col)
{
  int board[5][5];
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      board[i][j] = -1;
    }
  }
  board[0][0] = 1;
  find_path(board, row, col, 2);
  print_board(board);
}

int find_path(int board[5][5], int row, int col, int position)
{
  if (position > 25)
  {
    return true;
  }

  int moveSetRow[] = {2, 1, -1, -2, -2, -1, 1, 2};
  int moveSetCol[] = {1, 2, 2, 1, -1, -2, -2, -1};
  for (int i = 0; i < 8; i++)
  {
    if (isValid(row + moveSetRow[i], col + moveSetCol[i]) && board[row + moveSetRow[i]][col + moveSetCol[i]] == -1)
    {
      board[row][col] = position;
      if (find_path(board, row + moveSetRow[i], col + moveSetCol[i], position + 1) == true)
      {
        return true;
      }
    }
  }

  board[row][col] = -1;
  return false;
}

void print_board(int board[5][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      std::cout << board[i][j] << "\t";
    }
    std::cout << std::endl
              << std::endl;
  }
}