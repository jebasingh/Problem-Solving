//https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string str) {
        int isNegative = false;
        int isPositive = false;
        int continuousSymbols = false;
        int symbol1index = -1;
        int symbol2index = -1;
        long long int integer = 0;
        int notValid = false;
        int metNumericalValue = false;
        int metNumbers = false;
        int reachedMax = false;
        int noMoreNumbers = false;


        for(int idx = 0; idx < str.length(); idx++) {
            if(str[idx] == '-'){

                if(symbol1index == -1){
                    symbol1index = idx;
                }
                else if(symbol1index +1 == idx){
                    if(integer > 0)
                        return integer;
                    return 0;
                }
                metNumericalValue = true;
                if(metNumbers == false)
                    isNegative = true;
                if(metNumbers == true)
                    noMoreNumbers = true;
            } 
            else if(str[idx] == '+'){
                if(symbol1index == -1){
                    symbol1index = idx;
                }
                else if(symbol1index +1 == idx){
                    if(integer > 0)
                        return integer;
                    return 0;
                }
                metNumericalValue = true;
                isPositive = true;
                if(metNumbers == true)
                    noMoreNumbers = true;
            }
            else if(str[idx] >= 48 && str[idx] <= 57){
                 if(noMoreNumbers == true){
                    break;
                }
                if(((integer * 10) + (str[idx] - 48)) > INT_MAX){
                    reachedMax = true;
                    break;
                }
                integer = (integer * 10) + (str[idx] - 48); 
                metNumericalValue = true;
                metNumbers = true;
               
                    
            } 
            else if(str[idx] == ' '){
                if(metNumericalValue == true)
                    break;
                else
                    continue;
            }
            else if(metNumericalValue == false){
                notValid = true;
            }
            else if(metNumericalValue == true) {
                break;
            }
            
        }
        if(continuousSymbols == true) {
            notValid = true;
        }
        if(notValid == true)
            return 0;
        
        if(isNegative == true){
            if(reachedMax == true)
                return INT_MIN;
            return -integer;
        }
        if(reachedMax == true) {
            return INT_MAX; 
        }    
        return integer;
    }
};