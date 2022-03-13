//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<math.h>
using namespace std;

struct Bstnode
{
 int data;
 Bstnode *left;
 Bstnode *right;

};

class Btree
{

  int n;
  int x;
  int flag;

public:
  Bstnode * root;
 Btree()
 {
  root = NULL;
 }

 Bstnode *GetNewNode(int in_data)
 {
  Bstnode * ptr = new Bstnode();
  ptr->data = in_data;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
 }

 Bstnode *insert( Bstnode *temp , int in_data)
 {
  if( temp == NULL )
  {
   temp = GetNewNode(in_data);
  }
  else if( temp->data > in_data)
  {
   temp->left = insert(temp->left , in_data);
  }
  else
  {
   temp->right = insert( temp->right , in_data);
  }
  return temp;
 }

 void input()
 {
  cout<<"ENTER NUMBER OF ELEMENTS IN THE BST : ";
  cin>>n;
  for(int i = 0 ; i < n ; i++)
  {
   cout<<"Element = ";
   cin>>x;
   root = insert(root , x);
  }
 }

 void search(Bstnode* root, int key, Bstnode* parent)
 {
     // if the key is not present in the key
     if (root == NULL)
     {
         cout << "Key not found";
         return;
     }

     // if the key is found
     if (root->data == key)
     {
         if (parent == NULL) {
             cout << "The node with key " << key << " is root node"<<endl;
         }
         else if (key < parent->data)
         {
             cout << "The given key is the left node of the node with key"<< parent->data<<endl;
         }
         else  {
             cout << "The given key is the right node of the node with key "
                  << parent->data<<endl;
         }

         return;
     }
     if (key < root->data) {
             search(root->left, key, root);
         } else {
             search(root->right, key, root);
         }
 }


 void minvalue(Bstnode *temp)
 {
  while(temp->left != NULL)
  {
   temp = temp->left;
  }
  cout<<"MINIMUM VALUE = "<<temp->data<<endl;
 }
 void printTree(Bstnode* node) {
    if (node == NULL) {
       return;
    }
    printTree(node->left);
    cout << node->data << " ";
    printTree(node->right);
 }
 void convertTreeToItsMirror(Bstnode* node) {
    if (node == NULL) {
       return;
    }
    else {
       Bstnode* temp;
       convertTreeToItsMirror(node->left);
       convertTreeToItsMirror(node->right);
       temp = node->left;
       node->left = node->right;
       node->right = temp;
    }
 }

 void display()
 {
  cout<<endl<<"--- INORDER TRAVERSAL ---"<<endl;
  inorder(root);
  cout<<endl;
  cout<<endl<<"--- POSTORDER TRAVERSAL ---"<<endl;
  postorder(root);
  cout<<endl;
  cout<<endl<<"--- PREORDER TRAVERSAL ---"<<endl;
  preorder(root);
  cout<<endl;

 }

 void inorder(Bstnode *temp)
 {
  if(temp != NULL)
  {
   inorder(temp->left);
   cout<<temp->data<<"  ";
   inorder(temp->right);
  }
 }

 void postorder(Bstnode *temp)
 {
  if(temp != NULL)
  {
   postorder(temp->left);
   postorder(temp->right);
   cout<<temp->data<<" ";
  }
 }

 void preorder(Bstnode *temp)
 {
  if(temp != NULL)
  {
   cout<<temp->data<<" ";
   preorder(temp->left);
   preorder(temp->right);
  }
 }

 int depth(Bstnode *temp)
 {
  if(temp == NULL)
   return 0;
  return (max((depth(temp->left)),(depth(temp->right))) +1);
 }
};

int main()
{
 Btree obj;
 int ch;
 char ans;
 do
 {
	 cout<<"1) Insert new node"
			 "2)Search a value "
			 "3)Minimum data value found in the tree "
			 "4)Change a tree so that the roles of the left and right pointers are swapped at every node"
			 "5)Find number of nodes in longest path from root"<<endl;
	 cin>>ch;
	 switch(ch){
	 case 1:obj.input();obj.display();break;
	 case 2:obj.search(obj.root, 5, NULL);break;
	 case 3:obj.minvalue(obj.root);break;
	 case 4:cout<<"Mirror of the tree"<<endl;
	        obj.convertTreeToItsMirror(obj.root);
	        obj.printTree(obj.root);break;
	 case 5:cout<<"\n"<<"Depth of the tree"<<endl;
			cout<<obj.depth(obj.root)<<endl;break;
	 }
	 cout<<"\nDo you want to continue : (Y/N)"<<endl;
	 cin>>ans;
 }while (ans=='Y'||ans=='y');
 return 0;
}

