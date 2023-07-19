#include <iostream>
#include <unistd.h>
#include <chrono>
using namespace std;
int R_Num()
{
  return chrono::duration_cast<chrono::milliseconds>(
             chrono::system_clock::now().time_since_epoch())
             .count() %
         1000;
}
void Lowercase(string &a)
{
  for (int i = 0; i < int(a.size()); i++)
  {
    if (a[i] >= 'A' && a[i] <= 'Z')
    {
      a[i] = a[i] + 32;
    }
  }
}
int main()
{
  string computer = "Computer";
  string playerName;
  cout << endl;
  cout << "Enter your name." << endl;
  cin >> playerName;
  cout << endl;
  cout << "Hello " << playerName << ".Welcome to our game.The rule are simple" << endl;
  cout << "RULE No.1\nYou need to guess the number is [Odd or Even]." << endl;
  cout << endl;
  cout << endl;
  int playerScore = 0, computerScore = 0;
  cout << endl;

  int maxRounds = 5;
  for (int round = 1; round <= maxRounds; round++)
  {
    cout << "_________________________________________________________________________________________" << endl;
    cout << "Round " << round << "\t\t\t\t\t\t\t\t     " << playerName << " " << playerScore << "-" << computerScore << " " << computer << endl;
    cout << "The computer is thinking of a number.." << endl;
    ///sleep(1);
    cout << "The computer has decided a number, now make your guess:\n" << endl;

    string guess;
    /*
    do
    {
      cin >> guess;
      Lowercase(guess);
      bool isSpellingCorrect = (!guess.compare("even") || !guess.compare("odd"));
      if (!isSpellingCorrect)
      {
        cout << "Spelling error, please enter your guess again." << endl;
      }
    } while(!isSpellingCorrect);
    */
    for(int i=0;;){
      cin >> guess;
      Lowercase(guess);
      bool isSpellingCorrect = (!guess.compare("even") || !guess.compare("odd"));
      if (isSpellingCorrect)
      {
        break;
      }
      else cout << "\nSpelling error, please enter your guess again." << endl;
      i++;
    }

    if (guess.compare("even") == 0)
    {
      if (R_Num() % 2 == 0)
      {
        playerScore++;
        cout << "You are correct!!"
             << "1 Point added to your score." << endl;
      }
      else
      {
        computerScore++;
        cout << "You are wrong!!"
             << "1 Point added to Computer's score." << endl;
      }
    }
    else if (guess.compare("odd") == 0)
    {
      if (R_Num() % 2 == 1)
      {
        playerScore++;
        cout << "YOU are correct!!"
             << "1 Point added to your score." << endl;
      }
      else
      {
        computerScore++;
        cout << "YOU are wrong!!"
             << "1 Point added to Computer's score." << endl;
      }
    }

    cout << endl;
    if (playerScore == 3)
    {
      cout << playerName << " wins!"
           << "\t\t\t\t\t" << playerName << " " << playerScore << "-" << computerScore << " " << computer;
      cout << endl;
      break;
    }
    else if (computerScore == 3)
    {
      cout << "You lost! " << computer << " wins!"
           << "\t\t\t\t\t" << playerName << " " << playerScore << "-" << computerScore << " " << computer;
      cout << endl;
      break;
    }
    else
    {
      cout << "The number was: " << R_Num() << endl;
    }
    cout << endl;
  }
}