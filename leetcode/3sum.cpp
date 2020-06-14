//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int i=0, j=0, k=nums.size()-1;
        
        vector<vector<int>> result;
        while(i< nums.size() ){
            j=i+1;
            k=nums.size()-1;
            while(j<k){
                
                if(nums[i] + nums[j]+ nums[k]==0){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    result.push_back(tmp);
                  
                    int temp1 = nums[j];
                    int temp2 = nums[k];
                    while(j < k && nums[j] ==temp1)
                        j++;
                    while(j < k && nums[k] ==temp2 )
                        k--;
                   
                    
                }
                else  if(nums[i] + nums[j]+ nums[k] < 0){
                    j++;
                }
                else if(nums[i] + nums[j]+ nums[k] > 0){
                    k--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
             i++;
            i++;
          
        }
        
        return result;
    }
};