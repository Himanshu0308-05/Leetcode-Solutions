class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin() , strs.end());
        int n = strs.size();
        if(n == 0) return "";
        if(n == 1) return strs[0];
        string first = strs[0];
        string last = strs[n-1];
        string ans = "";
        for(int i=0; i< min(first.length() , last.length()); i++){
            if(first[i] != last[i]){
                break;
            }
            else{
                ans = first.substr(0,i+1);
            }
        }   

        return ans;
        
    }
};