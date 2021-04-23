#include <iostream>

using namespace std;
template<class type>
class Stack{
    public:
    Stack(){
        capacity=10;
        top=-1;
        array = new type[capacity];
    };
    ~Stack();
    bool full();
    bool empty();

    type& Top();
    void Push(const type& item);
    void Pop();
    bool IsEmpty() const;

    void Print(){
        for(int i=0; i<=top; i++)
        cout << array[i] << endl;
    };

    int Size() { return top+1;}

    private:
    type *array;
    int capacity;
    int top;
};

template<class type>
Stack<type>::~Stack(){
    delete[] array;
}

template<class type>
type& Stack<type>::Top(){
    return array[top];
}
template<class type>
void Stack<type>::Push(const type& item){
    if(top==capacity-1){
        capacity*=2;
        type *tmp = new type[capacity];

        for(int i=0; i<=top; i++){
            tmp[i]=array[i];
        }
        delete[] array;
        array=tmp;
    }
    array[++top]=item;
}

template<class type>
void Stack<type>::Pop(){
    if(top==-1) {
        std::cout << "The stack is empty\n";
        return;
    }
    array[top]='\0';
    top-=1;
}

template<class type>
bool Stack<type>::IsEmpty() const{
    if(top!=-1) return false;
    return true;
}


