/**
 * Assignment: Write a program that gives a solution
 *             to the Knight's Tour problem recursively
 * 
 * Author:      Tanjid A Shuhag (Tas)
 * Course:      Programming Language Concepts
 * Instructor:  Dr. Kapleau
 * Due Date:    June 5th, 2019
 **/

#include <iostream>
#include <sstream>
#include <string>

int count = 0;

/**
 * \brief Determines 
 **/
bool isValid(int row, int col);

void knights_tour(int row, int col);

void find_path(int board[8][8], int row, int col, int position);

void print_board(int board[8][8]);

int main(int argc, char **argv)
{
  if (argc > 1) 
  {
    if (argc == 2)
    {
      std::cout << "Need 2 command line arguments!\nProgram terminated!" << std::endl;
      return 0;
    }

    std::stringstream ss;
    ss << argv[1];
    int row, col;
    ss >> row;
    ss.clear();
    ss << argv[2];
    ss >> col;

    if (row >= 0 && row < 8 && col >= 0 && col < 8)
    {
      knights_tour(row, col);
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
  if (row < 0 || row >= 8 || col < 0 || row >= 8)
  {
    return false;
  }

  return true;
}

void knights_tour(int row, int col)
{
  int board[8][8];

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      board[i][j] = 0;
    }
  }

  find_path(board, row, col, 1);
  print_board(board);
}

void find_path(int board[8][8], int row, int col, int position)
{
  count++;
  board[row][col] = position;

  if (position >= 64) { return; }

  int moveRow[] = { 2, 1, -1, -2, -2, -1, 1, 2 , 2 };
  int moveCol[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1 };

  for (int i = 0; i < 8; i++)
  {
    int newRow = row + moveRow[i];
    int newCol = col + moveCol[i];

    if (isValid(newRow, newCol) && !board[newRow][newCol])
    {
      find_path(board, newRow, newCol, position + 1);
    }
  }

  board[col][row] = 0;
}

void print_board(int board[8][8])
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      std::cout << board[i][j] << "\t";
    }
    std::cout << std::endl << std::endl;
  }

  std::cout << count << std::endl;
}