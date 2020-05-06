#include<iostream>
using namespace std;

class Heap {
  private:
    int totalHeapSize;
    int currentHeapSize;
    int *heap;
  public:
    Heap (int heapSize) {
      totalHeapSize = heapSize;
      currentHeapSize = -1;
      heap = new int[totalHeapSize];
    }

    int parentOf(int index) {
      return (index-1) /2; 
    }

    int leftOf(int index) {
      return (index * 2) + 1; 
    }

    int rightOf(int index) {
      return (index * 2) + 2; 
    }

    void swap(int idx1, int idx2) {
      int temp = heap[idx1];
      heap[idx1] = heap[idx2];
      heap[idx2] = temp;
    }

    void heapifyToTop(int currentIndex, int parentIndex) {
      if(heap[currentIndex] > heap[parentIndex]){
        swap(currentIndex, parentIndex);
      }
      currentIndex = parentIndex;
      if(currentIndex == 0)
        return;
      heapifyToTop(currentIndex, parentOf(currentIndex));
    }

    
    void heapifyToBottom(int currentIndex) {
      int chosenIndex = currentIndex;
      if(leftOf(currentIndex) < currentHeapSize && heap[currentIndex] < heap[leftOf(currentIndex)]){
        chosenIndex = leftOf(currentIndex);
      }
      if(rightOf(currentIndex) < currentHeapSize && heap[chosenIndex] < heap[rightOf(currentIndex)]){
        chosenIndex = rightOf(currentIndex);
      }
      if(currentIndex == chosenIndex) {
        return;
      }
      swap(currentIndex, chosenIndex);
      currentIndex = chosenIndex;
      heapifyToBottom(currentIndex);
    }


    int insertToHeap(int ele) {
      if(currentHeapSize == totalHeapSize-1) {
        cout << "Overflow";
        return -1;
      }
      currentHeapSize++;
      heap[currentHeapSize] = ele;
      if(currentHeapSize == 0)
        return 0;
      
      heapifyToTop(currentHeapSize, parentOf(currentHeapSize));
      
      return 0;
    }

    void displayHeap() {
      cout<<"\n Heap Elements: ";
      for(int idx = 0; idx < totalHeapSize; idx++) {
        cout<<heap[idx] << "\t";
      }
      cout<<"\n";
    }

    int extractRoot() {
      int root = heap[0];
     
      heap[0] = heap[currentHeapSize];
      cout << "\nExtract Root: " << root; 
      cout<< "\tHeap[0] : " << heap[0] << "\t currentHeapSize : " << currentHeapSize;
      currentHeapSize--;
      heapifyToBottom(0);
      return root;
    }
};

int main () {
  int totalSize;
  cout<<"\nN:";
  std::cin >> totalSize;
  Heap heap(totalSize);
  int idx1 = 0;
  while (idx1 < totalSize)
  {
    int ele;
    cout<<"\nElement:"; 
    cin >> ele;
    heap.insertToHeap(ele);
    // heap.displayHeap();
    idx1++;
  }
  heap.displayHeap();

  int idx2 = 0;
  while(idx2 < totalSize) {
    heap.extractRoot(); 
    idx2++;
  }
  cout<<"\n"; 
  return 0;
}