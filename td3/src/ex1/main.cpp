#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers){
    vector<int> visitedIndex(numbers.size(),0); // Create a copy to avoid modifying the original vector
    for(int number : numbers){
        int count = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == number && visitedIndex[i] == 0){
                count++;
                visitedIndex[i] = 1; // Mark the number as counted to avoid duplicate counting
            }
        }
        if(count > 0){
            cout << "Frequency of " << number << ": " << count << endl;
        }
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers){
    map<int, int> frequencyMap;
    for(int number : numbers){
        frequencyMap[number]++;
    }
    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    //Test countFrequencyBruteForce
    cout << "Brute Force Frequency Count:" << endl;
    countFrequencyBruteForce(numbers);

    //Test countFrequencyOptimal
    cout << "\nFrequency (Optimal):" << endl;
    map<int, int> frequencyMap = countFrequencyOptimal(numbers);
    for(const auto& pair : frequencyMap){
        cout << "Frequency of " << pair.first << ": " << pair.second << endl;
    }

    return 0;
}