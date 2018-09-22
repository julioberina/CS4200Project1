#include "AStar.hpp"

void AStar::solveH1(Board& initial)
{
  globalDepth = 0;
  cost = 0;

  priority_queue<Board, vector<Board>, compareH1> pq;
  pq.push(initial);

  if (search(pq))
    cout << "H1 Done..." << endl;
}

void AStar::solveH2(Board& initial)
{
  globalDepth = 0;
  cost = 0;

  priority_queue<Board, vector<Board>, compareH2> pq;
  pq.push(initial);

  if (search(pq))
    cout << "H2 Done..." << endl;
}

// Search methods
bool AStar::search(priority_queue<Board, vector<Board>, compareH1>& pq)
{
  if (pq.empty()) return false;
  ++cost;

  Board puzzle = pq.top();
  globalDepth = puzzle.getDepth();
  cout << "d = " << puzzle.getDepth() << ", search cost = " << cost << endl;
  cout << puzzle << endl;
  pq.pop();

  if (puzzle.isGoal())
  {
    cout << "Puzzle solved!" << endl;
    return true;
  }

  for (Board& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq)) ? true : false;
}

bool AStar::search(priority_queue<Board, vector<Board>, compareH2>& pq)
{
  if (pq.empty()) return false;
  ++cost;

  Board puzzle = pq.top();
  globalDepth = puzzle.getDepth();
  cout << "d = " << puzzle.getDepth() << ", search cost = " << cost << endl;
  cout << puzzle << endl;
  pq.pop();

  if (puzzle.isGoal())
  {
    cout << "Puzzle solved!" << endl;
    return true;
  }

  for (Board& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq)) ? true : false;
}
