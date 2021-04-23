#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Tree;
class TreeNode{
    friend class Tree;
    private:
    TreeNode* leftChild;
    char data;
    TreeNode* rightChild;
};

class Tree{
    public:
    int size() const;
    bool empty() const;

    void inOrder(TreeNode * CurrentNode);
    void preOrder(TreeNode* CurrentNode);
    void postOrder(TreeNode* CurrentNode);
    void NonrecInorder();
    void LevelOrder();
    TreeNode* copy(TreeNode* origin);
    private:
    TreeNode* root;
};

void Tree::inOrder(TreeNode* CurrentNode){
    if(CurrentNode){
        inOrder(CurrentNode->leftChild);
        cout << CurrentNode->data;
        inOrder(CurrentNode->rightChild);
    }
}

void Tree::preOrder(TreeNode* CurrentNode){
    if(CurrentNode){
        cout << CurrentNode->data;
        preOrder(CurrentNode->leftChild);
        preOrder(CurrentNode->rightChild);
    }
}

void Tree::postOrder(TreeNode* CurrentNode){
    if(CurrentNode){
        postOrder(CurrentNode->leftChild);
        postOrder(CurrentNode->rightChild);
        cout << CurrentNode->data;
    }
}

void Tree::NonrecInorder(){
    stack<TreeNode*> s;
    TreeNode *CurrentNode=root;
    while(1){
        while(CurrentNode){
            s.push(CurrentNode);
            CurrentNode=CurrentNode->leftChild;
        }

        if(s.empty()) return;
        CurrentNode= s.top();
        s.pop();
        CurrentNode=CurrentNode->rightChild;
    }
}

void Tree::LevelOrder(){
    queue<TreeNode*> q;
    TreeNode * CurrentNode=root;
    while(CurrentNode){
        cout << CurrentNode->data;
        if(CurrentNode->leftChild) q.push(CurrentNode->leftChild);
        if(CurrentNode->rightChild) q.push(CurrentNode->rightChild);

        if(q.empty()) return;
        CurrentNode=q.front();
        q.pop();
    }
}

TreeNode *Tree::copy(TreeNode* origin){
    if(origin){
        TreeNode* tmp=new TreeNode;
        tmp->data=origin->data;
        tmp->leftChild=copy(origin->leftChild);
        tmp->rightChild=copy(origin->rightChild);
        return tmp;
    }

    else return 0;
}
