#include <iostream>
#include <queue>
using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int value = 0, Node *l = nullptr, Node *r = nullptr)
        : data{value}, left{l}, right{r} {}
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

    int depth(Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(depth(node->getLeft()), depth(node->getRight()));
    }

    int balanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return depth(node->getLeft()) - depth(node->getRight());
    }

    Node *rightRotation(Node *y)
    {
        Node *x = y->getLeft();
        Node *T = x->getRight();

        x->setRight(y);
        y->setLeft(T);

        return x;
    }

    Node *leftRotation(Node *x)
    {
        Node *y = x->getRight();
        Node *T = y->getLeft();

        y->setLeft(x);
        x->setRight(T);

        return y;
    }

    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->getData())
            node->setLeft(insert(node->getLeft(), key));
        else if (key > node->getData())
            node->setRight(insert(node->getRight(), key));
        else
            return node; // Duplicate keys not allowed

        int balance = balanceFactor(node);

        // Left-Left Case
        if (balance > 1 && key < node->getLeft()->getData())
            return rightRotation(node);

        // Right-Right Case
        if (balance < -1 && key > node->getRight()->getData())
            return leftRotation(node);

        // Left-Right Case
        if (balance > 1 && key > node->getLeft()->getData())
        {
            node->setLeft(leftRotation(node->getLeft()));
            return rightRotation(node);
        }

        // Right-Left Case
        if (balance < -1 && key < node->getRight()->getData())
        {
            node->setRight(rightRotation(node->getRight()));
            return leftRotation(node);
        }

        return node;
    }

    void displayTree(Node *node)
    {
        if (node == nullptr)
            return;

        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            int levelSize = q.size();
            while (levelSize > 0)
            {
                Node *curr = q.front();
                q.pop();
                cout << curr->getData() << " ";

                if (curr->getLeft())
                    q.push(curr->getLeft());
                if (curr->getRight())
                    q.push(curr->getRight());

                levelSize--;
            }
            cout << endl;
        }
    }

public:
    BinaryTree() : root{nullptr} {}

    void insert(int key)
    {
        root = insert(root, key);
    }

    void displayTree()
    {
        displayTree(root);
    }
};

int main()
{
    BinaryTree tree;
    tree.insert(9);
    tree.insert(7);
    tree.insert(15);
    tree.insert(8);
    tree.insert(11);
    tree.insert(1);
    tree.insert(0);

    tree.displayTree();

    return 0;
}