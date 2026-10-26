#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std ;

vector<int> twoSumBruteForce(const vector<int>& nums, int target){
    for(int i=0; i < nums.size(); i++){
        for(int j=i; j < nums.size() ; j++){
            if(nums[i] + nums[j] == target){
                return {i,j} ;
            }
        }   
    }
    return {-1,-1} ;
}

vector<int> twoSumOptimal(const vector<int>& nums, int target){
    unordered_map<int,int> tab = {} ;
    for(int i=0; i < nums.size(); i++){
        int key = target - nums[i];
        if(tab.contains(key)){
            return {tab[key], i};
        }
        tab[nums[i]] = i ;
    }
    return {-1,-1} ;
}

int main(){
    vector<int> nums = {2,7,15} ;
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution : ["
    << indicesBruteForce[0]
    << ", "
    << indicesBruteForce[1]
    << "]"
    <<endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution : ["
    << indicesOptimal[0]
    << ", "
    << indicesOptimal[1]
    << "]"
    <<endl;

    return 0 ;
}