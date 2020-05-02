//https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/
#include<iostream>
#include <climits>
#include<queue>
using namespace std;
class Tree {
  private: 
    struct Node {
      int data;
      struct Node *left;
      struct Node *right;
    };
    struct Node *root;
    void _treeInOrderTraversal(struct Node *root) {
      if(root == NULL) {
        return;
      }
       
      _treeInOrderTraversal(root->left);
      cout<<"\t"<<root->data;
      _treeInOrderTraversal(root->right);
    }

    int _findMaxSumOfSubTree(struct Node *root, int  *maxSum, bool *isRootAlone) {
      if(root == NULL) {
        return 0;
      }
      int leftSum = _findMaxSumOfSubTree(root->left, maxSum, isRootAlone);
      int rightSum = _findMaxSumOfSubTree(root->right, maxSum, isRootAlone);
      int sum = INT_MIN;
      if(leftSum + rightSum + root->data >=  root->data && *isRootAlone == false) {
        sum = leftSum + rightSum + root->data;
        *isRootAlone = false;
      }
      else
      {
        sum = root->data;
        *isRootAlone = true;
      }
      *maxSum = max(sum, *maxSum);
      cout<<"\nMaxsum  : " <<  *maxSum << "\t Sum : " <<sum;
      return  sum;
    }

  public:
    Tree() {
      root = NULL;
    }

    Node* createNode(int value) {
      struct Node *node = new Node();
      node->data = value;
      node->left = NULL;
      node->right = NULL;
      return node;
    }

    void insertToTree (int data) {
      if(root == NULL) {
        root = new Node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
      }
      else {
        queue <struct Node*> q;
        q.push(root);
        while (!q.empty())
        {
          struct Node *tmp = q.front();
          q.pop();
          if(tmp->left == NULL){
            tmp->left = createNode(data);
            break;
          }
          else {
            q.push(tmp->left);
          }

          if(tmp->right == NULL){
            tmp->right = createNode(data);
            break;
          }
          else {
            q.push(tmp->right);
          }
        }
      }
    }

    void treeInOrderTraversal() {
      cout<<"\n Inorder ";
      _treeInOrderTraversal(root);
      cout<<"\n";
    }

    int findMaxSumOfSubTree(int *maxSum) {
      bool isRootAlone = false;
      _findMaxSumOfSubTree(root, maxSum, &isRootAlone);
      return *maxSum;
    }
};

int main() {
  Tree t;
  int n;
  cout<<"Number of nodes : ";
  cin>>n;
  int node;
  while(n--) {
    cout<<"Node : ";
    cin>>node;
    t.insertToTree(node);
  }
  t.treeInOrderTraversal();
  int maxSum = INT_MIN;
  int result = t.findMaxSumOfSubTree(&maxSum);
  cout<< "Largest Sum of subtree: " << result <<"\ns";
}


// Input :       1
//             /    \
//           -2      3
//           / \    /  \
//          4   5  -6   2
