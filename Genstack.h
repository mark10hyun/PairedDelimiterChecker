#include <iostream>

using namespace std;
//template class for GenStack
template<class T>
class GenStack{
public:
  int top;
  int size;
  T *origArray; //original dynamic array
  T *resizeArray; //new dynamic array for resizing  stack
  //constructor
  GenStack();
  //overloaded constructor
  GenStack(int maxSize);
  ~GenStack();
  void Push(T value);
  T Pop();
  T Peek();
  bool isEmpty();
  bool isFull();
  int getSize();
  void resizeStack();
};


template<class T>
GenStack<T>::GenStack() //implement default constructor
{

}
template<class T>
GenStack<T>::GenStack(int maxSize) //overloaded constructor
{
  origArray= new T[maxSize];
  size = maxSize;
  top= -1;
}
template<class T>
GenStack<T>::~GenStack()//destructor
{
  delete []origArray;  //deletes the array
}

template<class T> //add a any value type to stack
void GenStack<T>::Push(T value)
{

  // resize the stack
  if(isFull()){
    resizeStack();
    origArray[++top] = value;
  }
  else
  {
    origArray[++top] = value;

  }

}

template<class T> //remove top of stack
T GenStack<T>::Pop()
{
  if( isEmpty())
  { //if it is empty then let the user know
    int i = 0;
    cout << "The Stack is empty" << endl;
    return i;

  }
  else
  {
    return origArray[top--];
  }

}

template<class T>
void GenStack<T>::resizeStack()
{
  //resize the stack when full
  size =size * 5;
  resizeArray = new T[size];
  //copy old stack to new resized array
  for (int i = 0; i < size; i++)
  {
    resizeArray[i]= origArray[i];
  }
    origArray= resizeArray;
}

template<class T>
T GenStack<T>::Peek()
{
  return origArray[top];
}

template<class T>
bool GenStack<T>::isFull()
{
  return (top == size - 1);
}
template<class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
