// Problem statement Link
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

// Solution 

// Brute force  
// TC O(n**2) 
// SC O(1)
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


// Using unordered map
// TC O(n)
// SC O(n)

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        unordered_map<char,int> mp;
        int ans = -1;

        for (int i=0; i<s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                ans = max(i-mp[s[i]]-1,ans);
            }else{
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};
