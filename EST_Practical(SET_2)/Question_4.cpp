#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) 
                dq.pop_back();

            dq.push_back(i);

            if (dq.front() <= i - k) 
                dq.pop_front();

            if (i >= k - 1) 
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = sol.maxSlidingWindow(nums, k);

    for (int x : ans) cout << x << " ";
    return 0;
}
