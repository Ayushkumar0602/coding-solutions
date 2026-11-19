class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmallestIndex(n);
        vector<int> rightSmallestIndex(n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                rightSmallestIndex[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty()) {
            rightSmallestIndex[s.top()] = n;
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                leftSmallestIndex[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty()) {
            leftSmallestIndex[s.top()] = -1;
            s.pop();
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, abs(heights[i] * (rightSmallestIndex[i] -
                                             leftSmallestIndex[i] - 1)));
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row= matrix.size();
        int col = matrix[0].size();

        int ans =0;
        vector<int>height(col,0);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }

                else{
                    height[j]+=1;
                }
            }

            ans=max(ans,largestRectangleArea(height));
        }

        return ans ;
    }
};