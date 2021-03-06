#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void createFile(string fileName, string suffix, int size, int zeroPos) {
  srand (time(NULL));                     // initialize random seed

  ofstream outputFile;
  outputFile.exceptions(ofstream::failbit | ofstream::badbit);
  outputFile.open((fileName + suffix).c_str());

  for (int i = 0; i < size; ++i)
  {
    if (i == zeroPos) {
      outputFile << 0;
    } 
    else {  
      int value = rand() % 9 + 1;         // generate number between 1 and 9
      outputFile << value;
    }
    if (i < size - 1) {
      outputFile << " ";
    }
  }

  outputFile.close();
}

int main()
{
  
  string fileName;
  int size;
  bool validSize;

  cout << "What would you like to name the output file base name?: ";
  getline(cin, fileName); 

  do
  {
    validSize = true;
    cout << "Enter file size that is at least 1000: ";
    cin >> size; 
    if (size < 1000)
    {
      cout << "File size must be at least 1000." << endl;
      validSize = false;
    }
  } while(!validSize);

  try {
    createFile(fileName, "_noZero", size, -1);
    createFile(fileName, "_frontZero", size, 0);
    createFile(fileName, "_midZero", size, size/2);
    createFile(fileName, "_endZero", size, size - 1);
  }
  catch (ofstream::failure& e) {
    cout << "Error creating file!" << endl;
    cout << e.what() << endl;
    return 1;
  }
 
  return 0;
}
