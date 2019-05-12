


#include <new>
#include <iostream>

template<typename T>class Stack {
private:
	struct Element {
		T data;
		Element *next;
	} *pstack;
public:
	Stack();

	~Stack();

	int Empty();

	T Top();

	T Pop();

	T Push(T x);

	void stkPrint();
};

template<typename T>
Stack<T>::Stack() {
	pstack = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
	Element *temp;
	while (pstack) {
		temp = pstack;
		pstack = pstack->next;
		delete temp;
	}
}

template<typename T>
int Stack<T>::Empty() {
	return pstack == nullptr;
}

template<typename T>
T Stack<T>::Top() {
	return pstack->data;
}

template<typename T>
T Stack<T>::Pop() {
	Element *del = pstack;
	T temp = pstack->data;
	pstack = pstack->next;
	delete del;
	return temp;
}

template<typename T>
T Stack<T>::Push(T x) {
	Element *ins = new(std::nothrow) Element;
	if (ins == nullptr) return 0;
	ins->data = x;
	ins->next = pstack;
	pstack = ins;
	return 1;
}
template<typename T> void Stack<T>::stkPrint() {
	Element* temp=pstack;
	while(temp!= nullptr){
		std::cout<<temp->data<<std::endl;
		temp=temp->next;

	}
}
