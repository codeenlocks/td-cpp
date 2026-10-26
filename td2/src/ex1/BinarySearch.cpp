#include "BinarySearch.h"
#include <iostream>
#include <cmath>
using namespace std ;

BinarySearch::BinarySearch() : SearchingAlgorithm(){};
int BinarySearch::search(const vector<int>& elements ,int target)
{
    int size = elements.size() ;
    int low = 0 ;
    int high = size - 1 ;
    while(low <= high){
        numberComparisons++;
        int mid = (low + high) / 2 ;
        if(elements[mid] == target){
            totalComparisons+=numberComparisons;
            totalSearch+=1;
            return mid ;
        }
        else if(elements[mid] < target){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    totalComparisons+=numberComparisons;
    totalSearch+=1;
    return -1 ;
}