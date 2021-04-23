#include <iostream>
using namespace std;

class Node{
    private:
    int data;
    Node* next;

    friend class CircleList;
};

class CircleList{
    public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const int& front() const;
    const int& back() const;
    void head();
    void add(const int& e);
    void remove();

    private:
    Node* cursor;
};

CircleList::CircleList(): cursor(NULL){ }

CircleList::~CircleList(){
    while(!empty()) remove();
}

bool CircleList::empty() const{
    return cursor==NULL;
}

const int& CircleList::back() const{
    return cursor->data;
}

const int& CircleList::front() const{
    return cursor->next->data;
}

void CircleList::head(){
    cursor=cursor->next;
}

void CircleList::add(const int& e){
    Node* n = new Node;
    n->data=e;

    if(cursor==NULL){
        n->next=n;
        cursor=n;
    }
    else{
        n->next=cursor->next;
        cursor->next=n;
    }
}

void CircleList::remove(){
    Node* old=cursor->next;
    if(old==cursor){
        cursor=NULL;
    }
    else cursor->next=old->next;

    delete old;
}
