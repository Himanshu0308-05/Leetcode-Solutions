class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long mid = s + (e-s)/2;
        long long ans;
        while(s <= e){
            long long val = mid * mid;
            if(val == x) 
                return mid;

            else if(val < x){
                ans = mid;
                s = mid+1;

            }
            else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
        
    }
};