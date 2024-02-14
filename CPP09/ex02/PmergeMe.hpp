#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <ctime>
# include <sstream>
# include <iomanip>
# include <iterator>

class PmergeMe
{
    private:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const &obj);
        PmergeMe &operator=(PmergeMe const &rhs);

        static std::vector<int> insertVector(std::vector<int> vector);
        static std::vector<int> mergeVector(const std::vector<int> &left, const std::vector<int> &right);

        static std::list<int> insertList(std::list<int> &list);
        static std::list<int> mergeList(const std::list<int> &left, const std::list<int> &right);
    public:
        static std::vector<int> createVector(char **argv);
        static std::vector<int> insertMergeSortVector(std::vector<int> vector);
        static std::string printVector(const std::vector<int> &vector);

        static std::list<int> createList(char **argv);
        static std::list<int> insertMergeSortList(std::list<int> list);
        static std::string printList(const std::list<int> &list);

        class Error : public std::exception
        {
            public:
            Error(const std::string& message) : _errorMessage(message) {}
                virtual const char* what() const throw()
                {
                    return _errorMessage.c_str();
                }
                virtual ~Error() throw() {}

            private:
                std::string _errorMessage;
        };
};

#endif