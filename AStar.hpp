#ifndef ASTAR_HPP
#define ASTAR_HPP
#include <queue>
#include "Board.hpp"
using namespace std;

static int globalDepth;

class AStar
{
private:
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
  bool search(priority_queue<Board, vector<Board>, compareH1>& pq);
  bool search(priority_queue<Board, vector<Board>, compareH2>& pq);
public:
  AStar() { cost = 0; globalDepth = 0; }
  void solveH1(Board& initial); // Solve using Hamming
  void solveH2(Board& initial); // Solve using Manhattan
};

#endif
