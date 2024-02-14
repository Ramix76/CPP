#include "PmergeMe.hpp"

bool isOnlyDigits(char *str)
{
	for (unsigned long i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void validateArgs(int argc, char **argv)
{
    if (argc < 2)
        throw PmergeMe::Error("Not enough arguments");

    for (int i = 1; argv[i]; ++i)
    {
        if (!isOnlyDigits(argv[i]))
            throw PmergeMe::Error("Invalid argument: non-numeric value");

        try
        {
            if (atof(argv[i]) > std::numeric_limits<int>::max() || atof(argv[i]) == 0)
                throw PmergeMe::Error("Invalid argument: out of range or zero");
        }
        catch (const std::exception &e)
        {
            throw PmergeMe::Error("Invalid argument: conversion error");
        }
    }
}

int main(int argc, char **argv)
{
	try
	{
		std::vector<int> vector;
		std::list<int> list;
		std::vector<int> vectorSorted;
		std::list<int> listSorted;

		double durationVec;
		double durationList;

		validateArgs(argc, argv);

		{
			clock_t start = clock();
			vector = PmergeMe::createVector(argv);
			vectorSorted = PmergeMe::insertMergeSortVector(vector);
			clock_t stop = clock();
			durationVec = static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000;
		}

		{
			clock_t start = clock();
			list = PmergeMe::createList(argv);
			listSorted = PmergeMe::insertMergeSortList(list);
			clock_t stop = clock();
			durationList = static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000;
		}

		std::cout << "Before: " << PmergeMe::printVector(vector) << std::endl;
		std::cout << "After - vector: " << PmergeMe::printVector(vectorSorted) << std::endl;
		std::cout << "After - list: " << PmergeMe::printList(listSorted) << std::endl;
		std::cout << "Time to process a range of " << vector.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << durationVec << " miliseconds" << std::endl;
		std::cout << "Time to process a range of " << list.size() << " elements with std::list: " << std::fixed << std::setprecision(5) << durationList << " miliseconds" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}