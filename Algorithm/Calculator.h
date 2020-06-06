#pragma once

#include "Common.h"
#include "ArrayStack.h"

class Calculator {
public:
  Calculator() {}
  void run();
  void clear();
  void postfix();

private:
  ArrayStack<double> stack;
  void addOperand(double value);
  bool get2Operands(double& left, double& right);
  void doOperator(char op);

  int icp(const char op);
  int isp(const char op);
  bool isDigital(const char ch);

};

inline void Calculator::run()
{
  char c;
  double newOperator;

  while (cin >> c, c != '#') {
    switch (c) {
    case '+': case '-': case '*': case '/':
      doOperator(c);
      break;
    default:
      // 这里又将ch重新写入输入流，是为了利用cin自动将字符串转化为数字
      // 当一行输入多个数字，中间用某种分隔符分开时，cin会自动将其分割为多个，待\n后调用多次循环
      // 当一行中间有#时，在输入#时就截止程序
      cin.putback(c);
      // 当输入的字符与接收的变量不匹配时，接收的变量置为0，输入流中的输入仍然保留
      cin >> newOperator;
      //newOperand = ch;
      addOperand(newOperator);
    }
  }

  stack.output();
}

inline void Calculator::clear()
{
  stack.makeEmpty();
}

inline int Calculator::icp(const char op)
{
  switch (op)
  {
  case '#':
    return 0;
  case '(':
    return 6;
  case '*':
  case '/':
  case '%':
    return 4;
  case '+':
  case '-':
    return 2;
  case ')':
    return 1;
  default:
    cout << "Unexception operator: " + op << endl;
    return 0;
  }
}

inline int Calculator::isp(const char op)
{
  switch (op)
  {
  case '#':
    return 0;
  case '(':
    return 1;
  case '*':
  case '/':
  case '%':
    return 5;
  case '+':
  case '-':
    return 3;
  case ')':
    return 6;
  default:
    cout << "Unexception operator: " + op << endl;
    return 0;
  }
}

inline bool Calculator::isDigital(const char ch)
{
  return ch == 46 || (48 <= ch && ch <= 57);
}

inline void Calculator::addOperand(double value)
{
  stack.push(value);
}

inline bool Calculator::get2Operands(double& left, double& right)
{
  bool success = true;
  if (!stack.pop(right)) {
    cout << "缺少右操作数" << endl;
    return false;
  }
  if (!stack.pop(left)) {
    cout << "缺少左操作数" << endl;
    return false;
  }

  return success;
}

inline void Calculator::doOperator(char op)
{
  double left, right;
  get2Operands(left, right);

  switch (op)
  {
  case '+':
    addOperand(left + right);
    break;
  case '-':
    addOperand(left - right);
    break;
  case '*':
    addOperand(left * right);
    break;
  case '/':
    if (right == 0) {
      cout << "被除数不能为0" << endl;
      clear();
    }
    addOperand(left / right);
    break;
  default:
    cout << "Some unexcepted thing happends" << endl;
    break;
  }
}

inline void Calculator::postfix()
{
  char rightOperator , leftOperator;

  ArrayStack<char> stack;
  stack.push('#');

  cin.get(rightOperator);
  while (!stack.isEmpty()) {
    if (isDigital(rightOperator)) {
      cout << rightOperator;
      cin.get(rightOperator);
      continue;
    }

    leftOperator = stack.getTop();

    if (isp(leftOperator) < icp(rightOperator)) {
      stack.push(rightOperator);
      cin.get(rightOperator);
    }
    else if (isp(leftOperator) > icp(rightOperator)) {
      stack.pop(leftOperator);
      cout << leftOperator;
    }
    else {
      stack.pop(leftOperator);

      cout << "?";
      if (leftOperator == '(') {
        cin.get(rightOperator);
      }
      else if (leftOperator == '#') {
        break;
      }
    }
  }
}
