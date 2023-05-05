#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;

void menu();
void insert_msg();
void delete_msg();
template <class T>
void display(T &);
int main()
{
   string input = "";
   bool exit_now = false;
   BinarySearchTree<int> bst;
   while (!exit_now)
   {
      menu();
      getline(cin, input);
      if (input == "i") // Insert
      {
         insert_msg();
         getline(cin, input);
         while (input != "q")
         {
            cout << "insert(" << input << ")" << endl;
            bst.insert(stoi(input));
            bst.print();
            getline(cin, input);
         }
      }
      else if (input == "r") // remove
      {
         delete_msg();
         getline(cin, input);
         while (input != "q")
         {
            bst.remove(stoi(input));
            bst.print();
            getline(cin, input);
         }
      }
      else if (input == "c") // clear
         bst.clear();
      else if (input == "t") // print tree
         bst.print();
      else if (input == "h") // print tree height
         cout << "\nThe height of the binary tree is " << bst.height() << endl;
      else if (input == "s") // print size
         cout << "\nThe size (node count) of the binary tree is " << bst.size() << endl;
      else if (input == "l") // leaf count
         cout << "\nThe leaf count of the binary tree is " << bst.leaf() << endl;
      else if (input == "m")
      { // preorder traversal
         bst.preorder(display);
         void (*fp)(int &);
      }
      else if (input == "n")
      {                        // inorder traversal
         bst.inorder(display); // in c++ the function name is also a pointer to function
         void (*fp)(int &);    // fp: a variable pointing to a function
      }
      else if (input == "p")
      { // postorder traversal
         bst.postorder(display);
         void (*fp)(int &);
      }
      else if (input == "e")
      { // operator=()
         cout << "create a new bst named bst_copy" << endl;
         BinarySearchTree<int> bst_copy; // a block bariable scope is within if
         getline(cin, input);
         if (input == "i")
         {
            insert_msg();
            getline(cin, input);
            while (input != "q")
            {
               bst_copy.insert(stoi(input));
               bst_copy.print();
               getline(cin, input);
            }

            cout << "Now, bst_copy = bst" << endl;

            bst_copy = bst;
            bst_copy.print();
         }
      }
      else if (input == "x")
         exit_now = true;
   }
}

void menu()
{
   cout << "\n";
   cout << "***********************\n";
   cout << "Menu:\n";
   cout << "i. Incremental Insert\n";
   cout << "r. Incremental remove\n";
   cout << "c. Clear tree\n";
   cout << "t. Print tree\n";
   cout << "h. Print tree height\n";
   cout << "s. Print tree size\n";
   cout << "m. Pre-order Traversal\n";
   cout << "n. In-order Traversal\n";
   cout << "p. Post-order Traversal\n";
   cout << "l. Leaf count\n";
   cout << "e. oerator=()\n";
   cout << "x. Exit\n";
   cout << "***********************\n";
}

void insert_msg()
{
   cout << "\nEnter new integer keys to insert.  Enter \"q<Enter>\" to quit.\n\n";
}

void delete_msg()
{
   cout << "\nEnter integer keys to delete.  Enter \"q<Enter>\" to quit.\n\n";
}

template <class T>
void display(T &value)
{
   cout << value << endl;
}
