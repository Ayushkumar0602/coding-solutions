class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        //     //    2,-1,2
        //     //    2,1,3

        //     //    -5 2 2 3 4 -8
        //     //    -5,-3,-1, 2, 6,-2.   -2-(-1)=-1

        //     //    -5 2 2 3 4 -8

        //     vector<int> PrefixSum(nums.size(), 0);
        //     int a = 0;
        //     for (int i = 0; i < nums.size(); i++) {
        //         PrefixSum[i] = a + nums[i];
        //         a = PrefixSum[i];
        //     }

        //     int st = 0;
        //     int end = 0;
        //     int n = nums.size();
        //     int min_size = 0;

        //     while (end < n) {
        //         int subarray_sum = 0;
        //         if (st > 0) {
        //             subarray_sum = PrefixSum[end] - PrefixSum[st - 1];
        //         } else {
        //             subarray_sum = PrefixSum[end];
        //         }

        //         min_size = min(min_size, st - end +1);

        //         if (subarray_sum < k) {
        //             end++;
        //         } else {
        //             st++;
        //         }
        //     }
        //     return min_size;
        // }

        int n = nums.size();

        vector<long long> prefixSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq;
        int min_size = n + 1;

        for (int end = 0; end <= n; end++) {

            // Find valid subarrays
            while (!dq.empty() && prefixSum[end] - prefixSum[dq.front()] >= k) {
                min_size = min(min_size, end - dq.front());
                dq.pop_front();
            }

            // Maintain increasing prefix sums
            while (!dq.empty() && prefixSum[end] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(end);
        }

        return min_size == n + 1 ? -1 : min_size;
    }
};