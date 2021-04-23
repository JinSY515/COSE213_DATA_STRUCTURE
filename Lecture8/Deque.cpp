#include <iostream>
using namespace std;

class Node {
    private:
    Node* left;
    int data;
    Node* right;

    friend class DList;
};

class DList{
    public:
    DList();
    ~DList();

    bool empty() const;
    const int& front() const;
    const int& back() const;

    void addFront(const int& e);
    void addBack(const int& e);
    void removeFront();
    void removeBack();

    private:
    Node* head;
    Node* tail;

    protected:
    void add(Node* v, const int& e);
    void remove(Node* v);

};

DList::DList(){
    head = new Node;
    tail = new Node;

    head->right=tail;
    tail->left=head;
}

DList::~DList(){
    while(!empty()) removeFront();

    delete head;
    delete tail;
}

bool DList::empty() const{
    return head->right == tail;
}

const int& DList::front() const{
    return head->right->data;
}

const int& DList::back() const{
    return tail->left->data;
}

void DList::add(Node* v, const int& e){
    Node* u =new Node;
    u->data=e;
    u->right=v;
    u->left=v->left;
    v->left->right=v->left=u;
}

void DList::addFront(const int& e){
    add(head->right, e);
}

void DList::addBack(const int& e){
    add(tail, e);
}

void DList::remove(Node* v){
    Node* u=v->left;
    Node* w=v->right;
    u->right=w;
    w->left=u;
    delete v;
}

void DList::removeFront(){
    remove(head->right);
}

void DList::removeBack(){
    remove(tail->left);
}


class LinkedDeque{
    public:
    LinkedDeque();
    ~LinkedDeque();
    int capacity() const;
    bool empty() const;
    const int& Front() const;
    const int& Back() const;
    void insertFront(const int& e);
    void insertBack(const int& e);
    void eraseFront();
    void eraseBack();

    private:
    DList D;
    int size;
};

void LinkedDeque::insertFront(const int& e){
    D.addFront(e);
    size++;
}

void LinkedDeque::insertBack(const int& e){
    D.addBack(e);
    size++;
}

void LinkedDeque::eraseFront(){
    if(empty()) return;
    D.removeFront();
    size--;
}

void LinkedDeque::eraseBack(){
    if(empty()) return;
    D.removeBack();
    size--;
}

bool LinkedDeque::empty() const{
    return size==0;
}

const int& LinkedDeque::Front() const{
    if(empty()) return;
    return D.front();
}

const int& LinkedDeque::Back() const{
    if(empty()) return;
    return D.back();
}
