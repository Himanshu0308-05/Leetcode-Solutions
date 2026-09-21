class Solution {
public:
    string longestPalindrome(string s) {
        string ans = s.substr(0, 1);
        int maxi = 1;
        int n = s.length();

        for(int i = 0; i < n; i++) {

            
            int prev = i - 1;
            int next = i + 1;

            while((prev >= 0 && next < n) && 
                  (s[prev] == s[next])) {

                prev--;
                next++;

                int len = next - prev - 1;

                if(len > maxi) {
                    maxi = len;
                    ans = s.substr(prev + 1, len);
                }
            }

            
            prev = i;
            next = i + 1;

            while((prev >= 0 && next < n) && 
                  (s[prev] == s[next])) {

                prev--;
                next++;

                int len = next - prev - 1;

                if(len > maxi) {
                    maxi = len;
                    ans = s.substr(prev + 1, len);
                }
            }
        }

        return ans;
    }
};