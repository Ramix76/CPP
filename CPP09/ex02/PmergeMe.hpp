#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>

class MergeInsertSort
{
    private:
        std::vector<int> sequence;

    public:
        MergeInsertSort();
        void readSequence();
        void mergeInsertSort();
        void merge(const std::vector<int>& left, const std::vector<int>& right);
        void printSortedSequence() const;
        
};

#endif