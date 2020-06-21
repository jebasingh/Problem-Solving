//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int binarysearch(vector<int>& nums, int start, int end, int target){
        if(start == end){
            if (target == nums[start])
                return start;
            else
                return -1;
        }
       
        if(start < end) {
            int mid = (start + end +1)/2;
            // cout<<   nums[start]  << "\t" << nums[mid] << "\t"<<nums[end] <<endl;
            // cout<<   start  << "\t" << mid << "\t"<< end <<endl;
            if(target == nums[mid])
                return mid;
            if(target < nums[mid] && target >= nums[start]) {
               return binarysearch(nums, start, mid-1, target);
            }
            else if(target < nums[mid] && target <= nums[start] && nums[start] < nums[mid] ){
                 return binarysearch(nums, mid+1, end, target);
             }
            else if(target < nums[mid] && target <= nums[start] && nums[start] > nums[mid] ){
                 return binarysearch(nums, start, mid-1, target);
             }
            else if(target > nums[mid] && target <= nums[end] )
                return binarysearch(nums, mid+1, end, target); 
            else if(target > nums[mid] && target >= nums[end] && nums[end] >= nums[mid] )
                return binarysearch(nums, start, mid-1, target); 
            else if(target > nums[mid] && target >= nums[end] && nums[end] < nums[mid] )
                return binarysearch(nums, mid+1, end, target); 
        }
       
        return -1;
    }
    int search(vector<int>& nums, int target) {
       return binarysearch(nums, 0, nums.size()-1, target);
    }
};