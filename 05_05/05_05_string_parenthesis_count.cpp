#include<iostream>
#include<stack>
#include<string>
using namespace std;
int getNoOfBalancedParenthesis(string str) {
  stack<char> s;
  int i = 0;
  int counter = 0;
  int innerLevelCounterTotal = 0;
  while(i < str.length()) {
    if( str[i] == '(') {
      s.push('(');
      i++;
    }
    else if ( str[i] == ')') {
      int innerLevelCounter = -1;
      counter++; 
      while(!s.empty() && i < str.length()) {
        if(str[i] == ')') {
          s.pop();
          innerLevelCounter++;
          i++;
        }
        else {
          i++;
          break;
        }
      }
      innerLevelCounterTotal += innerLevelCounter;
    }
  }
  int totalCount =  (counter * (counter + 1) ) /2;
  totalCount += innerLevelCounterTotal;
  return totalCount;
}

int main() {
  string str;
  cout<<"Enter  the string : ";
  cin>>str;
  // str = "(((((((())))))))";
  int count = getNoOfBalancedParenthesis(str);
  cout<< "\nNo of Count : " << count << "\n";
  return 0;
}