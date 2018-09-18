#include <iostream>
#include <limits>
using namespace std;

int main()
{
  int choice = 0;

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

  switch (choice)
  {
    case 1:
      cout << "You chose to generate a puzzle" << endl;
    break;

    case 2:
      cout << "You want to input a puzzle" << endl;
    break;

    case 3:
    default:
    break;
  }

  return 0;
}
