#include "StackTest.h"
#include "Calculator.h"

void printMatchedPairs(const char* expression) {
  cout << "START MATCH PAIRS" << endl;

  ArrayStack<int>* stack = new ArrayStack<int>();
  for (int i = 0; i < strlen(expression); i++)
  {
    const char c = expression[i];
    if (c == '(')
      stack->push(i + 1);
    else if (c == ')') {
      int left;
      bool success = stack->pop(left);
      if (success)
        cout << "( " << left << ", " << i + 1 << ")" << endl;
      else
        cout << "û�����" << i + 1 << "������ƥ���������" << endl;
    }
  }

  while (!stack->isEmpty()) {
    int left;
    stack->pop(left);
    cout << "û�����" << left << "������ƥ���������" << endl;
  }

}

void bracketMatcher() {

  const char* str1 = "((a+b)/c)*d";
  const char* str2 = "(((((a+b)*c)+e)^2)/2";
  const char* str3 = "((a+b)*c+e)^2)/2";

  //printMatchedPairs(str1);
  printMatchedPairs(str2);
  printMatchedPairs(str3);

}

void calculator() {
  Calculator* calc = new Calculator();
  calc->run();
}

void postfix() {
  Calculator* calc = new Calculator();
  calc->postfix();
}

int runStackTest()
{

  bracketMatcher();

  //calculator();

  postfix();

  return 0;
}
