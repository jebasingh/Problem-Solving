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
}

