#include "PmergeMe.hpp"

MergeInsertSort::MergeInsertSort() {}

void MergeInsertSort::readSequence()
{
    int num;

    std::cout << "Enter a positive integer sequence (enter a non-positive integer to stop):" << std::endl;
    // Keep reading integers until a non-positive integer is entered
    while (true)
    {
        std::cin >> num;
        if (num <= 0)
        {
            break;  // Stop reading when a non-positive integer is entered
        }
        sequence.push_back(num);
    }
}

void MergeInsertSort::mergeInsertSort()
{
   if (sequence.size() > 1)
   {
        int mid = sequence.size() / 2;
        std::vector<int> left(sequence.begin(), sequence.begin() + mid);
        std::vector<int> right(sequence.begin() + mid, sequence.end());
        MergeInsertSort leftSorter;
        leftSorter.sequence = left;
        leftSorter.mergeInsertSort();
        MergeInsertSort rightSorter;
        rightSorter.sequence = right;
        rightSorter.mergeInsertSort();
        // Merge the sorted subarrays
        merge(left, right);
    }
}

void MergeInsertSort::merge(const std::vector<int>& left, const std::vector<int>& right)
{
    size_t i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            sequence[k++] = left[i++];
        else
            sequence[k++] = right[j++];
    }
    while (i < left.size())
        sequence[k++] = left[i++];
    while (j < right.size())
        sequence[k++] = right[j++];
}

void MergeInsertSort::printSortedSequence() const
{
     std::cout << "Sorted sequence: ";
        for (size_t i = 0; i < sequence.size(); ++i)
        {
            std::cout << sequence[i] << " ";
        }
        std::cout << std::endl;   
}