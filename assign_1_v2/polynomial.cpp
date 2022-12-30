#include "polynomial.h"
#include <iostream>
#include <math.h>


//
// Implementation
//


// Copy constructor
Polynomial::Polynomial(const Polynomial& source)
{
	// ToDo
	terms=source.terms;
    capacity=source.capacity;
    termArray=new Term[capacity];  //allocate new array
    for(int i=0; i<source.terms; i++){
        termArray[i].coef=source.termArray[i].coef; //copy contents
        termArray[i].exp=source.termArray[i].exp;
    }
}	

// Destructor
Polynomial::~Polynomial()
{
	// ToDo
	delete[] termArray; //free the allocated array
}


Polynomial& Polynomial::operator = (const Polynomial& source)
{
	// ToDo
	delete[] this->termArray;  //free and allocate new array
    this->capacity=source.capacity; 
    this->terms=source.terms;
    this->termArray=new Term[capacity];
    for(int i=0; i<terms; i++){
        this->termArray[i].coef=source.termArray[i].coef;
        this->termArray[i].exp=source.termArray[i].exp;
    }
    
    return *this;
}



// Sum of *this and source polynomials
Polynomial Polynomial::operator +(const Polynomial& source)
{
	Polynomial c;

	
	// ToDo
    int a=0;  //index of existing Polynomial A
    int b=0;  //index of another Polynomial source

    float c_coef;
    while((a<terms)&&(b<source.terms)){
        if(termArray[a].exp==source.termArray[b].exp){ //차수 같을 때
            c_coef=termArray[a].coef + source.termArray[b].coef;
            if(c_coef) c.CreateTerm(c_coef, termArray[a].exp); //계수 합이 0이 아니면
            a++;
            b++;
        }
        else if(termArray[a].exp>source.termArray[b].exp){ // A vs source, A 차수가 더 크면
            c_coef=termArray[a].coef;
            c.CreateTerm(c_coef, termArray[a].exp);
            a++;
        }
        else{  //A vs source, A 차수 더 낮으면
            c_coef=source.termArray[b].coef;
            c.CreateTerm(c_coef, source.termArray[b].exp);
            b++;
        }
    }

    for(;a<terms; a++){
        c.CreateTerm(termArray[a].coef, termArray[a].exp);
    }
    for(;b<source.terms; b++){
        c.CreateTerm(source.termArray[b].coef, source.termArray[b].exp);
    }

	
	return c;
}

Polynomial Polynomial::operator - (const Polynomial& source)
{
	Polynomial c;

	// ToDo
	int a=0; // index of existing Polynomial A
    int b=0; // index of another Polynomial source

    float c_coef=0;

    while((a<terms) && (b<source.terms)){
        if(termArray[a].exp == source.termArray[b].exp){
            c_coef=termArray[a].coef-source.termArray[b].coef;  
            if(c_coef) //if the c_coef is not 0
            c.CreateTerm(c_coef, termArray[a].exp);
            a++;
            b++;
        }
        else if(termArray[a].exp > source.termArray[b].exp) {
            c.CreateTerm(termArray[a].coef, termArray[a].exp);
            a++;
        }
        else{
            c_coef=0-source.termArray[b].coef;
            c.CreateTerm(c_coef, source.termArray[b].exp);
            b++;
        }
    }

    for(;a<terms; a++){
        c.CreateTerm(termArray[a].coef, termArray[a].exp);
    }
    for(;b<source.terms; b++){
        c_coef=0-source.termArray[b].coef;
        c.CreateTerm(c_coef, source.termArray[b].exp);
    }
	
	return c;
	
}


Polynomial Polynomial::operator * (const Polynomial& source)
{
	Polynomial c;
	
	// ToDo
	int a; //index of the existing Polynomial A
    int b; //index of the existing Polynomial source
    int tmpExp;
    float tmpCoef;
    for(a=0; a<terms; a++){
        Polynomial tmp; //make a polynomial temporary polynomial
        for(b=0; b<source.terms; b++){
            tmpExp=termArray[a].exp+source.termArray[b].exp;
            tmpCoef=termArray[a].coef*source.termArray[b].coef;
            tmp.CreateTerm(tmpCoef, tmpExp);
        }
        c=c.Polynomial::operator+(tmp); //add tmp to c
    }
	
	
	return c;	
}


float Polynomial::Eval(float x)
{
	float ret = 0;
	
	// ToDo
	 for(int i=0; i<terms; i++){
        ret += (pow(x,termArray[i].exp) * termArray[i].coef);
    }
	
	return ret;
}




// Compute derivative of the current polynomial
Polynomial Polynomial::Derivative()
{
	Polynomial c;
	
	// ToDo
	int c_exp;
    float c_coef;
	for(int i=0; i<terms; i++){
        if(termArray[i].exp==0) continue;
        c_exp=termArray[i].exp-1;
        c_coef=termArray[i].exp*termArray[i].coef;
        c.CreateTerm(c_coef,c_exp);
    }
	
	return c;	

}


void Polynomial::CreateTerm(const float coef, const int exp)
{
	// ToDo
	// is there no term existing?
    int idx=0;
    while(exp<=termArray[idx].exp && idx<terms){  
        if(termArray[idx].exp==exp){  //if the term already exists
            termArray[idx].coef=coef; //replace
            return;
        }
        idx++;
    }
    // is current # is equal to max # ? (is the termArray full?) Yes
    if(terms==capacity){   //Array doubling
        capacity*=2;
        Term *tmp = new Term[capacity];
        for(int i=0; i<terms; i++){  
            tmp[i].coef=termArray[i].coef;
            tmp[i].exp=termArray[i].exp;
        }
        delete[] termArray;
        termArray = tmp;
    }

    // is current # is equal to max # ? No

    if(idx<terms){ //Not the end of the array?
        for(int j=terms-1; j>=idx; j--){   //insertion sort
            termArray[j+1].coef=termArray[j].coef;
            termArray[j+1].exp=termArray[j].exp;
        }
    }
    termArray[idx].coef=coef;
    termArray[idx].exp=exp;
    terms++;
}

