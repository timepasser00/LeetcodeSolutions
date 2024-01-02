// Problem statement link 
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/


// solution 

// TC - O(NLogN)
// SC - O(n**2)

 class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int lastRow = -1;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++){
        
            if(i-1 >= 0 && nums[i] == nums[i-1])
            {
                int row = lastRow + 1;
                if(ans.size() <= row){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    ans.push_back(tmp);
                }else{
                    ans[row].push_back(nums[i]);
                }
                lastRow = row;
            }else
            {
                int row = 0;
                if(ans.size() <= row){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    ans.push_back(tmp);
                }else{
                    ans[row].push_back(nums[i]);
                }
                lastRow = row;
            }
        }
        return ans;
    }
};


// approach 2 - using Map
// TC - O(n)
// SC - O(n**2 + n)

vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }  

        while(!mp.empty()){
            vector<int> temp;
            for(auto it = mp.begin(); it != mp.end(); ){
                temp.push_back(it->first);
                it->second--;
                if(it->second == 0){
                    it = mp.erase(it);
                } else {
                    ++it;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
