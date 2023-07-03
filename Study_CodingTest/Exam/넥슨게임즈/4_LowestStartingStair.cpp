/*
4. Lowest Starting Stair

A grasshopper is jumping on a long staircase, on which each stair is numbered; 
the bottommost stair being 1, the next stair being 2, and so on. 
In one jump, it can go some steps up or down. 
Given an array jumps of integers representing each jump of the grasshopper as:

• If jumps[i] > 0, the grasshopper jumps jumps[i] steps up from its current step.
• If jumps[i] < 0, the grasshopper jumps | jumps[i] | steps down from its current step.

Find the number of the lowest stair, 
startingStair on which the grasshopper should start so that it can remain on the staircase;
that is, the stair number remains >= 1.

Example
jumps = [1, -4, -2, 3].

If startingStair= 6, the following results are obtained:

Stair			jumps[i]
----------------------
6					1
7					-4
3					-2
1					3
4

For startingStair = 6, the stair number remains >=1 throughout the jumps. This is the least possible value of
startingStair for the condition to be true. Therefore, the answer is 6.


Function Description
Complete the function findLowestStartingStair in the editor below.

findLowestStartingStair has the following parameter:
int jumps[n]: an array of integers

Returns
	int: the minimum integer value for startingStair.

Constraints
	•	1 ≤ n ≤ 100000
	•	-100 ≤ jumps[i] ≤ 100

Input Format for Custom Testing
Input from stdin will be processed as follows and passed to the function.
The first line contains an integer n, the size of the array jumps.
Each of the next n lines contains an integer jumps[i]


Sample Case 0
Sample Input
STDTN 				Function
--------------------------
10			->			jumps[i] size n = 10
-5			->			jumps = [-5, 4, -2, 3, 1, -1, -6, -1, 0, 5]
4
-2
3
1
-1
-6
-1
0
5

Sample Output 0
8

Explanation
Stair				jumps[i]
------------------------------
8					-5
3					4
7					-2
5					3
8					1
9					-1
8					-6
2					-1
1					0
1					5
6

The minimum value of startingStair is 8 as for values less than 8, the stair number becomes < 1.
*/

/*
*  잘못 적은 코드
#include <iostream>
#include <vector>
using namespace std;

int findLowestStartingStair(vector<int> jumps) {
    int lowestStair = INT_MAX;
    int currentStair = 0;

    for (int i = 0; i < jumps.size(); i++) {
        currentStair += jumps[i];

        if (currentStair < lowestStair) {
            lowestStair = currentStair;
        }
    }

    return abs(lowestStair) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> jumps(n);

    for (int i = 0; i < n; i++) {
        cin >> jumps[i];
    }

    int result = findLowestStartingStair(jumps);
    cout << result << endl;

    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

int findLowestStartingStair(vector<int> jumps) {
    int minStair = 1;
    int currentStair = 1;
    for (int jump : jumps) {
        currentStair += jump;
        if (currentStair < 1) {
            minStair += 1 - currentStair;
            currentStair = 1;
        }
    }
    return minStair;
}

int main() {
    int n;
    cin >> n;
    vector<int> jumps(n);
    for (int i = 0; i < n; i++) {
        cin >> jumps[i];
    }
    cout << findLowestStartingStair(jumps) << endl;
    return 0;
}













