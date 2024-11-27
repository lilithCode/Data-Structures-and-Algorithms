// This program will help to convert a infix to postfix expression
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

struct Operators
{
    char symbol;
    int precedence;
};

struct Node
{
    char data;
    Node *next;
    int m_precedence;
};

class Stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(char value, int precedence = 0) // Time Complexity is O(1)
    {
        if (isEmpty())
        {
            cout << "Stack Overflow..." << endl;
            return;
        }
        Node *newNode = new Node();
        newNode->data = value;
        newNode->m_precedence = precedence;
        newNode->next = top;
        top = newNode;
    }

    void pop() // Time Complexity is O(1)
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    char peek(int index)// Time Complexity is O(n)
    {
        if (index < 0)
        {
            cout << "Invalid index. Index must be non-negative.\n";
            return '\0'; // Return null character for invalid index
        }

        Node *current = top;
        int count = 0;

        while (current != nullptr)
        {
            if (count == index)
            {
                return current->data;
            }
            current = current->next;
            count++;
        }
    }

    int getPrecedence()
    {
        return isEmpty() ? -1 : top->m_precedence;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
    bool isFull()
    {
        Node *temp = new (nothrow) Node(); // Try to allocate memory
        if (temp == nullptr)
        {
            return true; 
        }
        delete temp;  // Free the temporary node
        return false; 
    }
    char getChar()
    {
        return isEmpty() ? '\0' : top->data;
    }
};

bool parenthesisMatch(Stack *s, string_view equation)// Time Complexity is O(n)
{
    for (char ch : equation)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s->push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (s->isEmpty() ||
                (ch == ')' && s->getChar() != '(') ||
                (ch == ']' && s->getChar() != '[') ||
                (ch == '}' && s->getChar() != '{'))
            {
                return false;
            }
            s->pop();
        }
    }
    return s->isEmpty();
}

bool checkExpression(string_view s)
{
    string valid = "-+/&^* 1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ{}[]()";
    return s.find_first_not_of(valid) != string::npos;
}

void InfixToPostfix(string &exp)// Time Complexity is O(n)
{
     // you can increase this as you like. Add more operators if you want to for more advance expression
    array<Operators, 5> arr = {
        Operators{'+', 1},
        Operators{'-', 1},
        Operators{'/', 2},
        Operators{'*', 2},
        Operators{'^', 3}};
    Stack operators;

    for (char ch : exp)
    {
        bool isOperator = false;

        for (const auto &op : arr)
        {
            if (ch == op.symbol)
            {
                while (!operators.isEmpty() && operators.getPrecedence() >= op.precedence)
                {
                    cout << operators.getChar();
                    operators.pop();
                }
                operators.push(ch, op.precedence);
                isOperator = true;
                break;
            }
        }

        if (!isOperator)
        {
            cout << ch;
        }
    }

    while (!operators.isEmpty())
    {
        cout << operators.getChar();
        operators.pop();
    }
    cout << endl;
}

int main()
{
    Stack paren;
    string equation;

    do
    {
        cout << "Enter an expression: ";
        getline(cin >> ws, equation);

        bool invalid = checkExpression(equation) || !parenthesisMatch(&paren, equation);
        if (invalid)
        {
            cout << "Invalid. The entered expression isn't a valid mathematical expression.\n";
        }
        else
        {
            break;
        }
    } while (true);

    InfixToPostfix(equation);
    return 0;
}
