#include <iostream>

class Polynomial;

class Term{
    friend class Polynomial;

    private:
    float coef;
    int exp;
};

class Polynomial{
    public:
    Polynomial(){
        capacity=10;
        terms=0;
        termArray=new Term[capacity];
    };
    ~Polynomial();
    Polynomial Add(Polynomial B);
    void CreateTerm(const float coef, const int exp);
    private:
    Term *termArray;
    int capacity;
    int terms;
};


Polynomial Polynomial::Add(Polynomial B){
    Polynomial C;
    int a = 0;
    int b = 0;

    float c ;

    while(a<=terms && b<=B.terms){
        if(termArray[a].exp == B.termArray[b].exp){
            c = termArray[a].coef + B.termArray[b].coef;
            if(c) C.CreateTerm(c, termArray[a].exp);
            a++;
            b++;
        }
        else if(termArray[a].exp < B.termArray[b].exp){
            c = B.termArray[b].coef;
            C.CreateTerm(c, B.termArray[b].exp);
            b++;
        }
        else{
            c = termArray[a].coef;
            C.CreateTerm(c, termArray[a].exp);
            a++;
        }
    }

    for(; a<=terms; a++){
        C.CreateTerm(termArray[a].coef, termArray[a].exp);
    }
    for(; b<=B.terms; b++){
        C.CreateTerm(B.termArray[b].coef, B.termArray[b].exp);
    }

    return C;
}
