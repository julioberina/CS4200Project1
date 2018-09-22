#include "Board.hpp"

int Board::hamming() const
{
  int index = 1;
  int result = 0;

  for (int i = 0; i < 9; ++i)
  {
    if (currentState[i] == '0') continue;
    if (currentState[i] != goalState[index])  ++result;
    ++index;
  }

  return result;
}

int Board::manhattan() const
{
  int index = 1;
  int goalIndex = 0;
  int result = 0;

  for (int i = 0; i < 9; ++i)
  {
    if (currentState[i] == '0') continue;
    if (currentState[i] != goalState[index])
    {
      goalIndex = goalState.find(currentState[i]);
      result += abs((i/3) - (goalIndex/3)); // add abs value of row difference
      result += abs((i%3) - (goalIndex%3)); // add abs value of col difference
    }

    ++index
  }

  return result;
}

vector<Board> Board::successors()
{

}
