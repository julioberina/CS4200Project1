#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include <chrono>
#include "AStar.hpp"
using namespace std;

bool validatePuzzleInput(string puzzle);
bool isPuzzleSolvable(string puzzle);

int main()
{
  int choice = 0;
  string puzzle = "";
  unsigned seed; // case 1

  cout << "Welcome to the 8-Puzzle Program!" << endl << endl;
  cout << "Please choose from the options below:" << endl << endl;

  while (choice != 3)
  {
    cout << "1. Generate a random 8-puzzle" << endl;
    cout << "2. Input an 8-puzzle" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Enter input:  ";

    if (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(numeric_limits<int>::max(), '\n');
      cout << "Input must be an integer, ideally 1, 2, or 3" << endl << endl;
      continue;
    }

    // Clear input stream
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');

    if (choice == 1)
    {
      puzzle = "012345678";
      seed = chrono::system_clock::now().time_since_epoch().count();

      do {
        shuffle(puzzle.begin(), puzzle.end(), default_random_engine(seed));
      } while (!isPuzzleSolvable(puzzle));

      Board board(puzzle);
      AStar astar;
      astar.solveH1(board);
      cout << endl << "---------------------------------------------------------------" << endl << endl;
      astar.solveH2(board);
      cout << endl;
    }

    else if (choice == 2)
    {
      cout << "You want to input a puzzle" << endl << endl;

      do {
        cout << "Enter puzzle:  ";
        getline(cin, puzzle);
        puzzle.erase(remove_if(puzzle.begin(), puzzle.end(),
                              [](unsigned char x){return isspace(x);}),
                              puzzle.end()); // Get rid of whitespace
      } while (validatePuzzleInput(puzzle) == false);

      if (isPuzzleSolvable(puzzle))
      {
        Board board(puzzle);
        AStar astar;
        astar.solveH1(board);
        cout << endl << "---------------------------------------------------------------" << endl << endl;
        astar.solveH2(board);
        cout << endl;
      }
      else
        cout << "Cannot solve puzzle" << endl;
    }

    else if (choice == 4)
    {
      AStar astar;
      puzzle = "012345678";

      int numberOfCases = 0;
      int tempH1Depth = 0;
      int tempH1Cost = 0;
      int h1Depths[25];
      int h2Depths[25];
      unsigned long averageCostH1[25];
      unsigned long averageCostH2[25];

      for (int i = 0; i < 51; ++i)
        h1Depths[i] = h2Depths[i] = averageCostH1[i] = averageCostH2[i] = 0;

      while(numberOfCases < 2000)
      {
        seed = chrono::system_clock::now().time_since_epoch().count();

        do {
          shuffle(puzzle.begin(), puzzle.end(), default_random_engine(seed));
        } while (!isPuzzleSolvable(puzzle));

        Board board(puzzle);
        astar.solveH1(board);
        if (astar.getSolutionDepth() < 25)
        {
          tempH1Depth = astar.getSolutionDepth();
          tempH1Cost = astar.getSearchCost();
        }
        else
          continue;

        astar.solveH2(board);
        if (astar.getSolutionDepth() < 25)
        {
          h1Depths[tempH1Depth] += 1;
          averageCostH1[tempH1Depth] += tempH1Cost;
          h2Depths[astar.getSolutionDepth()] += 1;
          averageCostH2[astar.getSolutionDepth()] += astar.getSearchCost();
        }
        else
          continue;
      }

      cout << "d\tH1 cost\tH2 cost" << endl;
      for (int i = 0; i < 25; ++i)
      {
        if (h1Depths[i] == 0 && h2Depths[i] == 0)
          continue;

        cout << i << "\t";

        if (h1Depths[i] != 0)
          averageCostH1[i] = averageCostH1[i] / h1Depths[i];
        cout << averageCostH1[i] << "\t";

        if (h2Depths[i] != 0)
          averageCostH2[i] = averageCostH2[i] / h2Depths[i];
        cout << averageCostH2[i] << endl;
      }
    }

    else if (choice != 3)
      cout << "Invalid input!" << endl << endl;
  }

  return 0;
}

bool validatePuzzleInput(string puzzle)
{
  if (puzzle.size() != 9)
  {
    cout << "Puzzle must be of size 9!" << endl << endl;
    return false;
  }
  for (int i = 0; i < 9; ++i)
  {
    if (puzzle.find(to_string(i)) == string::npos)
    {
      cout << "Puzzle must contain unique values 0-9" << endl << endl;
      return false;
    }
  }

  cout << endl;
  return true;
}

bool isPuzzleSolvable(string puzzle)
{
  int inversions = 0;

  int inv_count = 0;
  for (int i = 0; i < 8; ++i)
  {
    for (int j = i + 1; j < 9; ++j)
      if (puzzle[j] != '0' && puzzle[i] != '0' && puzzle[i] > puzzle[j])  ++inversions;
  }

  return (inversions % 2 == 0);
}
