// // class Solution {
// // public:
// //     bool solve(vector<int>& nums, int index, int prev_element, int count) {

// //         if (count == 3) {
// //             return true;
// //         }

// //         if (index >= nums.size()) {
// //             return false;
// //         }

// //         bool take = false;
// //         bool notake = false;

// //         if (prev_element == -1 || (count == 1 && nums[index] > prev_element)
// //         ||
// //             (count == 2 && nums[index] < prev_element)) {

// //             take = solve(nums, index + 1, nums[index], count + 1);
// //         }

// //         notake = solve(nums, index + 1, prev_element, count);

// //         return take || notake;
// //     }
// //     bool find132pattern(vector<int>& nums) { return solve(nums, 0, -1, 0); }
// // };

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         vector<int> nextGreater(nums.size(), -1);
//         vector<int> nextSmaller(nums.size(), -1);

//         stack<int> s;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             while (!s.empty() && nums[s.top()] < nums[i]) {
//                 nextGreater[s.top()] = i;
//                 s.pop();
//             }

//             s.push(i);
//         }

//         for (int i = 0; i < n; i++) {
//             while (!s.empty() && nums[s.top()] > nums[i]) {
//                 nextSmaller[s.top()] = i;
//                 s.pop();
//             }

//             s.push(i);
//         }

//         for (int i = 0; i < n; i++) {
//             // next greater index of nums[i]
//             int next_index = nextGreater[i];
//             if (next_index != -1) {
//                 continue;
//             }

//             if (nextSmaller[next_index] != -1) {
//                 return true;
//             }
//         }

//         return false;

        
//     }
// };

// above two soln is not the right solution and will fail on submision , 

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int second = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < second) {
                return true;
            }

            while (!s.empty() && nums[i] > s.top()) {
                second = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};
