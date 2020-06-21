//https://leetcode.com/problems/trapping-rain-water/submissions/
class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if(length == 0)
            return 0;
        int left[length], right[length];
        int max = 0;
        for(int index = 0; index < length; index++){
            if(max < height[index])
                max = height[index];
           left[index] = max;
        }
        max = 0;
        for(int index = length-1; index >= 0; index--){
            if(max < height[index])
                max = height[index];
            right[index] = max;
        }

        int sum = 0;
        for(int index = 0; index < length; index++){
           sum += min(left[index], right[index]) - height[index];
        }
        return sum;
    }
};