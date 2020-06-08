//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_count = 0;
        int start = 0;
        int count = 0;
        map<char, int> m; 
        for(int idx = 0; idx < s.length(); idx++) {
            auto itr = m.find(s[idx]);
            if(itr == m.end()) {
                m.insert({s[idx], idx});
                count++;
                if(max_count < count)
                    max_count = count;
            }
            else {
                if(start < itr->second) {
                    start = itr->second;
                }
                count = idx - start;
               
                m.erase(s[idx]);
                m.insert({s[idx], idx });
                if(max_count < count)
                    max_count = count;
    
            }
            
        }
        return max_count;
    }
};