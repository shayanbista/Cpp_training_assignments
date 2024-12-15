// Two sum
#include <iostream>
#include <vector>
#include <unordered_map> 

class TwoSum{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // unordered_map to store the numbers and their indices
        std::unordered_map<int, int> visitedNumber;

        for (int i=0; i<nums.size(); i++){
            // finding if the element already exists on the map
           int findingElement=target-nums[i];

           if(visitedNumber.find(findingElement)!=visitedNumber.end()){
            // if it exists, return the indices
                return {visitedNumber[findingElement],i};
           }
            // if it doesn't exist push it onto the map
            visitedNumber[nums[i]] = i;    
    }

    return {};

    }

};

int main(){

    TwoSum ts;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = ts.twoSum(nums, target);


    for(auto result : result){
        std::cout<<result<<" "<<std::endl;
    }

    return 0;
} 