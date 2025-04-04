#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
            
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = solution.longestConsecutive(nums);
    cout << "Length of longest consecutive sequence: " << result << endl;

    return 0;
}