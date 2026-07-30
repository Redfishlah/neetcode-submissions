class KthLargest {
public:
    int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        this -> nums = nums;
    }
    
    int add(int val) {
        nums.push_back(val);
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
