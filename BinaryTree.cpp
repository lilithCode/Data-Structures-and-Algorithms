#include <iostream>
#include <queue>
using namespace std;
inline static int space = 5;
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
    void setData(int d) { data = d; }
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
    bool isBST(Node *node)
    {
        static Node *prev = NULL;
        if (node != NULL)
        {
            if (!isBST(node->getLeft()))
                return 0;
            if (prev != NULL && node->getData() <= prev->getData())
                return 0;
            prev = node;
            return isBST(node->getRight());
        }
        else
            return 1;
    }
    void displayTree(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            while (levelSize > 0)
            {
                Node *node = q.front();
                q.pop();
                cout << node->getData() << " ";

                if (node->getLeft() != nullptr)
                {
                    q.push(node->getLeft());
                }
                if (node->getRight() != nullptr)
                {
                    q.push(node->getRight());
                }
                levelSize--;
            }

            cout << endl; // Move to the next line for the next level
        }
    }
    Node *search(Node *node, int key)
    {
        if (node == NULL)
            return NULL;
        if (node->getData() > key)
            return search(node->getLeft(), key);

        else if (node->getData() < key)
            return search(node->getRight(), key);
        else
            return node;
    }
    void insert(Node *root, int key)
    {
        Node *prev = NULL;
        while (root != NULL)
        {
            prev = root;
            if (key == root->getData())
            {
                printf("Cannot insert %d, already in BST", key);
                return;
            }
            else if (key < root->getData())
            {
                root = root->getLeft();
            }
            else
            {
                root = root->getRight();
            }
        }
        Node *n = new Node(key, NULL, NULL);
        if (key < prev->getData())
        {
            prev->setLeft(n);
        }
        else
        {
            prev->setRight(n);
        }
    }
    Node *inOrderPredecessor(Node *root)
    {
        if (root->getLeft() != nullptr)
            root = root->getLeft();

        while (root->getRight() != NULL)
        {
            root = root->getRight();
        }
        return root;
    }

    Node *deleteNode(Node *root, int value)
    {

        Node *iPre;
        if (root == NULL)
        {
            return NULL;
        }
        if (root->getLeft() == NULL && root->getRight() == NULL)
        {
            free(root);
            return NULL;
        }

        // searching for the node to be deleted
        if (value < root->getData())
        {
            root->setLeft(deleteNode(root->getLeft(), value));
        }
        else if (value > root->getData())
        {
            root->setRight(deleteNode(root->getRight(), value));
        }
        // deletion strategy when the node is found
        else
        {
            iPre = inOrderPredecessor(root);
            root->setData(iPre->getData());
            root->setLeft(deleteNode(root->getLeft(), iPre->getData()));
        }
        return root;
    }
};

int main()
{
    /*
                                    9
                                   / \
                                  7   10
                                 / \
                                1   8
    */
    // Create the binary tree and initialize the root with the value 2
    BinaryTree tree(new Node(9));

    // Set left and right children for the root node
    tree.getRoot()->setLeft(new Node(7));
    tree.getRoot()->setRight(new Node(10));

    // Set left and right children for the node with value 7
    tree.getRoot()->getRight()->setLeft(new Node(1));
    tree.getRoot()->getLeft()->setRight(new Node(8));

    tree.displayTree(tree.getRoot());

    if (tree.isBST(tree.getRoot()))
    {
        cout << "The tree is a binary search tree." << endl;
    }
    else
        cout << "The tree is not a binary search tree." << endl;

    cout << "Preorder Traversal: ";
    tree.preorderTraversal(tree.getRoot()); // Output: 2 7 1 5 3
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorderTraversal(tree.getRoot()); // Output: 1 5 7 3 2
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.getRoot()); // Output: 1 7 5 2 3
    cout << endl;
    Node *n = tree.search(tree.getRoot(), 7);
    if (n)
    {
        cout << "Found: " << n->getData();
    }
    else
        cout << "Not found " << endl;
    tree.deleteNode(tree.getRoot(), 1);
    tree.displayTree(tree.getRoot());

    return 0;
}
