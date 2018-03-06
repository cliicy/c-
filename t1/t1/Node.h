#pragma once
namespace linkedlistofclasses{
	class Node
	{
		public:
			Node();
			Node(int value,Node* next);

			~Node();

			int getData() const;
			Node* getLink() const;

			void setData(int value);
			void setLink(Node* next);
	
	private:
			int data;
			Node* link;
	};
	typedef Node* NodePtr;

}//linkedlistofclases
