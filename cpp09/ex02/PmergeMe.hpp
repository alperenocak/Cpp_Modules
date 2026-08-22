#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cerrno>

class PmergeMe
{
private:
    std::vector<int>    _vectorList;
    std::deque<int>     _dequeList;

    bool                parseInput(int ac, char **av);
    static size_t       getJacobsthal(size_t n);
    static void         printVector(const std::string& prefix, const std::vector<int>& vec);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    template <typename Container>
    static void fordJohnsonAlgorithm(Container& container)
    {
        if (container.size() <= 1)
            return;

        bool hasStraggler = (container.size() % 2 != 0);
        int straggler = 0;
        if (hasStraggler)
        {
            straggler = container.back();
            container.pop_back();
        }

        Container mainChain;
        Container pend;
        for (size_t i = 0; i < container.size(); i += 2)
        {
            if (container[i] > container[i + 1])
            {
                mainChain.push_back(container[i]);
                pend.push_back(container[i + 1]);
            }
            else
            {
                mainChain.push_back(container[i + 1]);
                pend.push_back(container[i]);
            }
        }

        Container originalMain = mainChain;
        fordJohnsonAlgorithm(mainChain);

        Container sortedPend;
        for (size_t i = 0; i < mainChain.size(); ++i)
        {
            for (size_t j = 0; j < originalMain.size(); ++j)
            {
                if (mainChain[i] == originalMain[j])
                {
                    sortedPend.push_back(pend[j]);
                    originalMain[j] = -1;
                    break;
                }
            }
        }

        Container S;
        S.push_back(sortedPend[0]);
        for (size_t i = 0; i < mainChain.size(); ++i)
        {
            S.push_back(mainChain[i]);
        }

        size_t lastJacob = 1;
        size_t jacobIndex = 3;
        size_t P = sortedPend.size();

        while (lastJacob < P)
        {
            size_t nextJacob = getJacobsthal(jacobIndex);
            size_t target = std::min(nextJacob, P);

            for (size_t i = target; i > lastJacob; --i)
            {
                int elementToInsert = sortedPend[i - 1];
                int correspondingMax = mainChain[i - 1];

                typename Container::iterator bound = std::lower_bound(S.begin(), S.end(), correspondingMax);
                typename Container::iterator pos = std::lower_bound(S.begin(), bound, elementToInsert);
                S.insert(pos, elementToInsert);
            }

            lastJacob = nextJacob;
            jacobIndex++;
        }

        if (hasStraggler)
        {
            typename Container::iterator pos = std::lower_bound(S.begin(), S.end(), straggler);
            S.insert(pos, straggler);
        }

        container = S;
    }

    void run(int ac, char** av);
};

#endif


