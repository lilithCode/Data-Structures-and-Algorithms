#include <iostream>

class Node
{
private:
    int m_data;
    class Node *m_next;

public:
    Node( int data=0,Node *next = nullptr)
        :  m_next{next} , m_data{data}{}

    int isEmpty(){
    if (this==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
     Node* p =new Node();
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

    Node* push(int data);
    Node* pop();
    void display();

};
Node* Node::pop() // Time Complexity is O(1)
{
    if (isEmpty())
    {
        printf("The stack is empty\n");
        return this;
    }
    else
    {
        Node* current =this->m_next;
        delete this;
        return current;
    }
}


Node* Node::push(int data) // Time Complexity is O(1)
{
    if(isFull()){
        std::cout<<"Stack Overflow";
        return this;
    }
    else{
    Node *another = new Node;
    Node *current = another;
    another->m_data=data;
    another->m_next = this;
    return current;
    }

}
void Node::display() // Time Complexity is O(n)
{
    Node *ptr = this;
    while (ptr != NULL)
    {
        std::cout << "Element: " << ptr->m_data << std::endl;
        ptr = ptr->m_next;
    }
    std::cout << std::endl;
}
int main()
{
 
    Node *stact=nullptr;   //stact has 1 data and NULL   1  ---> NULL
    stact=stact->push(1);       // now stact head has this 1  --->  0  --->  NULL
    stact=stact->push(2);       // now stact head has this 2  ---> 1  --->  0  --->  NULL
    stact=stact->push(3);       // this has changed the stact data to 3,   3  --->  2  ---> 1  --->   0  ---> NULL
    // this will print the above just like in a stack, as 
    //    |  3  |
    //    |  2  |
    //    |  1  |
    //    |__0__|

    stact=stact->pop();
    stact->display();


    return 0;
}