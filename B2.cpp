//============================================================================
// Name        : ExpressionTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : construct an expression tree for a prefix Expression in inorder, preorder and postorder traversals
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
//node declaration
class TREE_N  {
   public:
   char d;
   TREE_N *l, *r;
   TREE_N(char d) {
      this->d = d;
      this->l = NULL;
      this->r = NULL;
   }
};
// stack declaration
class StackNod {
   public:
   TREE_N *treeN;
   StackNod *n;
   //constructor
   StackNod(TREE_N *treeN) {
      this->treeN = treeN;
      n = NULL;
   }
};

class ExpressionTree {
   private: StackNod *top;
   public: ExpressionTree() {
      top = NULL;
   }
   void clear() {
      top = NULL;
   }

   void push(TREE_N *ptr) {
      if (top == NULL)
         top = new StackNod(ptr);
      else {
         StackNod *nptr = new StackNod(ptr);
         nptr->n = top;
         top = nptr;
      }
   }

   TREE_N *pop() {
      if (top == NULL) {
         cout<<"Underflow"<<endl;
         return 0;
      }
      else {
    	  TREE_N *ptr = top->treeN;
         top = top->n;
         return ptr;
      }
   }

   TREE_N *peek() {
      return top->treeN;
   }

   void insert(char val) {
      if (isalpha(val)) {
    	  TREE_N *nptr = new TREE_N(val);
         push(nptr);
      } else if (isOperator(val)) {
    	  TREE_N *nptr = new TREE_N(val);
         nptr->l = pop();
         nptr->r= pop();
         push(nptr);
      } else {
         cout<<"Invalid Expression"<<endl;
         return;
      }
   }

  /* bool isDigit(char ch) {
      return ch >= '0' && ch <= '9';
   }*/

   bool isOperator(char ch) {
      return ch == '+' || ch == '-' || ch == '*' || ch == '/';
   }

   int toDigit(char ch) {
      return ch - '0';
   }

   void buildTree(string eqn) {
      for (int i = eqn.length() - 1; i >= 0; i--)
         insert(eqn[i]);
   }

   void postfix() {
      postOrder(peek());
   }

   void postOrder(TREE_N *ptr) {
      if (ptr != NULL) {
         postOrder(ptr->l);
         postOrder(ptr->r);
         cout<<ptr->d;
      }
   }
   void infix() {
      inOrder(peek());
   }

   void inOrder(TREE_N *ptr) {
      if (ptr != NULL) {
         inOrder(ptr->l);
         cout<<ptr->d;
         inOrder(ptr->r);
      }
   }
   void prefix() {
      preOrder(peek());
   }

   void preOrder(TREE_N *ptr) {
      if (ptr != NULL) {
         cout<<ptr->d;
         preOrder(ptr->l);
         preOrder(ptr->r);
      }
   }
};

int main() {
   string s;
   ExpressionTree et;
   cout<<"\nEnter equation in Prefix form: ";
   cin>>s;
   et.buildTree(s);
   cout<<"\nPrefix : ";
   et.prefix();
   cout<<"\n\nInfix : ";
   et.infix();
   cout<<"\n\nPostfix : ";
   et.postfix();
}
