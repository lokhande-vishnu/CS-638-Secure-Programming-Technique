/*
CS638
Exercise on Buffer Overflow (Part A and B)

@author Vishnu Sai Rao Suresh Lokhande (lokhande@cs.wisc.edu)
*/



#include <iostream>
#include <string>
#include <cstring>
#include <exception>

using namespace std;

int part_a() {
  int a[4];
  try {
    a[0] = 20;
    a[100] = 23; // Assigning element out of range
  } catch (exception& e) {
    cout << e.what() << "\n";
  }
  return 0;
}

int part_b() {
  string str1 = "Hello";
  try {
    cout << str1[2] << "\n";
    cout << str1[10000] << "\n"; // Accessing element out of range
  } catch (exception& e) {
    cout << e.what() << "\n";
  }
    
  return 0;
}

int main() {
  part_a();
  part_b();

  return 0;
}
