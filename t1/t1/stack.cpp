#include <cstddef>
#include <iostream>
#include "stack.h"

using namespace std;

namespace stacksavitch {
	Stack::Stack() :top(NULL)
	{
	}

	Stack::Stack(const Stack& a_stack) {

	}

	Stack::~Stack()
	{
		char next;
		while (!empty())
			next = pop();
	}

	bool Stack::empty() const {
		return (top == NULL);
	}

	void Stack::push(char the_symbol)
	{
		StackFramePtr newNode = new StackFrame();
		newNode->data = the_symbol;
		newNode->link = top;
		top = newNode;
	}

	char Stack::pop(){
		if (empty()) {
			cout << "Error: poping an empty stack" << endl;
			exit(1);
		}
		char result = top->data;
		StackFramePtr popItem = top;
		top = top->link;
		delete popItem;
		return result;
	}
}
