#include "enum.h"
using namespace std;

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
public:
   Error_code insert(const T &);
   Error_code remove(const T &);

protected:
   // Auxiliary functions
   Error_code search_and_insert(BinaryNode<T> *&sub_root, const T &new_data);
   Error_code search_and_delete(BinaryNode<T> *&sub_root, const T &target);
};

template <class T>
Error_code BinarySearchTree<T>::insert(const T &new_data)
{
   return search_and_insert(this->root, new_data);
}

template <class T>
Error_code BinarySearchTree<T>::search_and_insert(
    BinaryNode<T> *&sub_root, const T &new_data)
{
   Error_code error_code = success;

   if (sub_root == nullptr)
   { // base case
      sub_root = new BinaryNode<T>(new_data);
   }
   else if (sub_root->data == new_data)
   {
      error_code = duplicate_error;
   }
   else if (sub_root->data < new_data)
   {
      error_code = search_and_insert(sub_root->right, new_data);
   }
   else if (sub_root->data > new_data)
   {
      error_code = search_and_insert(sub_root->left, new_data);
   }
   return error_code;
}

template <class T>
Error_code BinarySearchTree<T>::remove(const T &target)
/*
Post: If a T with a key matching that of target belongs to the
      BinarySearchTree, a code of success is returned, and the corresponding node
      is removed from the tree.  Otherwise, a code of not_present is returned.
Uses: Function search_and_destroy
*/
{
   return search_and_delete(this->root, target);
}

template <class T>
Error_code BinarySearchTree<T>::search_and_delete(
    BinaryNode<T> *&sub_root, const T &target)
/*
Pre:  sub_root is either NULL or points to a subtree of the BinarySearchTree.
Post: If the key of target is not in the subtree, a code of not_present
      is returned.  Otherwise, a code of success is returned and the subtree
      node containing target has been removed in such a way that
      the properties of a binary search tree have been preserved.
Uses: Functions search_and_delete recursively
*/
{
   Error_code error_code = success;

   if (sub_root->data > target)
   { // go left
      error_code = search_and_delete(sub_root->left, target);
   }
   else if (sub_root->data < target)
   { // go right
      error_code = search_and_delete(sub_root->right, target);
   }
   else if (sub_root->data == target)
   {
      if (sub_root->left == nullptr && sub_root->right == nullptr)
      { // no child nodes
         sub_root = nullptr;
      }
      else if (sub_root->left == nullptr && sub_root->right != nullptr)
      { // right node only
         BinaryNode<T> *temp = sub_root;
         sub_root = sub_root->right;
         delete temp;
      }
      else if (sub_root->left != nullptr && sub_root->right == nullptr)
      { // left node only
         BinaryNode<T> *temp = sub_root;
         sub_root = sub_root->left;
         delete temp;
      }
      else if (sub_root->left != nullptr && sub_root->right != nullptr)
      { // both nodes
         BinaryNode<T> *temp = sub_root;
         temp = temp->left;             // Looking for immediate predecessor
         while (temp->right != nullptr) // While loop sets sub_root all the way right
            temp = temp->right;
         sub_root->data = temp->data;

         search_and_delete(sub_root->left, temp->data); //delete temp
      }
   }
   else
   { // node not found
      error_code = not_present;
   }

   return error_code;
}
