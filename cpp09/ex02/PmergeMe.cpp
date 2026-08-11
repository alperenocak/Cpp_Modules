#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::printVector(const std::string& prefix, const std::vector<int>& vec)
{
    std::cout << prefix;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << (i + 1 == vec.size() ? "" : " ");
    }
    std::cout << std::endl;
}


bool PmergeMe::parseInput(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        for (size_t j = 0; j < arg.length(); j++)
        {
            if(!std::isdigit(arg[j]))
                return false;
        }
        long val = std::atol(av[i]);
        if (val <= 0 || val > 2147483647)
        {
            return false;
        }
        
        _vectorList.push_back(static_cast<int>(val));
        _dequeList.push_back(static_cast<int>(val));
    }
    return true;
}

void PmergeMe::run(int ac, char **av)
{
    if(!parseInput(ac, av))
    {
        std::cerr<< "Error"<<std::endl;
        return;
    }

    printVector("Before: ", _vectorList);
    
    clock_t startVec = clock();
    fordJohnsonAlgorithm(_vectorList);
    clock_t endVec  = clock();

    
    clock_t startDeq = clock();
    fordJohnsonAlgorithm(_dequeList);
    clock_t endDeq = clock();

    printVector("After: ", _vectorList);

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << _vectorList.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeList.size()
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}
