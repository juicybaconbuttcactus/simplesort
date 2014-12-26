#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

class binarytree
{
  private:

} heap;

vector<float>& insertion(vector<float>& v)
{
  float temp;
  int n;
  for(int i = 1; i < v.size(); i++) {
    temp = v[i];
    n = i - 1;
    while((n >= 0) && (temp < v[n])) {
      v[n + 1] = v[n];
      n--;
    }
    v[n + 1] = temp;
  }
}

vector<float>& selection(vector<float>& v)
{
  float temp;
  int min;
  for(int i = 0; i < v.size() - 1; i++) {
    min = i;
    for(int n = i + 1; n < v.size(); n++) {
      if(v[n] < v[min]) min = n;
    }
    if(min != i) {
      temp = v[i];
      v[i] = v[min];
      v[min] = temp;
    }
  }
}

vector<float>& bubble(vector<float>& v)
{
  float temp;
  int count;
  do {
    count = 0;
    for(int i = 0; i < v.size() - 1; i++) {
      if(v[i + 1] < v[i]) {
        count++;
        temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
      }
    }
  } while(count > 0);
}

int main(int argc, char **argv)
{
  vector<float> v;
  float value;
  string filename;
  string algorithm;

  if(argc != 3) {
    cout << "Usage:" << endl;
    cout << "  ./simplesort [file] [algorithm]" << endl;
    cout << "  Where algorithm = [bubble, selection, insertion]" << endl;
  } else {
    algorithm = argv[2];
    filename = argv[1];
  }

  // Read in the values from the specified file
  ifstream infile(filename.c_str());
  while(infile >> value) {
    v.push_back(value);
  }

  // Sort the array using the specified algorithm
  if(algorithm == "bubble") {
    bubble(v);
  } else if(algorithm == "selection") {
    selection(v);
  } else if(algorithm == "insertion") {
    insertion(v);
  } else {
    cerr << "The specified algorithm does not exist." << endl;
    exit(1);
  }
}
