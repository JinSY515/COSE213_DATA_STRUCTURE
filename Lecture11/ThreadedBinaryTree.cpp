#include <iostream>
using namespace std;

class ThreadedNode{
    friend class ThreadedTree;
    friend class ThreadedInorderIterator;
    friend class ThreadedPreorderIterator;

    private:
    bool leftThread;
    ThreadedNode* leftChild;
    char data;
    ThreadedNode* rightChild;
    bool rightThread;
};

class ThreadedTree{
    friend class ThreadedInorderIterator;
    friend class ThreadedPreorderIterator;
    public:
    // // 
    private:
    ThreadedNode* root;
};

class ThreadedInorderIterator{
    public:
    char* Next();
    ThreadedInorderIterator(ThreadedTree tree):t(tree){
        CurrentNode = t.root;
    }

    private:
    ThreadedTree t;
    ThreadedNode *CurrentNode;
};

class ThreadedPreorderIterator{
    public:
    char* Next();
    ThreadedPreorderIterator(ThreadedTree tree):t(tree){
        CurrentNode = t.root;
    }

    private:
    ThreadedTree t;
    ThreadedNode *CurrentNode;
};

char* ThreadedPreorderIterator::Next(){
    ThreadedNode *tmp=CurrentNode;
    if(!CurrentNode->leftThread){
        tmp=CurrentNode->rightChild->rightChild;
    }
    CurrentNode=tmp;
    
    if(CurrentNode==t.root) return 0;
    else return &CurrentNode->data;
}

char* ThreadedInorderIterator::Next(){
    ThreadedNode *tmp=CurrentNode->rightChild;
    if(!CurrentNode->rightThread){
        while(!tmp->leftThread) tmp=tmp->leftChild;

    }
    CurrentNode=tmp;

    if(CurrentNode==t.root) return 0;
    else return &CurrentNode->data;
}