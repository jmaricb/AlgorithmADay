//
//  main.cpp
//  AlgorithmADay
//
//  Created by josipmaric on 21.02.2022..
//

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> occurences;

    if(nums.size() == 1) {
        return nums[0];
    }

    for(int i = 0; i < nums.size(); i++) {
        auto it = occurences.find(nums[i]);
        if (it == occurences.end() ) {
            occurences.insert ( std::pair<int,int>(nums[i], 1) );
        } else {
            it->second += 1;
            if(it->second > nums.size()/2) {
                return nums[i];
            }
        }
    }

    return 0;
}
