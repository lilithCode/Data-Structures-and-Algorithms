#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    
    Node(int value = 0, Node *l = nullptr, Node *r = nullptr) : data{value}, left{l}, right{r} {};
    int getData() { return data; }
    Node *getLeft() { return left; }
    Node *getRight() { return right; }
    void setLeft(Node *l) { left = l; }
    void setRight(Node *r) { right = r; }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree(Node *rt = nullptr) : root{rt} {}
    Node *getRoot() { return root; }

    // Preorder Traversal: Root -> Left -> Right
    // Time Complexity: O(n) because each node is visited exactly once, where n is the number of nodes.
    void preorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return; 
        }
        cout << node->getData() << " "; 
        preorderTraversal(node->getLeft()); 
        preorderTraversal(node->getRight()); 
    }

    // Postorder Traversal: Left -> Right -> Root
    // Time Complexity: O(n) because each node is visited exactly once.
    void postorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return; 
        }
        postorderTraversal(node->getLeft()); 
        postorderTraversal(node->getRight()); 
        cout << node->getData() << " "; 
    }

    // Inorder Traversal: Left -> Root -> Right
    // Time Complexity: O(n) because each node is visited exactly once.
    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderTraversal(node->getLeft()); 
        cout << node->getData() << " "; 
        inorderTraversal(node->getRight()); 
    }
};

int main()
{
    /*
                                    2
                                   / \
                                  7   3
                                 / \
                                1   5
    */
    // Create the binary tree and initialize the root with the value 2
    BinaryTree tree(new Node(2));

    // Set left and right children for the root node
    tree.getRoot()->setLeft(new Node(7)); 
    tree.getRoot()->setRight(new Node(3));

    // Set left and right children for the node with value 7
    tree.getRoot()->getLeft()->setLeft(new Node(1)); 
    tree.getRoot()->getLeft()->setRight(new Node(5)); 

    cout << "Preorder Traversal: ";
    tree.preorderTraversal(tree.getRoot()); // Output: 2 7 1 5 3
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorderTraversal(tree.getRoot()); // Output: 1 5 7 3 2
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.getRoot()); // Output: 1 7 5 2 3
    cout << endl;

    return 0;
}
