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

        typedef typename Container::value_type ValueType;
        typedef std::pair<ValueType, ValueType> PairType;
        typedef std::vector<PairType> PairContainer;

        bool hasStraggler = (container.size() % 2 != 0);
        ValueType straggler;
        if (hasStraggler)
        {
            straggler = container.back();
            container.pop_back();
        }

        PairContainer pairs;
        Container mainChain;
        for (size_t i = 0; i < container.size(); i += 2)
        {
            if (container[i] > container[i + 1])
            {
                pairs.push_back(std::make_pair(container[i], container[i + 1]));
                mainChain.push_back(container[i]);
            }
            else
            {
                pairs.push_back(std::make_pair(container[i + 1], container[i]));
                mainChain.push_back(container[i + 1]);
            }
        }

        fordJohnsonAlgorithm(mainChain);

        PairContainer sortedPairs;
        for (typename Container::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
        {
            for (typename PairContainer::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
            {
                if (pit->first == *it)
                {
                    sortedPairs.push_back(*pit);
                    pairs.erase(pit);
                    break;
                }
            }
        }
        pairs = sortedPairs;

        Container S;
        S.push_back(pairs[0].second);
        for (size_t i = 0; i < pairs.size(); ++i)
        {
            S.push_back(pairs[i].first);
        }

        size_t lastJacob = 1;
        size_t jacobIndex = 2;
        size_t P = pairs.size();

        while (lastJacob < P)
        {
            size_t nextJacob = getJacobsthal(jacobIndex);
            size_t target = std::min(nextJacob, P);

            for (size_t i = target; i > lastJacob; --i)
            {
                ValueType elementToInsert = pairs[i - 1].second;
                ValueType correspondingMax = pairs[i - 1].first;

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


