#include "AStar.hpp"

void AStar::solveH1(Board& initial)
{
  globalDepth = 0;
  cost = 0;

  priority_queue<Board, vector<Board>, compareH1> pq;
  unordered_map<int, vector<Board>> states;
  pq.push(initial);

  if (search(pq, states))
    cout << "search cost = " << cost << endl;
}

void AStar::solveH2(Board& initial)
{
  globalDepth = 0;
  cost = 0;

  priority_queue<Board, vector<Board>, compareH2> pq;
  unordered_map<int, vector<Board>> states;
  pq.push(initial);

  if (search(pq, states))
    cout << "search cost = " << cost << endl;
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

  if (puzzle.isGoal())
  {
    string current = puzzle.getState();

    // Loop for backtracking
    for (int d = puzzle.getDepth(); d >= 0; --d)
    {
      for (Board& board: um[d])
      {
        if (board.getState() == current && board.predecessor() != "")
        {
          cout << current << " ===> " << endl;
          current = board.predecessor();
        }
        else if (board.predecessor() == "")
          cout << current << endl << endl;
      }
    }

    cout << "d = " << puzzle.getDepth() << ", ";
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
  if (puzzle.isGoal())
  {
    string current = puzzle.getState();

    // Loop for backtracking
    for (int d = puzzle.getDepth(); d >= 0; --d)
    {
      for (Board& board: um[d])
      {
        if (board.getState() == current && board.predecessor() != "")
        {
          cout << current << " ===> " << endl;
          current = board.predecessor();
        }
        else if (board.predecessor() == "")
          cout << current << endl << endl;
      }
    }

    cout << "d = " << puzzle.getDepth() << ", ";
    return true;
  }

  for (Board& succ: puzzle.successors())
    pq.push(succ);

  return (search(pq, um)) ? true : false;
}
