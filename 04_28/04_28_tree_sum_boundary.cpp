//https://www.geeksforgeeks.org/sum-of-all-the-boundary-nodes-of-a-binary-tree/
#include <iostream>
#include <climits>
#include <queue>
#include <utility> 
#include <map>
#include <set> 
#include <iterator>
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

    int _sumTreeBottomBoundaryNodes(struct Node *root) {
      if(root == NULL)
        return 0;
      int sum = 0;
      if(root->left == NULL && root->right == NULL)
        sum += root->data;
      return sum + _sumTreeBottomBoundaryNodes(root->left) + _sumTreeBottomBoundaryNodes(root->right);
    }

    int _sumTreeLeftBoundaryNodes() {
      queue <pair <int, struct Node *> > q;
      map <int, int> m;
      q.push(pair <int, struct Node *>(0,root));
      while (!q.empty())
      {
        pair<int, struct Node*> currentPair = q.front();
        int level = currentPair.first;
        struct Node* currentNode = currentPair.second;
        if(m.find(level) == m.end() && currentNode->left != NULL &&  currentNode->right != NULL) {
          m.insert(pair<int, int> (level, currentNode->data));
        }
        q.pop();
       
        if(currentNode->left != NULL) {
          q.push(pair <int, struct Node *>(level + 1, currentNode->left));
        }
        if(currentNode->right != NULL) {
          q.push(pair <int, struct Node *>(level + 1, currentNode->right));
        }
      }
      
      map<int, int>::iterator itr; 
      int sum = 0;
      for( itr = m.begin(); itr != m.end(); itr++) {
        // cout<< "\t" << itr->second;
        sum += itr->second;
      }

      return sum;
    }

     int _sumTreeRightBoundaryNodes() {
      queue <pair <int, struct Node *> > q;
      map <int, int> m;
      q.push(pair <int, struct Node *>(0,root));
      while (!q.empty())
      {
        pair<int, struct Node*> currentPair = q.front();
        int level = currentPair.first;
        struct Node* currentNode = currentPair.second;
        if(currentNode->left != NULL &&  currentNode->right != NULL) {
           m[level] = currentNode->data;
        }
       
        q.pop();
       
        if(currentNode->left != NULL) {
          q.push(pair <int, struct Node *>(level + 1, currentNode->left));
        }
        if(currentNode->right != NULL) {
          q.push(pair <int, struct Node *>(level + 1, currentNode->right));
        }
      }
      
      map<int, int>::iterator itr; 
      int sum = 0;
      for( itr = m.begin(); itr != m.end(); itr++) {
        // As root is already added in left traversal
        if(itr->first != 0){
          // cout<< "\t" << itr->second;
          sum += itr->second;
        }  
      }

      return sum;
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

    int sumTreeBoundary() {
      int bottomNodesSum = _sumTreeBottomBoundaryNodes(root);
      int leftNodesSum = _sumTreeLeftBoundaryNodes();
      int rightNodesSum = _sumTreeRightBoundaryNodes();
      return leftNodesSum + rightNodesSum + bottomNodesSum;
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

  int sum = t.sumTreeBoundary();
  cout<<"Sum of Tree Boundary nodes : " << sum << "\n";
}


// Input :       1
//             /    \
//           -2      3
//           / \    /  \
//          4   5  -6   2