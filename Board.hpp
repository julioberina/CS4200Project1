# pragma once
#include <string>
#include <cstddef>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Board
{
private:
  enum { UP, DOWN, LEFT, RIGHT };
  const static string goalState = "012345678";
  Board prevBoard;
  string currentState;

  // Helper functions
  bool isValidMove(int direction);
  string makeMove(string& tempstr, int src, int dest);
public:
  Board(string initState) : prevBoard(NULL) { currentState = initState; }
  int hamming() const;
  int manhattan() const;
  string getState() const { return currentState; }
  vector<Board> successors();
  void setPredecessor(const Board& board) { prevBoard = board; }
  const Board& predecessor() { return prevBoard; }
  bool isGoal() { return currentState == goalState; }
  // friend ostream& operator<<(ostream& outs, const Board& other);
};

ostream& operator<<(ostream& outs, const Board& board)
{
  for (int i = 0; i < 9; ++i)
  {
    if (i % 3 == 2)
      outs << board.getState()[i];
    else
      outs << board.getState()[i] << " ";
  }

  return outs;
}
