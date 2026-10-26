#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H
#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm
{
public:
    LinearSearch();
    int search(const vector<int>&,int) override ;
};


#endif