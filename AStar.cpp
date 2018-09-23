#include "AStar.hpp"

void AStar::solveH1(Board& initial)
{
  cost = 0;

  priority_queue<Board, vector<Board>, compareH1> pq;
  unordered_map<int, vector<Board>> states;
  pq.push(initial);

  search(pq, states);
  cout << "H1 (Hamming) search cost = " << cost << endl;
}

void AStar::solveH2(Board& initial)
{
  cost = 0;

  priority_queue<Board, vector<Board>, compareH2> pq;
  unordered_map<int, vector<Board>> states;
  pq.push(initial);

  search(pq, states);
  cout << "H2 (Manhattan) search cost = " << cost << endl;
}

// Search methods
void AStar::search(priority_queue<Board, vector<Board>, compareH1>& pq, unordered_map<int, vector<Board>>& nodesAtDepth)
{
  Board puzzle = pq.top();

  while (!puzzle.isGoal())
  {
    if (pq.empty()) return;
    ++cost;

    puzzle = pq.top();
    pq.pop();

    try {
      nodesAtDepth[puzzle.getDepth()].push_back(puzzle);
    }
    catch (const out_of_range& oor) {
      vector<Board> vb;
      vb.push_back(puzzle);
      nodesAtDepth[puzzle.getDepth()] = vb;
    }

    for (Board& succ: puzzle.successors())
    {
      if (visited.find(succ.getState()) == visited.end()) // if not visited
        pq.push(succ);
    }

    visited.insert(puzzle.getState());
  }

  // Once puzzle is solved
  visited.clear();
  string optimalPath = puzzle.getState();
  string current = puzzle.getState();

  // Loop for backtracking
  for (int d = puzzle.getDepth(); d >= 0; --d)
  {
    for (Board& board: nodesAtDepth[d])
    {
      if (board.getState() == current && board.predecessor() != "")
      {
        optimalPath = board.predecessor() + " ===> \n" + optimalPath;
        current = board.predecessor();
      }
    }
  }

  cout << optimalPath << endl << endl;
  cout << "d = " << puzzle.getDepth() << ", ";
}

void AStar::search(priority_queue<Board, vector<Board>, compareH2>& pq, unordered_map<int, vector<Board>>& nodesAtDepth)
{
  Board puzzle = pq.top();

  while (!puzzle.isGoal())
  {
    if (pq.empty()) return;
    ++cost;

    puzzle = pq.top();
    pq.pop();

    try {
      nodesAtDepth[puzzle.getDepth()].push_back(puzzle);
    }
    catch (const out_of_range& oor) {
      vector<Board> vb;
      vb.push_back(puzzle);
      nodesAtDepth[puzzle.getDepth()] = vb;
    }

    for (Board& succ: puzzle.successors())
    {
      if (visited.find(succ.getState()) == visited.end()) // if not visited
        pq.push(succ);
    }

    visited.insert(puzzle.getState());
  }

  // Once puzzle is solved
  visited.clear();
  string optimalPath = puzzle.getState();
  string current = puzzle.getState();

  // Loop for backtracking
  for (int d = puzzle.getDepth(); d >= 0; --d)
  {
    for (Board& board: nodesAtDepth[d])
    {
      if (board.getState() == current && board.predecessor() != "")
      {
        optimalPath = board.predecessor() + " ===> \n" + optimalPath;
        current = board.predecessor();
      }
    }
  }

  cout << optimalPath << endl << endl;
  cout << "d = " << puzzle.getDepth() << ", ";
}
