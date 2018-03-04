#include "iostream"
#include "Node.h"

namespace linkedlistofclasses{
	Node::Node() :data(0), link(NULL)
	{

	}

	Node::Node(int value, Node* next) : data(value), link(next){

	}

	int Node::getData() const {
		return data;
	}

	Node* Node::getLink() const {
		return link;
	}

	void Node::setData(int value) {
		data = value;
	}
	void Node::setLink(Node* next){
		link = next;
	}

	Node::~Node()
	{
	}
}//linkedlistofclasses
