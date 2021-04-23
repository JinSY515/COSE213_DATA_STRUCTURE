#include <iostream>
using namespace std;

template<class type>
class Queue{
    public:
    Queue(){
        capacity=10;
        front=0;
        rear=0;
        array = new type[capacity];
    };
    ~Queue();

    int size() const;
    type& Front();
    type& Rear();
    
    void enqueue(const type& e);
    void dequeue();
    bool IsEmpty() const;
    bool IsFull() const;
    void Print(){
        for(int i=front; i<=rear; i++)
        cout << array[i] << endl;
    };

    int Size(){ return rear-front+1;}

    private:
    type* array;
    int capacity;
    int front;
    int rear;
};

template<class type>
Queue<type>::~Queue(){
    delete[] array;
}

template<class type>
type& Queue<type>::Front(){
    if(IsEmpty()) return;
    return array[front];
}

template<class type>
type& Queue<type>::Rear(){
    if(IsEmpty()) return;
    return array[rear];
}

template<class type>
void Queue<type>::enqueue(const type& e){
    array[rear++]=e;
}

template<class type>
void Queue<type>::dequeue(){
    if(IsEmpty()){
        cout << "The queue is empty\n";
        return;
    }
    else{
        array[front]='\0';
        front++;
    }
}

template<class type>
bool Queue<type>::IsEmpty() const{
    return capacity==0;
}

template<class type>
bool Queue<type>::IsFull() const{
    return capacity-1==rear==front;
}


