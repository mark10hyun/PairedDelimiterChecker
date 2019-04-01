#include <iostream>
#include <fstream>
#include "syntaxCheck.h"
using namespace std;
//the constructor
syntaxCheck::syntaxCheck()
{


}
// the destructor
syntaxCheck::~syntaxCheck()
{
}

//Takes a text or .cpp file and checks if there are any syntax errors

void syntaxCheck::filesyntaxChecker(string fileName){
     //make the stack size at 1000 because stack can be resized if full
    ifstream cppfile;
    GenStack<char> origstack(1000);
    string line = " ";
    int lineCount=0;
    int charCount=0;
    char openingDelim = origstack.Peek();

    cppfile.open(fileName);
    while(getline(cppfile, line)) //iterate through the text file or cpp
    {
      lineCount++;
      charCount=0;
      //reads through entire cpp file and push any opening demiliters.
      for(int i=0; i < line.size(); ++i){
        char currDelim = line[i];
        charCount++;
        if((currDelim == '{')|| (currDelim=='(') || (currDelim=='['))
        {
          origstack.Push(currDelim);
        }
        //If there are no errors then Pop each delimiter/element
        if (currDelim== '}' && openingDelim=='{')
        {
          origstack.Pop();
        }
        else if( currDelim== ')' &&  openingDelim== '(')
        {
          origstack.Pop();
        }
        else if(currDelim== ']' && openingDelim== '[')
        {
          origstack.Pop();
        }
        //check for non-paired dimlititers with the pairs
        else if (openingDelim=='(' && currDelim== '}')
        {
          cout << "Syntax Error found on line " << lineCount << " at character "<< charCount<<endl;
          cout<< " Syntax Error : Closed Bracket "<<" } "<< " Correction: replace with open paranthesis " << " ) " << "." << endl;
          break;
        }
        else if (openingDelim=='(' && currDelim== ']')
        {
          cout << "Syntax Error on line " << lineCount << " at character "<< charCount<< endl;
          cout<< "Syntax Error : "<< " ] " << "Correction : replace with  " << " ) " << "." << endl;
          break;
        }
        else if (openingDelim=='{' && currDelim== ')')
        {
          cout << "Syntax Error on line " << lineCount << " at character "<< charCount<<endl;
          cout<< "Syntax Error : '"<<" ) "<< " Correction : Replace with  '" << " } " << "." << endl;
          break;
        }
        else if (openingDelim=='{' && currDelim== ']')
        {
          cout << "Syntax Error on line " << lineCount << " at character "<< charCount<< endl;
          cout<<"Syntax Error: "<<" ] " << "Correction : Replace with  " << " } " << "." << endl;
          break;

        }
        else if (openingDelim=='[' && currDelim== '}')
        {
          cout << "Syntax Error on line " << lineCount << " at character "<< charCount << endl;
          cout<<"Syntax Error : '"<<" } "<< "Error : Replace with  " << " ] " << " . " << endl;
          break;
        }
        else if (openingDelim=='[' && currDelim== ')')
        {
        cout << "Syntax Error on line " << lineCount << " at character "<< charCount<<endl;
        cout<< "Syntax Error: ) "<<endl;
        cout<< "Correction: Replace with  " << " ] " << "." << endl;
        break;
        }

        //check if there any closing braces that do not correspond to an opening brace
        else if(origstack.isEmpty() && currDelim== ']')
        {

          cout << "Syntax Error on line " << lineCount << " at character "<< charCount<<"."<<endl;
          cout << "Syntax Error : ] "<< endl;
          cout<< "Correction : Replace with " << "[ " <<"."<< endl;
          break;
        }
        else if(origstack.isEmpty() && currDelim== '}')
        {

            cout << "Sytax Error on line " << lineCount << " at character "<< charCount<<"." <<endl;
            cout<< "Syntax Error : } "<< endl;
            cout<<"Correction : Needs an opening  '" << " { " <<"."<< endl;
            break;
        }
        else if(origstack.isEmpty() && currDelim== ')')
        {
            cout << "Sytnax Error on line " << lineCount << " at character "<< charCount<<" " << " ) "<< " Needs an opening  " << " ( " <<"'"<< endl;
            break;
        }
      }
    }
    cppfile.close();
    //if the stack is not empty then  there is an end of line missing error
     if(!origstack.isEmpty())
     {
       //if the stack contains delimiter then print the error
       if( origstack.Peek() =='{')
       {
         cout << "Syntax Error - Missing " << " } " << "" << endl;
       }
       else  if( origstack.Peek() =='[')
       {
         cout << "Syntax Error - Missing "<< " ] " << "" << endl;
       }
       else  if( origstack.Peek() =='(')
       {
           cout << "Syntax Error - Missing "<< " ) " << "" << endl;
       }
     }
     else
     {
       cout<<"No Errors"<<endl;
     }

  }
