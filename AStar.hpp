# pragma once
#include <queue>
#include <cstddef>
#include <iostream>
#include "Board.hpp"
using namespace std;

class AStar
{
private:
  int globalDepth;

  struct compareH1
  {
    bool operator()(const Board& left, const Board& right)
    {
      return (left.hamming() + globalDepth) > (right.hamming() + globalDepth);
    }
  };

  struct compareH2
  {
    bool operator()(const Board& left, const Board& right)
    {
      return (left.manhattan() + globalDepth) > (right.manhattan() + globalDepth);
    }
  };

  int cost;
  Board initial;
  Board finish;
  bool search(priority_queue<Board, vector<Board>, compareH1>& pq);
  bool search(priority_queue<Board, vector<Board>, compareH2>& pq);
public:
  AStar(Board& init) : initial(init), finish(NULL) { initial = init; cost = 0; }
  void solveH1(); // Solve using Hamming
  void solveH2(); // Solve using Manhattan
};
