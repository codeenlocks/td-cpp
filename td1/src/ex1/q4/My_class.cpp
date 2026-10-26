#include <iostream>
#include "My_class.h"
using namespace std;


My_class::My_class(string ele) : element(ele) {}

My_class::My_class() : element("EMPTY") {}

void My_class::print_my_element(){
    cout << element << endl ;
}