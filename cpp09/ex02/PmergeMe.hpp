#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class PmergeMe
{
private:

    std::vector<int>    _vectorList;
    std::deque<int>     _dequeList;

    bool         parseInput(int ac, char **av);
    static size_t       getJacobsthal(size_t n);
    static void         printVector(const std::string& prefix, const std::vector<int>& vec);

public:
    PmergeMe();
    ~PmergeMe();

    template <typename Container>
    void fordJohnsonAlgorithm(Container& container)
    {
        container.size();
        if(container.size() < 1) return;

        typedef typename Container::value_type ValueType;
        typedef std::pair<ValueType, ValueType> PairType;
        typedef std::vector<PairType> PairContainer;

        
        PairContainer pairs;
        int 
    }
    
    void run(int ac, char** av);

};

#endif
