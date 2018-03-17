#include "iostream"
#include <assert.h>
#include <cstddef>

#include "..\t1\common.h"



namespace solution{
	using namespace std;
	using namespace treetask;
	using namespace EmployeeTreeFiled;

		void sort(string& s){
			for (unsigned int i = 0; i < s.length(); i++){
				for (unsigned int k = 1; k < s.length(); k++)
				{
					if (s[i]>s[k])
					{
						char c = s[i];
						s[i] = s[k];
						s[k] = c;
					}
				}
			}
		}

		bool checkstr(string s1, string s2){
			sort(s1);
			sort(s2);
			return (s1 == s2);
		}

		bool isScreamble(string s1, string s2){
			if (s1 == "") return s2 == "";
			if (checkstr(s1, s2) == false) return false;
			int len = s1.length();
			if (len == 1)return true;

			for (unsigned int i = 1; i < s1.length(); i++){
				string left = s1.substr(0, i);
				string right = s1.substr(i);
				if (isScreamble(left, s2.substr(i)) && isScreamble(right, s2.substr(i)) || \
					isScreamble(left, s2.substr(len - i)) && isScreamble(right, s2.substr(len - i)))
					return true;

			}
			return false;
		}

		void InitEmployeeTree(){
			EmployeeTree tree(14);

			tree.addChildNode(0, 1);
			tree.addChildNode(0, 5);
			tree.addChildNode(0, 10);
			tree.addChildNode(1, 2);
			tree.addChildNode(1, 3);
			tree.addChildNode(1, 4);
			tree.addChildNode(1, 7);
			tree.addChildNode(5, 6);
			tree.addChildNode(5, 8);
			tree.addChildNode(5, 9);
			tree.addChildNode(10, 11);
			tree.addChildNode(10, 12);
			tree.addChildNode(10, 13);

			tree.print();
			system("pause");

			tree.print(DOC);
			system("pause");

			tree.print(IMAGE);
			system("pause");

			tree.resignation("xiaoyu01");
				system("pause");
		}

		void InitTree(){
			//分配14个节点 为14名员工建立存储空间
			Tree tree(14);
			//						0			1			2				3			4		5			6			7			8			9			
			//char chName[14] = { "Steven", "YuanNing", "Wei Xiaojin", "Fan Zhihe", "Cliicy", "灰太狼", "Ge Langtai", "Jianjun", "XiaoYu", "Fengru", \

			//		10		11		12		13
			//	"Alex", "Shuan", "Ellen", "Luo" };

			//add root detail information
			tree.addNode(0, 1);
			tree.addNode(0, 5);
			tree.addNode(0, 10);
			tree.addNode(1, 2);
			tree.addNode(1, 3);
			tree.addNode(1, 4);
			tree.addNode(1, 7);
			tree.addNode(5, 6);
			tree.addNode(5, 8);
			tree.addNode(5, 9);
			tree.addNode(10, 11);
			tree.addNode(10, 12);
			tree.addNode(10, 13);

			tree.print();
			system("pause");

		}


		void GetMemory1(char* p){
			p = (char*)malloc(100);
		}

		void Test1(){
			char* str = NULL;
			GetMemory1(str);
			strcpy(str, "hello world");
			printf(str);
		}

		char* GetMemory2() {
			char p[] = "hello world";
			return p;
		}

		void Test2() {
			char* str = NULL;
			str = GetMemory2();
			printf(str);
		}

		void GetMemory3(char**p, int num) {
			*p = (char*)malloc(num);
			assert(*p != NULL);
			/*
			if (*p == NULL)
			{

			}
			*/
		}

		void Test3() {
			char* str = NULL;
			GetMemory3(&str, 100);
			strcpy(str, "hello");
			printf(str);
		}

		void PrintTest(int nSpace){
			EmployeeTree etree;
			etree.print_test(nSpace);
			system("pause");
		}

		int recur_sum(int nNumber){
			if (nNumber > 1){
				return nNumber + recur_sum(nNumber - 1);
			}
				
			else{
				return nNumber;
			}
		}

		//extern int nA;
		//void fn()

		//{

		//	nA++;

		//	cout << nA << endl;

		//}

}
