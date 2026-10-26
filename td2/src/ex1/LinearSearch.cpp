#include "LinearSearch.h"
#include <iostream>
using namespace std ;

LinearSearch::LinearSearch() : SearchingAlgorithm(){};
int LinearSearch::search(const vector<int>& elements ,int target)
{
    int _index=0 ;
    for(int element : elements){
        numberComparisons++ ;
        
        if(element==target){
            totalComparisons+=numberComparisons;
            totalSearch+=1;
            return _index ;
        }
        _index ++;
    }
    totalComparisons+=numberComparisons;
    totalSearch+=1;
    return -1 ;
}