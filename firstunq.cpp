#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "string: ";
    cin >> s;

    int result = solution.firstUniqChar(s);
    cout << "ans: "<< result << endl;

    return 0;
}