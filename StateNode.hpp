#ifndef STATE_NODE_HPP
#define STATE_NODE_HPP
#include <string>
using namespace std;

class StateNode
{
private:
  StateNode predecessor;
  int* initalState;
  int* currentState;
  int cost;
  string actionTaken;
  int emptyPosition;
  int fringeSize = 0;
  int exploredSize = 0;
  int searchCost = 0;

public:
  StateNode() : predecessor(nullptr)
  {
    initalState = new int[9];

    for (int i = 0; i < 9; ++i) { initialState[i] = -1; }

    currentState = initalState;
    cost = 0;
    actionTaken = "noop";
    emptyPosition = 0;
  }

  StateNode(int* initState, int* currState, int cost, string actionTaken, StateNode predecssor, int emptyPos)
  {
    initalState = initState;
    currentState = currState;
    this->cost = cost;
    this->actionTaken = actionTaken;
    this->predecessor = predecssor;
    emptyPosition = emptyPos;
  }

  void setFringeSize(int fSize) { fringeSize = fSize; }
  void setExploredSize(int eSize) { exploredSize = eSize; }
  void setSearchCost(int searchCost) { this->searchCost = searchCost; }
  int getSearchCost() { return searchCost; }
  StateNode getPredecessor() { return predecessor; }
  int* getInitialState() { return initalState; }
  int* getCurrentState() { return currentState; }
  int getCost() { return cost; }
  string getAction() { return actionTaken; }
  int getEmptyPosition() { return emptyPosition; }
  int getFringeSize() { return fringeSize; }
  int getExploredSize() { return exploredSize; }
};

#endif
