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

    ++index;
  }

  return result;
}

vector<Board> Board::successors()
{
  int currentZeroIndex = currentState.find('0');
  int zeroIndex = 0;
  vector<Board> children;

  for (int i = 0; i < 4; ++i) // go in all directions
  {
    string tempState(currentState);

    if (isValidMove(i, zeroIndex) && makeMove(tempState, currentZeroIndex, zeroIndex) != prevState)
    {
      Board board(tempState);
      board.setPredecessor(currentState);
      board.setDepth(depth + 1);
      children.push_back(board);
    }
  }

  return children;
}

// Helper function implementations
bool Board::isValidMove(int direction, int& ind)
{
  int zeroIndex = currentState.find('0');

  switch (direction)
  {
    case 0:
    if (zeroIndex / 3 - 1 >= 0)
    {
      ind = zeroIndex - 3;
      return true;
    }
    break;

    case 1:
    if (zeroIndex / 3 + 1 < 3)
    {
      ind = zeroIndex + 3;
      return true;
    }
    break;

    case 2:
    if (zeroIndex % 3 - 1 >= 0)
    {
      ind = zeroIndex - 1;
      return true;
    }
    break;

    case 3:
    if (zeroIndex % 3 + 1 < 3)
    {
      ind = zeroIndex + 1;
      return true;
    }
    break;
  }

  return false;
}

string Board::makeMove(string& tempstr, int src, int dest)
{
  char temp = tempstr[src];
  tempstr[src] = tempstr[dest];
  tempstr[dest] = temp;
  return tempstr;
}

ostream& operator<<(ostream& outs, const Board& board)
{
  for (int i = 0; i < 9; ++i)
  {
    if (i % 3 == 2)
      outs << board.getState()[i] << endl;
    else
      outs << board.getState()[i] << " ";
  }

  return outs;
}
