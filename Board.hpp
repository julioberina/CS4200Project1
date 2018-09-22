#ifndef BOARD_HPP
#define BOARD_HPP
#include <string>
#include <cstddef>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

const string goalState = "012345678";

class Board
{
private:
  string prevState;
  string currentState;

  // Helper functions
  bool isValidMove(int direction, int& index);
  string makeMove(string& tempstr, int src, int dest);
public:
  Board(string initState) : prevState("") { currentState = initState; }
  int hamming() const;
  int manhattan() const;
  string getState() const { return currentState; }
  vector<Board> successors();
  void setPredecessor(string& pre) { prevState = pre; }
  string predecessor() { return prevState; }
  bool isGoal() const { return currentState == goalState; }
  friend ostream& operator<<(ostream& outs, const Board& other);
};

#endif
