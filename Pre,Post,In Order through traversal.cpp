// C++ program to print inorder traversal
// using stack.
#include<bits/stdc++.h>
using namespace std;
  
/* A binary tree Node has data, pointer to left child
   and a pointer to right child */
class Node
{
	public:
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
  
/* Iterative function for preorder tree
   traversal */
void preOrder(Node *root)
{
    //stack<Node *> s;
    stack<Node *> s; 
    Node *curr = root;
  
    while ( curr != NULL || !(s.empty()) )
    {
        while (curr !=  NULL)
        {
            s.push(curr);
			cout << curr->data << " ";
            curr = curr->left;
        }
  
        curr = s.top();
        s.pop();
  
        curr = curr->right;
  
    } 
}


void inOrder(Node *root)
{
    //stack<Node *> s;
    stack<Node *> s; 
    Node *curr = root;
  
    while ( curr != NULL || !(s.empty()) )
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
  
        curr = s.top();
        s.pop();
        
        cout << curr->data << " ";
  
        curr = curr->right;
  
    } 
}


void postOrder(Node *root)
{
    //stack<Node *> s;
    stack<Node *> s; 
    Node *curr = root;
  	int a,b;
    while ( curr != NULL || !(s.empty()) )
    {
        while (curr->left !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
  		cout << curr->data << " ";
  		if(a==b)
  		cout << a << " ";
  		
  		
        curr = s.top();
        b=curr->data;
        a=curr->data;
        s.pop();
        
        //cout << curr->data << " ";
  
        curr = curr->right;
  
    } 
}

int main()
{
  
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
  
    postOrder(root);
    return 0;
}
