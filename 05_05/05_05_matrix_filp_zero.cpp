//https://www.geeksforgeeks.org/maximize-binary-matrix-filpping-submatrix/
#include<iostream>
using namespace std;

int** populateSumOfZerosInSubMatrix(int **mat, int n, int m) {
  int **zeroCountSum = new int*[n];
  for(int i = 0; i < n; i++) {
    int colsum = 0;
    zeroCountSum[i] = new int[m];
    for(int j =0 ; j < m; j++) {
      zeroCountSum[i][j]= colsum + ((mat[i][j] == 0) ? 1 : 0) + ((i==0) ? 0 : zeroCountSum[i-1][j]);
      colsum +=  ((mat[i][j] == 0) ? 1 : 0);
    }
  }
  return zeroCountSum;
}


int** populateSumOfOnesInSubMatrix(int **mat, int n, int m) {
  int **oneCountSum = new int*[n];
  for(int i = 0; i < n; i++) {
    int colsum = 0;
    oneCountSum[i] = new int[m];
    for(int j =0 ; j < m; j++) {
      oneCountSum[i][j]= colsum + ((mat[i][j] == 1) ? 1 : 0) + ((i==0) ? 0 : oneCountSum[i-1][j]);
      colsum +=  ((mat[i][j] == 1) ? 1 : 0);
    }
  }
  return oneCountSum;
}

int getMaxNoOfOnesByFlipping(int **mat, int **zeroCountMat , int **oneCountMat,  int n, int m, int inputOnesCount) {
  int maxOnesCount = inputOnesCount;
  for(int i =n-1; i >= 0; i--) {

    for(int j=m-1 ; j >=0 ; j--) {

      for(int k =0; k < n || k < m ; k++) {
        int currentOnesCount;
        if(k < n ) {
          currentOnesCount =  zeroCountMat[i][j] - zeroCountMat[k][j] + oneCountMat[k][j];
          if(currentOnesCount > maxOnesCount) {
            maxOnesCount = currentOnesCount;
          }
        }
        if(k < m) {
          currentOnesCount =  zeroCountMat[i][j] - zeroCountMat[i][k] + oneCountMat[i][k];
          if(currentOnesCount > maxOnesCount) {
            maxOnesCount = currentOnesCount;
          }
        }
      }
    }
  }
  return maxOnesCount;
}

void printMatrix(int **mat, int n, int m) {
  for(int i =0; i < n; i++) {
    cout<<"\n";
    for(int j=0 ; j< m; j++) {
      cout<<"\t"<< mat[i][j];
    }
  }
  cout<<"\n";
}

int main() {
  int n,m;
  cout<<"\nEnter N : ";
  cin>>n;
  cout<<"\nEnter M : ";
  cin>>m;
  int **mat = new int*[n];
  int currentOnesCount = 0;
  for(int i =0; i < n; i++) {
    mat[i] = new int[m];
    for(int j=0 ; j< m; j++) {
      cout<<"A["<<i<<"]["<< j<< "] : ";
      cin>>mat[i][j];
      if(mat[i][j] == 0)
        currentOnesCount++;
    }
  }

  int **zeroCountMat = populateSumOfZerosInSubMatrix(mat, n, m);
  int **oneCountMat = populateSumOfOnesInSubMatrix(mat, n, m);
  
  printMatrix(mat, n, m);
  printMatrix(zeroCountMat, n, m);
  printMatrix(oneCountMat, n, m);

  int count = getMaxNoOfOnesByFlipping(mat, zeroCountMat, oneCountMat, n, m, currentOnesCount);
  cout<<"\n Total 1's in flipped matrix : " << count << "\n";
  return 0;
}