class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //withdivision approch


        // vector<int>ans(nums.size(),1);
        // int n=nums.size();
        // int product=1;
        // for(int i=0;i<n;i++){
        //     product=product*nums[i];
        // }

        // for(int i=0;i<n;i++){
        //     ans[i]=product/nums[i];  //error because we have to make it without using division
        // }

        // return ans;

        


        //without caring about space complexicity 

        vector<int>ans(nums.size(),1);
        vector<int>prefix(nums.size(),1);
        vector<int>suffix(nums.size(),1);
        int n=nums.size();
        
        //loop for finding the array of prefix 
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }


         //loop for finding the array of srefix 
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }

        //multiplying  both prefix and suffix

        
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }

        return ans;








    }
};