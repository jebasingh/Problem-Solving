//https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        // for(int i =0 ; i < nums.size() ; i++) {
        //     cout<< "\t" << nums[i] ;
        // }
        cout<<endl;
        int i=0, j=0, k=nums.size()-1;
        
        int abs_final_min = INT_MAX;
        int sum ;
        int final_sum;
        int completed = false;
        while(i< nums.size() ){
            j=i+1;
            k=nums.size()-1;
            while(j<k){
                // cout<<endl << nums[i] ;
                //  cout<<endl << nums[j]  << '\t' << j;
                //  cout<<endl << nums[k] << '\t' << k;

                int local_min = target - (nums[i] + nums[j]+ nums[k]);
                 int abs_local_min = local_min < 0 ? -local_min : local_min;
                 sum = nums[i] + nums[j]+ nums[k];
               
                if(abs_local_min  == 0){
                    
                    final_sum = sum;
                    abs_final_min = abs_local_min;
                  
                    completed = true;
                    break;
                }
                else  if( abs_local_min < abs_final_min) {
                    abs_final_min = abs_local_min;
                    final_sum = sum;
                    
                }
                if(local_min >=0){
                    j++;
                }
                else {
                    k--;
                }
                 // cout<<endl << "\t " << target << "\t" << abs_local_min  << "\t"<< abs_final_min <<  "\t" << sum  << "\t"<< final_sum ;
            }
            if(completed){
                break;
            }
            i++;
          
        }

        
        return final_sum;
    }
    
};

