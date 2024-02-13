#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <stdexcept>

class RPNCalculator
{
    public:
        RPNCalculator();
        ~RPNCalculator();
        RPNCalculator(RPNCalculator const &obj);
        RPNCalculator &operator=(RPNCalculator const &rhs);
        double evaluateRPN(const std::string &expression);
        class RPNException : public std::exception
        {
            public:
            RPNException(const std::string& message) : errorMessage(message) {}
                virtual const char* what() const throw()
                {
                    return errorMessage.c_str();
                }
                virtual ~RPNException() throw() {}

            private:
                std::string errorMessage;
        };

    private:
        bool isOperator(char c);
        double performOperation(char op, double operand1, double operand2);
        std::stack<double> operandStack;
};

#endif