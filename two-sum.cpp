#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  
            
            if (mp.count(complement)) { 
                return {mp[complement], i};  
            }

            mp[nums[i]] = i;
        }

        return {};  
    }
};

int main() {
    Solution solution;
    int n, target;

    cout << "Enter no of elements" << endl;
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "target: ";
    cin >> target;

    vector<int> result = solution.twoSum(nums, target);

    if (!result.empty()) {
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}