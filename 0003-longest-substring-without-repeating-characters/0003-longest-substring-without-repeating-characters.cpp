class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans = 0;
        int l;
        for(int r = 0; r < s.length(); r++){

            while(st.find(s[r]) != st.end() ){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans = max(ans , r-l+1);
        }

        return ans;
        
    }
};