#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;

    for (int num : nums) {
        freqMap[num]++;
    }

    vector<int> result;

    while (k--) {
        int maxFreq = 0, maxFreqNum = 0;

        for (auto& [num, freq] : freqMap) {
            if (freq > maxFreq) {
                maxFreq = freq;
                maxFreqNum = num;
            }
        }

        result.push_back(maxFreqNum);
        freqMap.erase(maxFreqNum); 
    }

    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}