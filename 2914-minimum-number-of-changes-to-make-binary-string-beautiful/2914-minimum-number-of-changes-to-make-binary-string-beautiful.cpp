class Solution {
public:
    int minChanges(string s) {

        int change = 0;
        int count = 0;
        char ch;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(count == 0){
                ch = s[i];
                count++;
                continue;
            }
            else if(s[i] == ch){
                count++;
                continue;
            }
            else{
               if(count%2 == 0){
                    count = 1;
                    ch = s[i];
                    continue;
               }
               else{
                change++;
                count = 0;
               }

            }

        }
        return change;
    }
};