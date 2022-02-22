//
//  main.cpp
//  AlgorithmADay
//
//  Created by josipmaric on 20.02.2022..
//

#include <iostream>
#include <vector>

int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [ ]( const auto& lhs, const auto& rhs ) {
        if (lhs[0] == rhs[0]) {
            return lhs[1] > rhs[1];
        }
        return lhs[0] < rhs[0];
    });

    int uncontained_number = 0;

    for(int i = intervals.size() - 1; i > 0; i--) {
        bool contained = false;
        for(int j = i-1; j >= 0; j--) {
            if(intervals[j][1] >= intervals[i][1]) {
                contained = true;
                break;
            }
        }
        uncontained_number += (contained ? 0 : 1);
    }
    return uncontained_number + 1;
}

int main(int argc, const char * argv[]) {

    // Create interval [[1,4],[3,6],[2,8]]
    std::vector<std::vector<int>> intervals;

    std::vector<int> interval1;
    interval1.push_back(1);
    interval1.push_back(4);
    intervals.push_back(interval1);

    std::vector<int> interval2;
    interval2.push_back(3);
    interval2.push_back(6);
    intervals.push_back(interval2);

    std::vector<int> interval3;
    interval3.push_back(2);
    interval3.push_back(8);
    intervals.push_back(interval3);

    std::cout << removeCoveredIntervals(intervals) << std::endl;

    return 0;
}
