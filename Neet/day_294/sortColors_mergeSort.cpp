class Solution
{
    public:
    void sortColors(vector<int>& nums)
    {
        nums = mergeSort(nums);
    }

    private:
    vector<int> mergeSort(vector<int> nums)
    {
        if (nums.empty()) return nums;
        int n = nums.size();
        int mid = n / 2;
        vector<int> left = mergeSort( vector<int>(nums.begin() + nums.begin()+mid) );
        vector<int> right = mergeSort( vector<int>(nums.begin()+mid, nums.end()) );
        return merge(left, right);
    }

    vector<int> merge(vector<int>& left, vector<int>& right)
    {
        vector<int> res;
        int i = 0, j = 0;

        while (i < (int)left.size() && j < (int)right.size()) {
            if (left[i] <= right[j]) {
                res.push_back(left[i++]);
            } else {
                res.push_back(right[j++]);
            }
        }
        while (i < (int)left.size()) res.push_back(left[i++]);
        while (j < (int)right.size()) res.push_back(right[j++]);
        return res;
    }
};
