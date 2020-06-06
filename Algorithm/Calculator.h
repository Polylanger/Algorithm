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
      // �����ֽ�ch����д������������Ϊ������cin�Զ����ַ���ת��Ϊ����
      // ��һ�����������֣��м���ĳ�ַָ����ֿ�ʱ��cin���Զ�����ָ�Ϊ�������\n����ö��ѭ��
      // ��һ���м���#ʱ��������#ʱ�ͽ�ֹ����
      cin.putback(c);
      // ��������ַ�����յı�����ƥ��ʱ�����յı�����Ϊ0���������е�������Ȼ����
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
    cout << "ȱ���Ҳ�����" << endl;
    return false;
  }
  if (!stack.pop(left)) {
    cout << "ȱ���������" << endl;
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
      cout << "����������Ϊ0" << endl;
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
