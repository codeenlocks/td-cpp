#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std ;


bool isPalindrome(const string& input){
    stack<char> lifo ;
    queue<char> fifo ;
    int n = input.size();

    for(int i=0 ; i<n; i++){
        lifo.push(input[i]);
        fifo.push(input[i]) ;
    }
    
    for(int i=0 ; i<n; i++){
        if(lifo.top()!=fifo.front()){
            return false ;
        }
        lifo.pop();fifo.pop() ;

    }
    return true ;
}

int main()
{
    cout << boolalpha ;
    cout <<  "Is racecar a palindrome ?" ;
    cout << isPalindrome("racecar") << endl ;

    cout <<  "Is hello a palindrome ?" ;
    cout << isPalindrome("hello") << endl ;

    return 0;
}
