class Solution {
public:
    int t[1001][1501];
    int solve(int idx, vector<vector<int>> &items, int budget,vector<int>&copies){
        if(idx < 0) return budget/items[0][1];

        if(budget <= 0) return 0;
        if(t[idx][budget] != -1) return t[idx][budget];
        int take = 0;
        int nottake = 0;
        
        if(items[idx][1] <= budget){
            take = 1 + copies[idx] + solve(idx-1, items,budget-items[idx][1],copies);
        }
        nottake = solve(idx-1, items, budget,copies);


        return t[idx][budget] =  max(take , nottake);
        


    }
    public:
    static bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        sort(items.begin(), items.end(),comp);
        vector<int> copies(n,0);
        for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;

                if(items[j][0] % items[i][0] == 0) copies[i]++;
            }
        }
        memset(t,-1,sizeof(t));
        return solve(n-1, items , budget , copies);
        
    }
};