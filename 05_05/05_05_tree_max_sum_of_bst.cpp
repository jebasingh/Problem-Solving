//https://www.geeksforgeeks.org/maximum-sub-tree-sum-in-a-binary-tree-such-that-the-sub-tree-is-also-a-bst/
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

    void _sumOfSubBST(struct Node *root, struct Node *prev, int &current_sum, int &max_sum) {
      if(root == NULL) {
        return;
      }
      _sumOfSubBST(root->left, prev, current_sum, max_sum);
      if(prev !=NULL) {
        if(prev->data < root->data) {
          current_sum += root->data;
        }
        else {
          current_sum =  root->data;
        }
        if(max_sum < current_sum) {
          max_sum = current_sum;
        }
      }
      prev = root;
      _sumOfSubBST(root->right, prev, current_sum, max_sum);
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

    void randomInsert() {
      // root = createNode(7);
      // root->left = createNode(12);
      // root->right = createNode(2);
      // root->left->left = createNode(11);
      // root->left->right = createNode(13);
      // root->left->left->left = createNode(2);
      // root->right->right = createNode(5);
      // root->right->right->left = createNode(1);
      // root->right->right->right = createNode(38);

      root = createNode(5);
      root->left = createNode(9);
      root->right = createNode(2);
      root->left->left = createNode(6);

      root->left->left->left = createNode(8);
      root->left->left->right = createNode(8);

      root->right->right = createNode(3);

    }

    void treeInOrderTraversal() {
      cout<<"\n Inorder ";
      _treeInOrderTraversal(root);
      cout<<"\n";
    }

    void sumOfSubBST(int &max_sum) {
      struct Node *prev = NULL;
      int currentSum = 0;
      _sumOfSubBST(root, prev, currentSum, max_sum);
      cout<<"\nMax Sum : "<< max_sum << "\n";
    }
};

int main() {
  Tree t;
  // int n;
  // cout<<"Number of nodes : ";
  // cin>>n;
  // int node;
  // while(n--) {
  //   cout<<"Node : ";
  //   cin>>node;
  //   t.insertToTree(node);
  // }
  t.randomInsert();
  t.treeInOrderTraversal();
  int max_sum = 0;
  t.sumOfSubBST(max_sum);
  return 0;
}

