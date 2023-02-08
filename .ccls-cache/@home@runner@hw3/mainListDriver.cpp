// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "unsorted.h"

using namespace std;


//void PrintList(ofstream& outFile, UnsortedListClass& list);
// silly mistake I kept on re-using the PrintList twice with different prototypes one as an enum and the other as the function all the way at the bottom
// fixed this by just re-naming the the PrintList to PrintListNew

enum Command {
    PutItem,
    DeleteItem,
    GetItem,
    GetLength,
    IsFull,
    MakeEmpty,
    PrintListNew,
    Quit
};

void PrintList(ofstream& outFile, UnsortedListClass& list);
Command ReadCommand(ifstream& inFile, int& item);

Command MapCommand(const std::string &command) {
    if (command == "PutItem") return PutItem;
    if (command == "DeleteItem") return DeleteItem;
    if (command == "GetItem") return GetItem;
    if (command == "GetLength") return GetLength;
    if (command == "IsFull") return IsFull;
    if (command == "MakeEmpty") return MakeEmpty;
    if (command == "PrintList") return PrintListNew;
    if (command == "Quit") return Quit;

    return Quit;
}


int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName, outFileName, outputLabel, command; 
  // input file external name
  //string outFileName;    // output file external name
  //string outputLabel;     
  //string command;        // operation to be executed
  
  int number;
  ItemType item;
  UnsortedListClass list;
  bool found;
  int numCommands = 0;


  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file and press return: " << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file and press return: " << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run and press return: " << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;
  if (!inFile)
  {
    cout << "file not found" << endl;
	exit(2);
  }
  inFile >> command;




  

  //numCommands = 0;
  while (command != "Quit")
  {
    switch (MapCommand(command)) 
    {
      case PutItem:
        inFile >> number; 
        item.Initialize(number);
        list.PutItem(item);
        item.Print(outFile);
        outFile << " is in list" << endl;
        break;
      case DeleteItem:
        inFile >> number;
        item.Initialize(number);
        list.DeleteItem(item);
        item.Print(outFile);
        outFile << " is deleted" << endl;
        break;
      case GetItem:
        inFile >> number;
        item.Initialize(number);
        item = list.GetItem(item, found);
        item.Print(outFile);
        if (found)
          outFile << " found in list." << endl;
        else outFile <<  " not in list."  << endl;  
        break;
      case GetLength:
        outFile << "Length is " << list.GetLength() << endl;
        break;
      case IsFull:
        if (list.IsFull())
          outFile << "List is full." << endl;
        else outFile << "List is not full."  << endl;  
        break;
      case MakeEmpty:
        list.MakeEmpty();
        break;
      case PrintListNew:
        PrintList(outFile, list);
        break;
      default:
        cout << command << " is not a valid command." << endl;
    }
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;
  };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
}







void PrintList(ofstream& dataFile, UnsortedListClass& list)
{
    ItemType item;

    for (list.ResetList(); !list.EndOfList(); )
    {
        item = list.GetNextItem();
        item.Print(dataFile);
    }
    dataFile << endl;
}

