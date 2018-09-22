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
  Board prevState;
  string currentState;
public:
  Board(string initState) : prevState(NULL) { currentState = initState; }
  int hamming() const;
  int manhattan() const;
  string getState() const { return currentState; }
  vector<Board> successors();
};
