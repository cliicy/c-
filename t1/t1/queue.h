#pragma once

namespace queuesavitch {
	struct QueueNode{
		char data;
		QueueNode *link;
	};
	typedef QueueNode* QueueNodePtr;

	class Queue
	{
		public:
			Queue();
			Queue(const Queue& aQueue);

			~Queue();

			void add(char item);

			char remove();

			bool empty() const;
		private:
			QueueNodePtr front;
			QueueNodePtr back;
	};
}//queuesavitch


