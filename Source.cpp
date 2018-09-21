#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool validatePuzzleInput(string puzzle);
bool isPuzzleSolvable(string puzzle);

int main()
{
  int choice = 0;
  string puzzle = "";

  cout << "Welcome to the 8-Puzzle Program!" << endl << endl;
  cout << "Please choose from the options below:" << endl << endl;

  cout << "1. Generate a random 8-puzzle" << endl;
  cout << "2. Input an 8-puzzle" << endl;
  cout << "3. Exit" << endl << endl;

  while (choice < 1 || choice > 3)
  {
    cout << "Enter input:  ";

    if (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(numeric_limits<int>::max(), '\n');
      cout << "Input must be an integer, ideally 1, 2, or 3" << endl << endl;
    }
    else if (choice < 1 || choice > 3)
      cout << "Input must be 1, 2, or 3" << endl << endl;
  }

  // Clear input stream
  cin.clear();
  cin.ignore(numeric_limits<int>::max(), '\n');

  switch (choice)
  {
    case 1:
      cout << "You chose to generate a puzzle" << endl << endl;
    break;

    case 2:
      cout << "You want to input a puzzle" << endl << endl;

      do {
        cout << "Enter puzzle:  ";
        getline(cin, puzzle);
        puzzle.erase(remove_if(puzzle.begin(), puzzle.end(),
                              [](unsigned char x){return isspace(x);}),
                              puzzle.end()); // Get rid of whitespace
      } while (validatePuzzleInput(puzzle) == false);

      if (isPuzzleSolvable(puzzle))
        cout << "Solvable" << endl;
      else
        cout << "Cannot solve puzzle" << endl;
    break;

    case 3:
    default:
      return 0;
    break;
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
