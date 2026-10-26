#include "JumpSearch.h"
#include <iostream>
#include <cmath>
using namespace std ;

JumpSearch::JumpSearch() : SearchingAlgorithm(){};
int JumpSearch::search(const vector<int>& elements ,int target)
{
    int size = elements.size() ;
    int maxJump = sqrt(size) ;
    int _index=0 ;
    while(_index<size && elements[_index]<target){
        numberComparisons++;
        _index+=maxJump ;
    }
    if(_index>=size){
        _index=size-1 ;
        numberComparisons++;
        if(elements[_index]<target){
            numberComparisons++ ;
            totalComparisons+=numberComparisons;
            totalSearch+=1;
            return -1 ;
        }
        totalComparisons+=numberComparisons;
        totalSearch+=1;
        return _index ;
    }

    for(int i=_index-maxJump ; i<=min(_index,size-1) ; i++){
        numberComparisons++ ;
        
        if(elements[i]==target){
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