#pragma once
#include <string>

using namespace std;


namespace EmployeeTreeFiled {
	class EmployeeTree
	{
		typedef struct treenode{
			string chFiles[3];
			string chName;
			int pmfkey;
			treenode* left;
			treenode* right;
		} EmployeeNode;

	public:
		EmployeeTree();
		~EmployeeTree();
		EmployeeTree(EmployeeNode* pNode);
		void createTree(int nTotalSum);
		void createChildTree(int i, int j);
		void addBrotherNode(EmployeeNode* bro, EmployeeNode* node);

		void print_employees(EmployeeNode & head);
		void print_Employee(int nFileType);
		void printSpace(int nSpace);
		void resignation(const char pmfkey);
		void promote(const char pmfkey);

		void print_test(int nSpace);

	private:
		EmployeeNode* root;
	};
}
