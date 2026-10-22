class Solution 
{
    public:
    int mySqrt(int x) 
    {
        if (x == 0 || x == 1) return x;

        // strategically setting right to be x / 2
        int ans = 1;
        int left = 2, right = x / 2;
        while (left <= right) {
            long long mid = left + (right-left) / 2;

            if (mid * mid <= x) {
                ans = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return ans;
    }
};