#include <iostream>

void knights_tour(int row, int col)
{
  std::cout << row << " " << col << std::endl;
}

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    knights_tour(std::stoi(argv[1]), std::stoi(argv[2]));
  }

  else
  {
    knights_tour(0, 0);
  }
  return 0;
}