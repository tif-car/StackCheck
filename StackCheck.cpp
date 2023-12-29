#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Stack{
  public:
    int top;
    int stackArray[1000];
    Stack(){
      top = -1;
    }
    void push(int addValue);
    char pop();
    char peek();
    bool isEmpty();
}; 

void Stack::push(int addValue){
  if(top >= 999){
    cout << "There is not enough room for adding new input!\n";
    return;
  }
  stackArray[++top] = addValue;
}

char Stack::pop(){
  if(top < 0){
    cout << "There is no element in this stack!\n";
    return 0;
  }
  return stackArray[top--];
}

char Stack::peek(){
  if(top < 0){
    cout << "There is no element in this stack!\n";
    return 0;
  }
  return stackArray[top];
  }

bool Stack::isEmpty(){
  return (top < 0);
}

bool Balanced(const string& input){
  Stack s;
  for(char c : input){
    if(c == '(' || c == '[' || c == '{'){
      s.push(c);
  } else if (c == ')' || c == ']' || c == '}'){
      if(s.isEmpty()) return false;
      char topChar = s.pop();
      if((c == ')' && topChar != '(') ||
        (c == ']' && topChar != '[') ||
        (c == '}' && topChar != '{')){
          return false;
      }
    }
  }
  return s.isEmpty();
}

int main(int argc, char** argv) {
  
  if(argc != 3) {
    cout << "Error, please enter inputFile.txt, outputFile.txt" << endl;
    return 1;
  }

  string inputFile = argv[1];       //input File
  string outputFile = argv[2];      //outputFile

  ifstream inFile(inputFile);
  if(!inFile.is_open()){
    cout << "Error, cannot open input file: " << inputFile << endl;
    return 1;
  }
  string inputString;
  getline(inFile, inputString);
  inFile.close();

  bool result = Balanced(inputString);
  ofstream outFile(outputFile);
  if(!outFile.is_open()){
    cout << "Error, cannot open output file: " << endl;
    return 1;
  }
  outFile << (result ? "true" : "false") << endl; 
  outFile.close();
  
  return 0;
  
} //end of main function



