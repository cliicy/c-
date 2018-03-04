#include <iostream>
#include <cstddef>
#include <cstdlib>

#include "queue.h"

using namespace std;

namespace queuesavitch {
//	template<class T>

	Queue::Queue() : front(NULL), back(NULL)
	{
	}

	Queue::Queue(const Queue& aQueue){

	}

	Queue::~Queue(){
	}
	
	bool Queue::empty() const{
		return (back==NULL);
	}

	void Queue::add(char item) {
		if (empty()){
			front = new QueueNode;
			front->data = item;
			front->link = NULL;
			back = front;
		} 
		else {
			QueueNodePtr temp_ptr=new QueueNode;
			temp_ptr->data = item;
			temp_ptr->link = NULL;
			back->link = temp_ptr;
			back = temp_ptr;
		}
	}

	char Queue::remove() {
		if (empty()) {
			cout << "error: removing an item from an empty queue.\n";
			exit(1);
		}

		char resutl = front->data;
		QueueNodePtr discard = front;
		front = front->link;
		if (front == NULL)
			back = NULL;
		delete discard;
		return resutl;
		
	}
}

