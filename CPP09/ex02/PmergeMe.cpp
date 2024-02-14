#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &obj)
{
    (void)obj;
    return ;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    (void)rhs;
    return *this;
}

std::vector<int> PmergeMe::insertVector(std::vector<int> vector)
{
    for (std::vector<int>::size_type i = 1; i < vector.size(); ++i)
    {
        int tmp = vector[i];
        std::vector<int>::size_type j = i;
        while(j > 0 && vector[j - 1] > tmp)
        {
            vector[j] = vector[j - 1];
            --j;
        }
        vector[j] = tmp;
    }
    return vector;
}

std::vector<int> PmergeMe::mergeVector(const std::vector<int> &left, const std::vector<int> &right)
{
    std::vector<int> mergedVector;
    std::vector<int>::const_iterator itLeft = left.begin();
    std::vector<int>::const_iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end())
    {
        if (*itLeft < *itRight)
        {
            mergedVector.push_back(*itLeft);
            ++itLeft;
        }
        else
        {
            mergedVector.push_back(*itRight);
            ++itRight;
        }
    }
    std::copy(itLeft, left.end(), std::back_inserter(mergedVector));
    std::copy(itRight, right.end(), std::back_inserter(mergedVector));
    return mergedVector;
}

std::vector<int> PmergeMe::insertMergeSortVector(std::vector<int> vector)
{
    if (vector.size() <= 5)
        return PmergeMe::insertVector(vector);
    else
    {
        std::vector<int>::size_type mid = vector.size() / 2;
        std::vector<int> left(vector.begin(), vector.begin() + mid);
        std::vector<int> right(vector.begin() + mid, vector.end());

        std::vector<int> leftMerged = PmergeMe::insertMergeSortVector(left);
        std::vector<int> rightMerged = PmergeMe::insertMergeSortVector(right);

        return PmergeMe::mergeVector(leftMerged, rightMerged);
    }
}

std::string PmergeMe::printVector(const std::vector<int> &vector)
{
    std::ostringstream out;

    for (std::vector<int>::size_type i = 0; i < vector.size(); ++i)
    {
        if (i > 10)
        {
            out << "[...]";
            break;
        }
        out << vector[i] << " ";
    }
    return out.str();
}

std::list<int> PmergeMe::insertList(std::list<int> &list)
{
    std::list<int>::iterator it, j;

    for (it = ++list.begin(); it != list.end(); ++it)
    {
        int tmp = *it;
        j = it;
        while (j != list.begin() && *std::prev(j) > tmp)
        {
            *j = *(std::prev(j));
            --j;
        }
        *j = tmp;
    }
    return list;
}

std::list<int> PmergeMe::mergeList(const std::list<int> &left, const std::list<int> &right)
{
    std::list<int> mergedList;
    std::list<int>::const_iterator itLeft = left.begin();
    std::list<int>::const_iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end())
    {
        if (*itLeft < *itRight)
        {
            mergedList.push_back(*itLeft);
            ++itLeft;
        }
        else
        {
            mergedList.push_back(*itRight);
            ++itRight;
        }
    }
    mergedList.insert(mergedList.end(), itLeft, left.end());
    mergedList.insert(mergedList.end(), itRight, right.end());

    return mergedList;
}

std::list<int> PmergeMe::insertMergeSortList(std::list<int> list)
{
    if (list.size() <= 5)
        return PmergeMe::insertList(list);
    else
    {
        std::list<int>::size_type mid = list.size() / 2;
        std::list<int> left(list.begin(), ++std::next(list.begin(), mid));
        std::list<int> right(++std::next(list.begin(), mid), list.end());

        std::list<int> leftMerged = PmergeMe::insertMergeSortList(left);
        std::list<int> rightMerged = PmergeMe::insertMergeSortList(right);

        return PmergeMe::mergeList(leftMerged, rightMerged);
    }
}

std::string PmergeMe::printList(const std::list<int> &list)
{
    std::ostringstream out;
    int counter = 0;

    for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
    {
        if (counter > 10)
        {
            out << "[...]";
            break;
        }
        out << *it << " ";
        ++counter;
    }
    return out.str();
}

std::vector<int>	PmergeMe::createVector(char **argv){
	std::vector<int>	vector;

	for (int i = 1; argv[i]; i++) {
		vector.insert(vector.end(), atoi(argv[i]));
	}
	return (vector);
}

std::list<int>	PmergeMe::createList(char **argv){
	std::list<int>	list;

	for (int i = 1; argv[i]; i++) {
		list.push_back(atoi(argv[i]));
	}
	return (list);
}