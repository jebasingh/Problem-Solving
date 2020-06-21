//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
class Solution {
public:
    int recursion(vector<int>& nums, int left, int right, int target, bool isStart) {
        if(left > right)
            return -1;
        int mid = (left + right )/2;
        if(nums[mid] > target )
            return recursion(nums, left, mid-1, target, isStart);
        if(nums[mid] < target )
            return recursion(nums, mid+1, right, target, isStart);
        if(isStart && nums[mid] == target) {
            if(mid == 0)
                return mid;
            else if(nums[mid -1 ] != target )
                return mid;
            else
                return recursion(nums, left, mid-1, target, isStart);
        }
        if(!isStart && nums[mid] == target) {
            if(mid == right)
                return mid;
            else if(nums[mid + 1 ] != target )
                return mid;
            else
                return recursion(nums, mid+1, right, target, isStart);
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = recursion(nums, 0, nums.size()-1, target, true);
        int right = recursion(nums, 0, nums.size()-1, target, false);
        vector<int> a;
        a.push_back(left);
        a.push_back(right);
        return a;
    }
};