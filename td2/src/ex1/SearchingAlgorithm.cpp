#include "SearchingAlgorithm.h"
#include <iostream>
using namespace std ;

int SearchingAlgorithm::totalComparisons=0 ;
int SearchingAlgorithm::totalSearch=0 ;
int SearchingAlgorithm::averageComparisons=0 ;


SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0){} 
void SearchingAlgorithm::displaySearchResults(ostream& out, int result, int target) const 
{
    averageComparisons = (totalSearch==0)?0:totalComparisons/totalSearch ;
    out << "====== Search Results ======"
    << endl << "Target : " << target
    << endl << "Result : " << result
    << endl << ">> Total Number of Comparisons : "<< totalComparisons
    << endl << ">> Average Number of Comparisons : "<< averageComparisons << endl;
}