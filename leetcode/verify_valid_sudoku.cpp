//https://leetcode.com/problems/valid-sudoku/submissions/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
//         for(int i = 0; i < board.size(); i++ ){
            
//             for(int j = 0; j < board.size(); j++){
//                cout<<board[i][j]<<"\t";
//             }
//             cout<<endl;
//         }
        
        int length = 10;
        int arr[length];
        for(int i = 0; i < board.size(); i++ ){
            
            memset(arr, 0, length * sizeof(int));
            // cout<<endl;
            // for(int x = 0; x < length ; x++ )
            //     cout<<arr[x]<<"\t";
            // cout<<endl;
            for(int j = 0; j < board.size(); j++){
                char val = board[i][j];
                if(val == '.')
                    continue;
                int number = (int)(val-48);
                // cout<<i<< "\t"<< j << "\t"<<number<< "\t"<< arr[number] <<endl;
                if(arr[number] == 1)
                    return false;
                else
                    arr[number] = 1;
            }
            // cout<<endl;
        }
        
        for(int i = 0; i < board.size(); i++ ){
            
            memset(arr, 0, length * sizeof(int));
            // cout<<endl;
            // for(int x = 0; x < length ; x++ )
            //     cout<<arr[x]<<"\t";
            // cout<<endl;
            for(int j = 0; j < board.size(); j++){
                char val = board[j][i];
                if(val == '.')
                    continue;
                int number = (int)(val-48);
                // cout<<j<< "\t"<< i << "\t"<<number<< "\t"<< arr[number] <<endl;
                if(arr[number] == 1)
                    return false;
                else
                    arr[number] = 1;
            }
            // cout<<endl;
        }
        
        // cout<<endl<<endl;
    
        for(int i = 0; i < board.size(); i = i+3 ){
            for(int j = 0; j < board.size(); j = j+3 ){
                memset(arr, 0, length * sizeof(int));
                // for(int k = 0; k < 3; k++ ){
                //     for(int l = 0; l < 3; l++){
                //        cout<<arr2[k][l]<<"\t";
                //     }
                //     cout<<endl;
                // }
                for(int k=i; k < i+3; k++){
                    for(int l=j; l < j+3; l++){
                        char val = board[k][l];
                        // cout<<k<<"\t"<<l<<"\t"<<board[k][l]<<endl;
                        if(val == '.')
                            continue;
                        int number = (int)(val-48);
                         if(arr[number] == 1)
                            return false;
                        else
                            arr[number] = 1;
                    }
                     
                }  
                // cout<<endl;
            }
        }
        
        return true;
    }
};