//https://www.geeksforgeeks.org/ways-to-arrange-balls-such-that-adjacent-balls-are-of-different-types/
#include<iostream>
#include<stack>
using namespace std;
void countNumberOfPossibility(int p, int q, int r, int totalLength, stack<char> s, int currentIdx, int &counter) {
  if(totalLength == currentIdx) {
    counter++;
    cout<< "\n Counter : "  << counter << "\t String : ";
    while(s.size() > 0) {
      cout<<s.top();
      s.pop();
    }
  }
  else {
    if((s.empty() ||s.top() != 'P') && p > 0) {
      s.push('P');
      currentIdx++;
      p--;
      countNumberOfPossibility(p, q, r, totalLength, s, currentIdx, counter);
      s.pop();
      currentIdx--;
      p++;
    }
    if((s.empty() ||s.top() != 'Q') && q > 0) {
      s.push('Q');
      currentIdx++;
      q--;
      countNumberOfPossibility(p, q, r, totalLength, s, currentIdx, counter);
      s.pop();
      currentIdx--;
      q++;
    }
    if((s.empty() ||s.top() != 'R') && r > 0) {
      s.push('R');
      currentIdx++;
      r--;
      countNumberOfPossibility(p, q, r, totalLength, s, currentIdx, counter);
      s.pop();
      currentIdx--;
      r++;
    }
  }
}

int main() {
  int p, q, r;
  cout<<"\nP : ";
  cin>>p;
  cout<<"\nQ : ";
  cin>>q;
  cout<<"\nR : ";
  cin>>r;
  // p =2;
  // q=1;
  // r=1;
  int counter = 0;
  int totalLength = p + q + r;
  int currentIdx = 0;
  stack<char> s;
  countNumberOfPossibility(p, q, r, totalLength, s, currentIdx, counter);
  cout<<"\nNo of Ways to arrange Balls with given constrain : " << counter << "\n";


  return 0;
}