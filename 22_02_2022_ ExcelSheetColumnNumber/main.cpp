//
//  main.cpp
//  AlgorithmADay
//
//  Created by josipmaric on 22.02.2022..
//

int titleToNumber(string columnTitle) {
    int number = 0;
    for (int i = 0; i < columnTitle.size(); i++) {
        int currentLetter = (int) columnTitle[i] - 64;
        number = number * 26 + currentLetter;
    }
    return number;
}
