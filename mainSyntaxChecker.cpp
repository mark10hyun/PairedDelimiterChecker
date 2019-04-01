#include <iostream>
#include "syntaxCheck.h"
int main(int argc, char const *argv[]) {
  string fileName = " ";
  cout<<"Please type the .cpp file that your want to check for Syntax errors."<<endl;
  cin>>fileName;
  syntaxCheck object1;
  object1.filesyntaxChecker(fileName);
  return 0;
}
