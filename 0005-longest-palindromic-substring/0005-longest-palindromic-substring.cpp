class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int start;
        for(int i=0; i<n; i++){
            int l = i , r= i;

            while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    start =l;
                }
                l--,r++;
            }
            l = i, r = i+1;
              while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    start =l;
                }
                l--,r++;
            }


        }

        return s.substr(start,maxLen);
        
    }
};