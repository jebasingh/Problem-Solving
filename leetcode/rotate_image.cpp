//https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //   for (int idx1 = 0; idx1 < matrix.size(); idx1++){
        //     for(int idx2 = 0; idx2 < matrix[idx1].size() ; idx2++){
        //         cout<<matrix[idx1][idx2] << "\t";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for (int idx1 = 0; idx1 < matrix.size(); idx1++){
            for(int idx2 = 0; idx2 < matrix[idx1].size()/2 ; idx2++){
                int idx3 = matrix[idx1].size() - idx2 -1;
                int swap = matrix[idx1][idx2];
                matrix[idx1][idx2] = matrix[idx1][idx3];
                matrix[idx1][idx3] = swap;
            }
        }
        
        // for (int idx1 = 0; idx1 < matrix.size(); idx1++){
        //     for(int idx2 = 0; idx2 < matrix[idx1].size() ; idx2++){
        //         cout<<matrix[idx1][idx2] << "\t";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // int halflength = matrix.size()/2  ;
        int length = matrix.size()-1  ;
        // if(length%2 == 0)
        //     length +=1;
        for (int idx1 = 0; idx1 <= length; idx1++){
            for(int idx2 = 0; idx2 <= length- idx1; idx2++){
                // cout<<matrix[length -idx2][length - idx1]<< "\t" <<  matrix[idx1][idx2] << "\t";
                int swap = matrix[idx1][idx2];
                matrix[idx1][idx2] = matrix[length -idx2] [length - idx1];
                matrix[length -idx2][length - idx1]= swap;
                // cout<< matrix[length -idx2][length - idx1]<< "\t" <<  matrix[idx1][idx2] << endl;
            }
        }
        
//          cout<<endl;
//          cout<<endl;
//         for (int idx1 = 0; idx1 < matrix.size(); idx1++){
//             for(int idx2 = 0; idx2 < matrix[idx1].size() ; idx2++){
//                 cout<<matrix[idx1][idx2] << "\t";
//             }
//             cout<<endl;
//         }
        
        
    }
};