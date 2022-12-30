#ifndef CALCULATOR_H
#define CALCULATOR_H

//
// Assignment 2 : Simple calculator using Stack
//
// COSE213 Spring 2021
//
// Won-Ki Jeong (wkjeong@korea.ac.kr)
//

#include <iostream>
#include <cassert>
#include <math.h>
#include <string.h>
#include "stack.h"


Stack<double> opr; // stack for operands
Stack<char> opt;   // stack for operators


//
// Modify Eval() below to evaluate the given expression
//

int isp(char op){
	if(op=='(') return (8);
	else if(op=='*'||op=='/') return (2);
	else return (3);
}

int icp(char op){
	if(op=='(') return (0);
	else if(op=='*'||op=='/') return (2);
	else  return (3);
	

}

void case_opt(double operand1, double operand2){
	double tmp_operand;

	if(opt.Top()=='+'){
		tmp_operand=operand1+operand2;
		opr.Push(tmp_operand);
	}
	else if(opt.Top()=='-'){
		tmp_operand = operand1 - operand2;
		opr.Push(tmp_operand);
	}
	else if(opt.Top()=='*'){
		tmp_operand = operand1 * operand2;
		opr.Push(tmp_operand);
	}
	else if(opt.Top()=='/'){
		tmp_operand = operand1 / operand2;
		opr.Push(tmp_operand);
	}
							
	opt.Pop();
}

void opt_cmp(){
	double operand2 = opr.Top();
	opr.Pop();
	double operand1 = opr.Top();
	opr.Pop();
	
	case_opt(operand1, operand2);
}


double Eval(char* in)
{
	double out = 0;
	
	char buf[1000]; // temp buffer 
	char lastToken = '#';
	
	double operand;
	int i = 0, bi = 0;  //what is bi? buffer's index?
	
	opt.Push('#');
		
	while(in[i] != '\0')
	{		
		char c = in[i];
		
		// Operators
		if(c == '+' || c == '-' ||
		   c == '*' || c == '/' ||
		   c == '(' || c == ')')
		{
			if(bi > 0)  //not empty buffer = before this operator was operand
			{
				buf[bi++] = '\0';
				operand = atof(buf);				
				bi = 0;
				
				char operator2;
				char operator1;
				operator2=opt.Top();
				if(operator2=='-'){  //is unary? or binary?
					opt.Pop();
					operator1=opt.Top();
					if(operator1=='('||operator1=='#'){
						operand=(-1)*operand;
					}
					else if(operator1==')'){
						opt.Pop();
						
						if(isp(opt.Top()) <= icp('-')){
							opt_cmp();
						}
						opt.Push('-');

					}
					else{
						opt.Push('-');
					}
				}
				// push operand
				//std::cout << "New operand is " << operand << "\n";//
				opr.Push(operand);
			}

	
			// push operator
			//std::cout << "New operator is " << c << "\n";//
			if(c==')'){
				while(opt.Top()!='('){
					if(opt.Top()==')'){
						opt.Pop();
						continue;
					}
					opt_cmp();
				}
				opt.Pop(); // pop '('
				opt.Push(c);
				
			}
			//let's compare isp and icp when pushing new operator
			else{
				if(opt.Top()==')'){
					if(c!='-') {
						opt.Pop();
						goto cmp;
					}
					else {
						opt.Push(c);
					}
				}
				else if(opt.Top()=='#'){
					opt.Push(c);
				}
				else{
					cmp : 
					if(isp(opt.Top()) <= icp(c)){
						opt_cmp();
					}
					opt.Push(c);
				}
			}
		}
		// Operands
		else if(c == '0' || c == '1' ||
				c == '2' || c == '3' ||
				c == '4' || c == '5' ||
				c == '6' || c == '7' ||
				c == '8' || c == '9' ||
				c == '.')
		{
			buf[bi++] = c;  //update token
		}
		else {}
	
		i++;
	}
	
	// push the very last operand if exists
	if(bi > 0)
	{
		buf[bi++] = '\0';
		operand = atof(buf);
		bi = 0;
		
		// push operand
		//std::cout << "New operand : " << operand << std::endl;//
		opr.Push(operand);
	}

	while(!opt.IsEmpty()){
		if(opt.Top()==')'){
			opt.Pop();
			continue;
		}
		double operand2=opr.Top();
		opr.Pop();
		if(opr.IsEmpty()){
			out=operand2;
			break;
		}
		double operand1=opr.Top();
		opr.Pop();

		case_opt(operand1, operand2);
		
	}
	return out;	
}

#endif
