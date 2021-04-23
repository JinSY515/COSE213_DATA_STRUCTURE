#include <iostream>

class Bag{
    public:
    Bag();
    ~Bag();

    void Add(int);
    int *Delete(int);

    bool IsFull();
    bool IsEmpty();

    private:
    int *array;
    int MaxSize;
    int top;
};