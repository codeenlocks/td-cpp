#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"
#include <iostream>
#include <vector>
using namespace std ;


int main(){
    vector<int> tab = {1,4,3,6,7};
    const vector<int> tab_ref = tab;
    cout << "Searching for 5 in the array {1,4,3,6,7} using Linear Search" << endl ;
    LinearSearch myLSearch = LinearSearch();
    int result_fake = myLSearch.search(tab_ref,5); //This may return -1
    myLSearch.displaySearchResults(cout,result_fake,5) ;

    cout << "Searching for 6 in the array {1,4,3,6,7} using Linear Search" << endl ;
    LinearSearch myLSearch2 = LinearSearch();
    int result = myLSearch2.search(tab_ref,6);
    myLSearch2.displaySearchResults(cout,result,6) ;


    cout << "Searching for 5 in the array {1,4,3,6,7} using Jump Search" << endl ;
    JumpSearch myJSearch = JumpSearch();
    int result_jump = myJSearch.search(tab_ref,5);
    myJSearch.displaySearchResults(cout,result_jump,5) ;

    cout << "Searching for 6 in the array {1,4,3,6,7} using Jump Search" << endl ;
    JumpSearch myJSearch2 = JumpSearch();
    int result_jump2 = myJSearch2.search(tab_ref,6);
    myJSearch2.displaySearchResults(cout,result_jump2,6) ;

    cout << "Searching for 5 in the array {1,4,3,6,7} using Binary Search" << endl ;
    BinarySearch myBSearch = BinarySearch();
    int result_binary = myBSearch.search(tab_ref,5);
    myBSearch.displaySearchResults(cout,result_binary,5) ;

    cout << "Searching for 6 in the array {1,4,3,6,7} using Binary Search" << endl ;
    BinarySearch myBSearch2 = BinarySearch();
    int result_binary2 = myBSearch2.search(tab_ref,6);
    myBSearch2.displaySearchResults(cout,result_binary2,6) ;

    return 0 ;
}