// Problem statement Link
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

// Solution 
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int ans = -1;
        for(int i=0; i<s.length()-1; i++){
            for(int j=s.length()-1; j>i; j--){
                if(s[i] == s[j]){
                    ans = max(j-i-1,ans);
                }
            }
        }
        return ans;
    }
};
