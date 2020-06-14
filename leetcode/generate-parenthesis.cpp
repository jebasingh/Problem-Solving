//https://leetcode.com/problems/generate-parentheses/submissions/
class Solution {
public:
    void recursion(int n, vector<string> &result, deque<char> q, int& open, int& close) {
        if(n == close && n == open){
            deque<char> t = q;
            string temp ;
            while(!t.empty()) {
                char val = t.back();
                temp.push_back(val);
                // cout<<val;
                t.pop_back();
            }
            // cout<<temp;
            result.push_back(temp);
            cout<<endl;
        }
        if(open <= n){
            q.push_front('(');
            open++;
            recursion(n, result, q, open, close);
            open--;
            q.pop_front();
            
        } 
        if(close <= n && close < open) {
            if(open== close)
                cout<<open<<"\t"<<close <<endl;
            q.push_front(')');
            close++;
            recursion(n, result, q, open, close);
            close--;
            q.pop_front();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        deque<char> q;
        int open = 0, close = 0;
        recursion(n, result, q, open, close);
        return result;
    }
};