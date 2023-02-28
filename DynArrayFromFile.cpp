#include <iostream>
#include <fstream>

using namespace std;

int countNumberOfIntsInFile(ifstream& inFile) {
  int count = 0, num = 0;
  while (!inFile.eof()) {
    inFile >> num;
    if (!inFile.bad()) {
      count++;
    }
  }
  return count;
}

void fillArray(ifstream& inFile, int arr[], int size) {
  for (int i = 0; i < size; i++) {
    inFile >> arr[i];
    cout << arr[i] << endl;
  }
}

int main() {
  // open nums.txt with a variable number of integers
  // count the number of ints in the file
  // and allocate a perfectly fit array to
  // store the numbers
  // fill the array with the numbers
  ifstream inFile("nums.txt");
  int count = 0, * arr = NULL;

  count = countNumberOfIntsInFile(inFile);
  cout << "count: " << count << endl;
  arr = new int[count];

  inFile.clear(); // clear the EOF bit
  inFile.seekg(0, ios::beg);
  fillArray(inFile, arr, count);

  inFile.close();
  delete [] arr;
  arr = NULL;
  
	return 0;
}
