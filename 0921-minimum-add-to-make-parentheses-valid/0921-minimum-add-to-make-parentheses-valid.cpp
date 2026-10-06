class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int ans = 0;
        for(auto ch : s){
            if(ch == '(') cnt++;
            else{
                if(cnt > 0) cnt--;

                else ans++;
            }
        }

        return ans+cnt;
        
    }
};