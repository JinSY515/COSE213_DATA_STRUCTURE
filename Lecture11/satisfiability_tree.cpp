#include <iostream>
using namespace std;

class SatTree;
class SatNode{
    friend class SatTree;
    private:
    SatNode* leftChild;
    char data_first;
    char data_second;
    SatNode* rightChild;
};

class SatTree{
    public:
    int size() const;
    bool empty() const;

    void PostOrderEval(SatNode* s);

    private:
    SatNode* root;
};

void SatTree::PostOrderEval(SatNode* s){
    if(s){
        PostOrderEval(s->leftChild);
        PostOrderEval(s->rightChild);
        switch(s->data_first){
            case '~':
            s->data_second = !s->rightChild->data_second;
            break;

            case '&':
            s->data_second = 
            s->rightChild->data_second && s->leftChild->data_second;
            break;

            case '|':
            s->data_second = 
            s->rightChild->data_second || s->leftChild->data_second;
            break;

            case true:
            s->data_second=true;
            break;

            case false:
            s->data_second=false;
            break;

        }
    }
}