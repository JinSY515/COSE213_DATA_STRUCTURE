//
// Assignment 2 : Simple calculator using Stack
//
// Array-based stack data structure
//
// COSE213 Spring 2021
//

template<class type>
Stack<type>::~Stack()
{
	// ToDo
	delete[] array; //destruct
}

template<class type>
type& Stack<type>::Top()
{
	// ToDo
	return array[top];  //return the top element of the stack
}

template<class type>
void Stack<type>::Push(const type& item)
{
	// ToDo
	if(top==capacity-1){  //array doubling
		capacity*=2;
		type *tmp=new type[capacity];
		for(int i=0; i<=top; i++){
			tmp[i]=array[i];
		}
		delete[] array;
		array=tmp;
	}
	array[++top]=item;  //push
}

template<class type>
void Stack<type>::Pop()
{
	// ToDo
	if(top==-1){  //if there is no element in the stack
		std::cout << "The stack is empty\n";
		return;
	}
	array[top]='\0';
	top-=1;   //pop
}

template<class type>
bool Stack<type>::IsEmpty() const
{
	// ToDo	
	if(top!=-1) return false;  //if there is top element 
	return true; //else
}

