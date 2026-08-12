#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& src) : _vectorList(src._vectorList), _dequeList(src._dequeList)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        _vectorList = rhs._vectorList;
        _dequeList = rhs._dequeList;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

size_t PmergeMe::getJacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t curr = 0;
    for (size_t i = 2; i <= n; ++i)
    {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
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
        if (arg.empty())
            return false;
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!std::isdigit(arg[j]) && !std::isspace(arg[j]) && arg[j] != '+')
                return false;
        }
        std::stringstream ss(arg);
        std::string token;
        while (ss >> token)
        {
            for (size_t j = 0; j < token.length(); j++)
            {
                if (j == 0 && token[j] == '+') continue;
                if (!std::isdigit(token[j]))
                    return false;
            }
            long val = std::atol(token.c_str());
            if (val <= 0 || val > 2147483647)
                return false;
            _vectorList.push_back(static_cast<int>(val));
            _dequeList.push_back(static_cast<int>(val));
        }
    }
    return !_vectorList.empty();
}

void PmergeMe::run(int ac, char **av)
{
    if (!parseInput(ac, av))
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    printVector("Before: ", _vectorList);

    clock_t startVec = clock();
    fordJohnsonAlgorithm(_vectorList);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    fordJohnsonAlgorithm(_dequeList);
    clock_t endDeq = clock();

    printVector("After:  ", _vectorList);

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vectorList.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeList.size()
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

