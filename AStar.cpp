#include "AStar.hpp"

void AStar::solveH1()
{
  priority_queue<Board, vector<Board>, compareH1> pq;
  pq.add(initial);

  if (search(pq, 0))
    cout << "H1 Done..." << endl;
}

void AStar::solveH2()
{
  priority_queue<Board, vector<Board>, compareH2> pq;
  pq.add(initial);

  if (search(pq, 0))
    cout << "H2 Done..." << endl;
}

// Search methods
bool search(priority_queue<Board, vector<Board>, compareH1>& pq, int currentDepth)
{
  if (pq.empty()) return false;
  globalDepth = currentDepth;
  ++cost;
  cout << "d = " << currentDepth << ", search cost = " << cost << ", ";

  auto& puzzle = pq.top();
  pq.pop();

  cout << puzzle << endl;

  if (puzzle.isGoal())
    return true;

  for (auto& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq)) ? true : false;
}

bool search(priority_queue<Board, vector<Board>, compareH2>& pq, int currentDepth)
{
  if (pq.empty()) return false;
  globalDepth = currentDepth;
  ++cost;
  cout << "d = " << currentDepth << ", search cost = " << cost << ", ";

  auto& puzzle = pq.top();
  pq.pop();

  cout << puzzle << endl;

  if (puzzle.isGoal())
    return true;

  for (auto& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq)) ? true : false;
}
