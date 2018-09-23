#include "AStar.hpp"

void AStar::solveH1(Board& initial)
{
  globalDepth = 0;
  cost = 0;

  priority_queue<Board, vector<Board>, compareH1> pq;
  unordered_map<int, vector<Board>> states;
  pq.push(initial);

  if (search(pq, states))
    cout << "H1 Done..." << endl;
}

void AStar::solveH2(Board& initial)
{
  globalDepth = 0;
  cost = 0;

  priority_queue<Board, vector<Board>, compareH2> pq;
  unordered_map<int, vector<Board>> states;
  pq.push(initial);

  if (search(pq, states))
    cout << "H2 Done..." << endl;
}

// Search methods
bool AStar::search(priority_queue<Board, vector<Board>, compareH1>& pq, unordered_map<int, vector<Board>>& um)
{
  if (pq.empty()) return false;
  ++cost;

  Board puzzle = pq.top();
  globalDepth = puzzle.getDepth();
  pq.pop();

  try {
    um[puzzle.getDepth()].push_back(puzzle);
  }
  catch (const out_of_range& oor) {
    vector<Board> vb;
    vb.push_back(puzzle);
    um[puzzle.getDepth()] = vb;
  }
  // cout << "d = " << puzzle.getDepth() << ", search cost = " << cost << endl;
  // cout << puzzle << endl;

  if (puzzle.isGoal())
  {
    cout << "Puzzle solved!" << endl;
    return true;
  }

  for (Board& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq, um)) ? true : false;
}

bool AStar::search(priority_queue<Board, vector<Board>, compareH2>& pq, unordered_map<int, vector<Board>>& um)
{
  if (pq.empty()) return false;
  ++cost;

  Board puzzle = pq.top();
  globalDepth = puzzle.getDepth();
  pq.pop();

  try {
    um[puzzle.getDepth()].push_back(puzzle);
  }
  catch (const out_of_range& oor) {
    vector<Board> vb;
    vb.push_back(puzzle);
    um[puzzle.getDepth()] = vb;
  }
  // cout << "d = " << puzzle.getDepth() << ", search cost = " << cost << endl;
  // cout << puzzle << endl;

  if (puzzle.isGoal())
  {
    cout << "Puzzle solved!" << endl;
    return true;
  }

  for (Board& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq, um)) ? true : false;
}
