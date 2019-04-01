#include <iostream>
#include "Genstack.h"

using namespace std;

class syntaxCheck
{
public:
  //constructor
  syntaxCheck();
  //destructor
  ~syntaxCheck();
  //used to identify line
  int lineCount;
  //used to identify position
  int charCount;
  void filesyntaxChecker(string file);

};
