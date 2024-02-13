#include "PmergeMe.hpp"

int main() {
    MergeInsertSort sorter;
    sorter.readSequence();
    sorter.mergeInsertSort();
    sorter.printSortedSequence();

    return 0;
}