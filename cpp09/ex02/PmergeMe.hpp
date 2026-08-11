#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
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
        
        if()
    }
    
    void run(int ac, char** av);

};



#endif


