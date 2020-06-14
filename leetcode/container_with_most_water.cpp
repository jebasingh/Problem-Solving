//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& h) {
        int max_area = 0;
      
        int area = 0;
        int start = 0;
        int end = h.size() -1;
        
        while(start < end) {
            area = (end - start) * (h[start] < h[end] ? h[start] : h[end]);
            if(max_area < area) {
                max_area = area;
            }
            if(h[start] < h[end])
                start++;
            else
                end--;
        }
    
        return max_area;
    }
};