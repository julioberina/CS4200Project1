#include "AStar.hpp"

void AStar::solveH1()
{
  priority_queue<Board, vector<Board>, compareH1> pq;
  pq.push(initial);

  if (search(pq, 0))
    cout << "H1 Done..." << endl;
}

void AStar::solveH2()
{
  priority_queue<Board, vector<Board>, compareH2> pq;
  pq.push(initial);

  if (search(pq, 0))
    cout << "H2 Done..." << endl;
}

// Search methods
bool AStar::search(priority_queue<Board, vector<Board>, compareH1>& pq, int currentDepth)
{
  if (pq.empty()) return false;
  globalDepth = currentDepth;
  ++cost;
  cout << "d = " << currentDepth << ", search cost = " << cost << ", ";

  Board puzzle = pq.top();
  pq.pop();

  cout << puzzle << endl;

  if (puzzle.isGoal())
    return true;

  for (Board& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq, currentDepth + 1)) ? true : false;
}

bool AStar::search(priority_queue<Board, vector<Board>, compareH2>& pq, int currentDepth)
{
  if (pq.empty()) return false;
  globalDepth = currentDepth;
  ++cost;
  cout << "d = " << currentDepth << ", search cost = " << cost << ", ";

  Board puzzle = pq.top();
  pq.pop();

  cout << puzzle << endl;

  if (puzzle.isGoal())
    return true;

  for (Board& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq, currentDepth + 1)) ? true : false;
}
