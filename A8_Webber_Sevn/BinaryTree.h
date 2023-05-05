#include "BinaryNode.h"
using namespace std;

template <class T>
class BinaryTree
{
public:
   BinaryTree();
   bool empty() const;
   void preorder(void (*visit)(T &)); // function pointer
   void inorder(void (*visit)(T &));
   void postorder(void (*visit)(T &));

   int size() const;
   void clear();
   int height() const;
   int leaf() const;

   void print() const; // A method to print out the tree using preorder

   // Add the prototypes of the Big-Three below and add their definitions later

protected: // can be directly accessed by all the member functions of this class and all its child classes
   // Auxiliary functions
   void recursive_preorder(BinaryNode<T> *sub_root, void (*visit)(T &));
   void recursive_inorder(BinaryNode<T> *sub_root, void (*visit)(T &));
   void recursive_postorder(BinaryNode<T> *sub_root, void (*visit)(T &));
   int recursive_size(BinaryNode<T> *sub_root) const;
   void recursive_clear(BinaryNode<T> *sub_root);
   int recursive_height(BinaryNode<T> *sub_root) const;
   int recursive_leaf(BinaryNode<T> *sub_root) const;
   BinaryNode<T> *recursive_copy(BinaryNode<T> *sub_root);

   void recursive_preorder_print_node(BinaryNode<T> *sub_root) const;

   // Data member
   BinaryNode<T> *root;
};

template <class T>
BinaryTree<T>::BinaryTree()
/*
Post: An empty binary tree has been created.
*/
{
   root = nullptr;
}

template <class T>
bool BinaryTree<T>::empty() const
/*
Post: A result of true is returned if the binary tree is empty.
      Otherwise, false is returned.
*/
{
   return root == nullptr;
}

template <class T>
void BinaryTree<T>::preorder(void (*visit)(T &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_preorder(root, visit); // a function call can not have a variable defenition
}

template <class T>
void BinaryTree<T>::inorder(void (*visit)(T &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_inorder(root, visit);
}

template <class T>
void BinaryTree<T>::postorder(void (*visit)(T &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_postorder(root, visit);
}

template <class T>
int BinaryTree<T>::size() const
/*
Post: The number of entries in the binary tree is returned.
Uses: The function recursive_size
*/
{
   return recursive_size(root);
}

template <class T>
void BinaryTree<T>::clear()
/*
Post: Dispose of all the nodes of the binary tree.
Uses: The function recursive_clear.
*/
{
   recursive_clear(root);
}

template <class T>
int BinaryTree<T>::height() const
/*
Post: The height of the binary tree is returned.
Uses: The function recursive_height
*/
{
   return recursive_height(root);

}

template <class T>
int BinaryTree<T>::leaf() const
{
   return recursive_leaf(root);

}

template <class Entry>
void BinaryTree<Entry>::print() const
{
   /*
   Post: The tree has been traversed in preorder.  Each node and its two children is printed
   Uses: The function recursive_preorder_print_node
   */
   cout << endl;
   cout << "++++++++++++++++++++++" << endl;
   if (root == NULL)
      cout << "EMPTY TREE" << endl;
   else
   {
      if (root->left == NULL && root->right == NULL)
         cout << root->data << ":  -  -" << endl;

      recursive_preorder_print_node(root);
   }
   cout << "++++++++++++++++++++++" << endl;
   cout << endl;
}

template <class Entry>
void BinaryTree<Entry>::recursive_preorder_print_node(BinaryNode<Entry> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder_print_node recursively
*/
{
   if (sub_root != NULL)
   {
      if (sub_root->left != NULL || sub_root->right != NULL)
      {
         cout << sub_root->data << ":  ";
         if (sub_root->left != NULL)
            cout << sub_root->left->data << "  ";
         else
            cout << "-  "; // "-" represents no child
         if (sub_root->right != NULL)
            cout << sub_root->right->data << " ";
         else
            cout << "-  "; // "-" represents no child
         // cout << "; ";
         cout << endl;
      }
      recursive_preorder_print_node(sub_root->left);
      recursive_preorder_print_node(sub_root->right);
   }
}

template <class T>
void BinaryTree<T>::recursive_preorder(BinaryNode<T> *sub_root,
                                       void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder recursively
*/
{
   if (sub_root != nullptr)
   {
      // 1. visit V
      visit(sub_root->data); // visit = display -> display(sub_root->data)
      // 2. Visit left
      recursive_preorder(sub_root->left, visit);
      // 3. visit right
      recursive_preorder(sub_root->right, visit);
   }
}

template <class T>
void BinaryTree<T>::recursive_inorder(BinaryNode<T> *sub_root,
                                      void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive_inorder recursively
*/
{
   if (sub_root != nullptr)
   {
      // 1. Visit left
      recursive_inorder(sub_root->left, visit);
      // 2. visit V
      visit(sub_root->data); // visit = display -> display(sub_root->data)
      // 3. visit right
      recursive_inorder(sub_root->right, visit);
   }
}

template <class T>
void BinaryTree<T>::recursive_postorder(BinaryNode<T> *sub_root,
                                        void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in postorder sequence.
Uses: The function recursive_postorder recursively
*/
{
   if (sub_root != nullptr)
   {
      // 1. Visit left
      recursive_postorder(sub_root->left, visit);
      // 2. visit right
      recursive_postorder(sub_root->right, visit);
      // 3. visit V
      visit(sub_root->data); // visit = display -> display(sub_root->data)
   }
}

template <class T>
int BinaryTree<T>::recursive_size(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The number of entries in the subtree is returned.
Uses: The function recursive_size recursively
*/
{
   if (sub_root == nullptr)
      return 0;
   else
   {
      int ls = recursive_size(sub_root->left);
      int rs = recursive_size(sub_root->right);
      return ls + rs + 1;
   }
}

template <class T>
void BinaryTree<T>::recursive_clear(BinaryNode<T> *sub_root)
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: All the nodes in the subtree are disposed of in postorder.
Uses: The function recursive_clear recursively
*/
{
   if (sub_root != nullptr)
   {
      recursive_clear(sub_root->left);
      recursive_clear(sub_root->right);
      delete sub_root;
      this->root = nullptr;
   }
}

template <class T>
int BinaryTree<T>::recursive_height(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: the height of the subtree is returned.
Uses: The function recursive_height recursively
*/
{
   // base case
   if (sub_root == nullptr)
      return 0;
   else
   {
      // inductive case
      int lh = recursive_height(sub_root->left);
      int rh = recursive_height(sub_root->right);
      return (lh > rh) ? lh + 1 : rh + 1;
   }
}

template <class T>
int BinaryTree<T>::recursive_leaf(BinaryNode<T> *sub_root) const
{
   if (sub_root == nullptr)
      return 0;
   else
   {
      int ls = recursive_leaf(sub_root->left);
      int rs = recursive_leaf(sub_root->right);
      if(sub_root->left==nullptr && sub_root->right==nullptr)
         return 1 + ls + rs;
      else
         return 0 + ls + rs;
   }
}


template <class T>
BinaryNode<T> *BinaryTree<T>::recursive_copy(BinaryNode<T> *sub_root)
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: returns a pointer to the root of a new binary tree that has exactly the same structure and content as those of the subtree.
Uses: The function recursive_copy recursively
*/
{
}
