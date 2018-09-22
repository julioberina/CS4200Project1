# pragma once
#include <string>
#include <cstddef>
#include <vector>
#include <cmath>
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
};
