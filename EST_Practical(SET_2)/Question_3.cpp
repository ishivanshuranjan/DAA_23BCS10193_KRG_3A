#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<pair<int, char>> arr;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                arr.push_back({freq[i], (char)(i + 'a')});
            }
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        if (arr[0].first > (n + 1) / 2)
            return "";

        vector<char> result(n);
        int index = 0;

        for (auto &p : arr) {
            int f = p.first;
            char c = p.second;

            while (f > 0) {
                result[index] = c;
                index += 2;
                f--;
                if (index >= n)
                    index = 1;
            }
        }

        return string(result.begin(), result.end());
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << sol.reorganizeString(s) << endl;
    return 0;
}
