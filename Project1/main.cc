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
#include <sstream> //
#include <string>

//===========================================================================================
//                                    PROTOTYPES
//===========================================================================================

/**
 * \brief Determines if row and column are within the
 *        bounds of the board
 * 
 * \param Two integer value, which represents the row
 *        and the column
 * 
 * \return A boolean value
 **/
bool isValid(int row, int col);

/**
 * \brief This function declares a two dimensional array
 *        and populate it with a single integer value,
 *        so it is easier to determine if a cell in the
 *        board has been visited or not. Then "find_path"
 *        function is called which finds a path. Lastly
 *        the board is printed to the console window by
 *        calling the "print_board" function.
 * 
 * \param Two integer values, which is either user specified
 *        or default row and column values.
 * 
 * \return Nothing
 **/
void knights_tour(int row, int col);

/**
 * \brief This function is called recursively to find a valid
 *        knights tour path.
 * 
 * \param Four integer values: first is the board itself, then
 *        the new row and column values, and lastly the position
 *        number which is placed in a cell to signify that cell
 *        is the N number of step in the path
 * 
 * \return Nothing
 *        
 **/ 
void find_path(int board[8][8], int row, int col, int position);

/**
 * \brief Prints the board to the console window
 * 
 * \param A two dimensional array which represents the chess
 *        board.
 * 
 * \return Nothing
 **/

void print_board(int board[8][8]);

//===========================================================================================
//                                    MAIN
//===========================================================================================

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

//===========================================================================================
//                                    ISVALID
//===========================================================================================

bool isValid(int row, int col)
{
  if (row < 0 || row > 8 || col < 0 || row > 8)
  {
    return false;
  }

  return true;
}

//===========================================================================================
//                                    KNIGHTS_TOUR
//===========================================================================================

void knights_tour(int row, int col)
{
  int board[8][8];

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

void find_path(int board[8][8], int row, int col, int position)
{
  if (position > 64) {
    return;
  }

  board[row][col] = position;

  if (isValid(row - 2, col -1) && board[row - 2][col - 1] != -1)
  {
    find_path(board, row - 2, col - 1, position + 1);
  }

  else if (isValid(row - 1, col - 2) && board[row - 1][col - 2] != -1)
  {
    find_path(board, row - 1, col - 2, position + 1);
  }

  else if (isValid(row + 1, col - 2) && board[row + 1][col - 2] != -1)
  {
    find_path(board, row + 1, col - 2, position + 1);
  }

  else if (isValid(row + 2, col - 1) && board[row + 2][col - 1] != -1)
  {
    find_path(board, row + 2, col - 1, position + 1);
  }

  else if (isValid(row + 2, col + 1) && board[row + 2][col + 1] != -1)
  {
    find_path(board, row + 2, col + 1, position + 1);
  }

  else if (isValid(row + 1, col + 2) && board[row + 1][col + 2] != -1)
  {
    find_path(board, row + 1, col + 2, position + 1);
  }

  else if (isValid(row - 1, col + 2) && board[row - 1][col + 2] != -1)
  {
    find_path(board, row - 1, col + 2, position + 1);
  }

  else if (isValid(row - 2, col + 1) && board[row - 2][col + 1] != -1)
  {
    find_path(board, row - 2, col + 1, position + 1);
  }

  else
  {
    board[row][col] = 0;
  }
}

//===========================================================================================
//                                    PRINT_BOARD
//===========================================================================================

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
}