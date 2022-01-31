#include <iostream>
#include <string> 
#include <vector> 
#include <fstream> 
#include <filesystem>

using namespace std; 

char Rot13(char character); // Converting passed variable to its allocated character
void WriteToFile(char character, ofstream &outputFile); // Ouputs new character text to outputFile in folder

int main(){
  ifstream inputFile; 
  ofstream outputFile;
  inputFile.open("readFrom.txt");
  outputFile.open("“output.rot13"); 

  bool fileFound; 
  string command, fileName; 
  char charHolder, space;
  int counter = 0; 
  space = ' '; 

  while(fileFound == false)
    cout << "Enter the name of file: "; 
    cin >> fileName;
    ifstream my_file("file.txt");
    if (my_file.good())
      cout << "found"; 
{
  // read away
}

    // exists(fileName) ? fileFound = true: fileFound = false; 


  while(command != "QUIT"){
    vector<char> wordSplit(command.begin(), command.end());
    for(int num = 0; num < wordSplit.size(); num++)
      {
        charHolder = Rot13(wordSplit[num]);
        if(num != wordSplit.size())
          WriteToFile(charHolder, outputFile);
      }

    if(counter != 0) // Used to remove white space at the start of sentence
      outputFile << space; 
    inputFile >> command;
    counter++; 
  }

  return 0; 
}

char Rot13(char character){
  vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 
  int number, totalChar; 
  totalChar = chars.size(); 

  for(int x = 0; x < totalChar; x++)
  {
    if(character == chars[x]) // Finds the value number of the character in terms of sequential alphabetical order. Once found 13 is added to it.
    {
      number = x + 13;
      if(number >= totalChar) // Subtracts if total value of number is greater than the total number of characters in the alphabet. 
        number = number - totalChar; 
    }
  }
  
  for(int y = 0; y < totalChar; y++)
  {
    if(number == y)
      return chars[y]; // Returns new character
  }
}

void WriteToFile(char character, ofstream &outputFile){
  outputFile << character; 
}