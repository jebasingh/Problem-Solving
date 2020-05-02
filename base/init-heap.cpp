#include<iostream>
using namespace std;

int parentOf(int i) {
  return (i-1) /2; 
}


void swap(int *a, int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void heapify(int *a, int i, int parent) {
  if(a[i] > a[parent]){
    swap(a, i, parent);
  }
  i = parent;
  if(i==0)
    return;
  heapify(a, i, parentOf(i));
}

void  insertToHeap(int *a, int i, int x, int heap_max) {
  if(i == heap_max) {
    cout<< "OVERFLOW";
    return ;
  }
  a[i] = x;
  if(i == 0)
    return;
  heapify(a, i, parentOf(i));
}


int main () {
  int n;
  cout<<"\nN:";
  std::cin >> n ;
  int a[n];
  int  i = 0;
  while (i < n)
  {
    int x;
    cout<<"\nElement:";
    cin >> x;
    insertToHeap(a, i, x, n);
    i++;
  }

  cout<<"\nInserted Elements:  ";
  for(int idx = 0; idx < sizeof(a)/ sizeof(a[0]); idx++) {
    cout<<a[idx] << "\t";
  }
  cout<<"\n";


  
  return 0;
}