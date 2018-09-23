#ifndef ASTAR_HPP
#define ASTAR_HPP
#include <queue>
#include <unordered_map>
#include <stdexcept>
#include <unordered_set>
#include "Board.hpp"
using namespace std;

struct compareH1
{
  bool operator()(const Board& left, const Board& right)
  {
    return (left.hamming() + left.getDepth()) > (right.hamming() + right.getDepth());
  }
};

struct compareH2
{
  bool operator()(const Board& left, const Board& right)
  {
    return (left.manhattan() + left.getDepth()) > (right.manhattan() + right.getDepth());
  }
};

class AStar
{
private:
  int cost;
  unordered_set<string> visited;
  void search(priority_queue<Board, vector<Board>, compareH1>& pq, unordered_map<int, vector<Board>>& nodesAtDepth);
  void search(priority_queue<Board, vector<Board>, compareH2>& pq, unordered_map<int, vector<Board>>& nodesAtDepth);
public:
  AStar() : visited() { cost = 0; }
  void solveH1(Board& initial); // Solve using Hamming
  void solveH2(Board& initial); // Solve using Manhattan
};

#endif
