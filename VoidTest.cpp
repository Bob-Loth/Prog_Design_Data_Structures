// Programmer: Bob Loth
// Programmer's ID: 1684749
#include <iostream>
#include <string>
using namespace std;

void MakePartialLongWord(int wordLength); //prints the first WordLength characters of LongWord, could be used in a guessing game
int main()
{
  // programmer's identification
  cout << "Programmer: Bob Loth\n";
  cout << "Programmer's ID: 1684749\n";
  cout << "File: " << __FILE__ << endl;

  MakePartialLongWord(9);
  cin.ignore();
}

void MakePartialLongWord(int wordLength) 
{
  string LongWord = "supercalifragilisticexpialidocious";
  if (wordLength > LongWord.length()) 
  {
    wordLength = LongWord.length();
  }
  for (int i = 0; i < wordLength; i++)
  {
    cout << LongWord[i];
  }
}