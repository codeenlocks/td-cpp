#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H
#include <iostream>
#include <vector>
using namespace std ;

class SearchingAlgorithm
{
protected:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch ;
    static int averageComparisons ;
public:
    SearchingAlgorithm();
    virtual int search(const vector<int>&,int) = 0 ;
    void displaySearchResults(ostream&,int,int) const ;
};



#endif