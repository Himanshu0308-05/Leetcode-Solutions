class Solution {
public:
    void solve(string &digits , vector<string> &ans, const string keypads[10], string &output, int idx){
        if(idx == digits.length()){
            ans.push_back(output);
            return;
        }
        int val = digits[idx] - '0';
        string s = keypads[val];
        for(int i=0; i<(int)s.length(); i++){
            output.push_back(s[i]);
            solve(digits,ans,keypads,output,idx+1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string keypads[10] = {"", "", "abc", "def", "ghi" , "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        string output;
        vector<string> ans;
        solve(digits,ans,keypads,output,0);

        return ans;
        
    }
};