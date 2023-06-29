#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;


std::string getString(std::string input_str) {
    int n = input_str.length();
    std::unordered_map<char, int> count;
    std::string result;

    // Count the occurrences of each character
    for (int i = 0; i < n; i++) {
        count[input_str[i]]++;
    }

    // Iterate through the characters in order
    for (int i = 0; i < n; i++) {
        char ch = input_str[i];

        // Append the character to the result if it occurs more than once
        if (count[ch] > 1) {
            result.push_back(ch);
            count[ch] = 0;  // Mark the occurrence as deleted
        }
    }

    return result;
}

int main() {
    std::string input_str;
    std::cin >> input_str;

    std::string result = getString(input_str);
    std::cout << result << std::endl;

    return 0;
}






