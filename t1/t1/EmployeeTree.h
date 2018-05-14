#pragma once
#include <string>
#include <vector>

using namespace std;


namespace EmployeeTreeFiled {
#define DOCF ".txt"
#define IMAGEF ".jpg"

#define TYPE char
	class EmployeeTree
	{
		typedef struct treenode{
			TYPE* chFiles[3];
			TYPE chName[20];
			TYPE pmfkey[10];
			vector<string> vFile;
			treenode* firstChild;
			treenode* nextSibling;
			bool bResigned;
		} EmployeeNode;

	public:
		EmployeeTree();
		~EmployeeTree();
		EmployeeTree(EmployeeNode* pNode);
		EmployeeTree(int nTotal);

		void createTree(int nTotalSum);
		void addChildNode(int i, int j);
		void addBrotherNode(EmployeeNode* bro, EmployeeNode* node);

		void print();

		void printEmployees(const EmployeeNode* pNode,int nSpace);
		
		void print(int nFileType);
		int childresign(EmployeeNode* pNode, const char pmfkey[]);

		void printEmployee(const EmployeeNode* pNode, int nFileType, int nSpace);
		void printSpace(int nSpace);
		void resignation(const char* pmfkey);
		void PreOrder(EmployeeNode* pNode, const char pmfkey[]);
		void promote(const char pmfkey);

		void print_test(int nSpace);

	private:
		EmployeeNode* root;
	};
}
