#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPNCalculator::RPNCalculator()
{
    return;
}

RPNCalculator::~RPNCalculator()
{
    return;
}

RPNCalculator::RPNCalculator(RPNCalculator const &obj)
{
    *this = obj;
    return;
}

RPNCalculator &RPNCalculator::operator=(RPNCalculator const &rhs)
{
    if (this != &rhs)
    {
        operandStack = std::stack<double>();
        operandStack = rhs.operandStack;
    }
    return *this;
}

double RPNCalculator::evaluateRPN(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
        {
            std::istringstream convert(token);
            double value;
            if (!(convert >> value))
                throw RPNCalculator::RPNException("Error converting token to double: " + token);
            if (value >= 10)
                throw RPNCalculator::RPNException("Invalid RPN expression: operand must be less than 10.");
            operandStack.push(value);
        }
        else if (isOperator(token[0]))
        {
            if (operandStack.size() < 2)
                throw RPNCalculator::RPNException("Invalid RPN expression: insufficient operands for operator.");
            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();
            double result = performOperation(token[0], operand1, operand2);
            operandStack.push(result);
        }
        else
            throw RPNCalculator::RPNException("Invalid token in RPN expression: " + token);
    }
    if (operandStack.size() != 1)
        throw RPNCalculator::RPNException("Invalid RPN expression: too many operands.");
    return operandStack.top();
}

bool RPNCalculator::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double RPNCalculator::performOperation(char op, double operand1, double operand2)
{
    switch (op)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0)
                throw RPNCalculator::RPNException("Division by zero.");
            return operand1 / operand2;
        default:
            throw RPNCalculator::RPNException("Invalid operator: " + std::string(1, op));
    }
}