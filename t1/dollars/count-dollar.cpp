#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "..\t1\Node.h"
#include "..\t1\stack.h"
#include "..\t1\queue.h"

using namespace std;
using namespace linkedlistofclasses;
using namespace stacksavitch;
using namespace queuesavitch;


#define common_dir "..\\..\\common\\"
#define infile "infile.txt"
#define outfile "outfile.txt"

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array)/sizeof(array[0]));
}


void fstropen();
void testcoutcin();
void multiplyBigInt();
void multiplyBigIntEx();
void head_insert(NodePtr& head, int the_number);

void demo_head_insert();
void do_stack();
void do_queue();

void do_vector();
void do_vector2();


class CExample {
private:
	int a;
public:
	CExample(int b){
		a = b;
	}

	CExample(const CExample& C) {
		a = C.a;
	}
	void Show()
	{
		cout << a << endl;
	}
};


class CA {
public:
	CA(int b, char* cstr){
		a = b;
		str = new char[b];
		strcpy(str, cstr);
	}

	CA(const CA& C) {
		a = C.a;
		str = new char[a];
		if (str != 0)
			strcpy(str, C.str);
		
	}

	void Show(){
		cout << str << endl;
	}

	~CA() {
		delete str;
	}

	private:
		int a;
		char* str;
};
int main() {

//	testcoutcin();
//	fstropen();
//	multiplyBigInt();
//	demo_head_insert();
//	do_stack();
	do_queue();

//	CExample A(100);
//	CExample B = A;
//	B.Show();

//	CA A(10, "hello!");
//	CA B = A;

//	do_vector();

//	do_vector2();

    return 0;
}

void do_vector() {
	vector<int> vt;
	cout << "Enter a list of positive numbers.\n"
		<< "Place a negative number number at the end.\n";

	int next;
	cin >> next;
	while (next > 0) {
		vt.push_back(next);
		cout << next << " added. ";
		cout << "vt.size() = " << vt.size() << endl;
		cin >> next;
	}


/*	
	
	for (int i = 0; i < 5; i++) {
		vt.push_back(i);
	}
*/
	cout << "will pop the value one by one: ";
	for (unsigned int j = 0; j < vt.size(); j++){
		cout << vt[j] << " ";
	}

}

void do_vector2() {
	vector<char> vt;
	cout << "Enter a list of positive numbers.\n"
		<< "Place a negative number number at the end.\n";

	char next;
	cin >> next;
	while (next != '@') {
		vt.push_back(next);
		cout << next << " added. ";
		cout << "vt.size() = " << vt.size() << endl;
		cin >> next;
	}

	cout << "will pop the value one by one: ";
	for (unsigned int j = 0; j < vt.size(); j++){
		cout << vt[j] << " ";
	}

}


void do_queue() {
	Queue q;
	char next, ans;
	do {
		cout << "Enter a word: ";
		cin.get(next);
		while (next != '\n'){
			q.add(next);
			cin.get(next);
		}
		cout << "you entered: ";
		while (!q.empty())
			cout << q.remove();
		cout << endl;

		cout << "Again?(Y/n): ";
		cin >> ans;
		cin.ignore(1000, '\n');
	} while (ans != 'n' && ans != 'N' );
}


void do_stack(){
	Stack s;
	char next, ans;
	do {
		cout << "enter a word: ";
		cin.get(next);
		while (next != '\n')
		{
			s.push(next);
			cin.get(next);
		}
		cout << "Written backward that is: ";
		while ( !s.empty() ) {
			cout << s.pop();
		}
		cout << endl;

		cout << "Again?(y/n): ";
		cin >> ans;
		cin.ignore(10000, '\n');
	} while (ans != 'n' && ans != 'N');

}


void head_insert(NodePtr& head, int the_number) {
	NodePtr tempNode = new Node(the_number, head);
	head = tempNode;
}

void demo_head_insert() {
	NodePtr head, tmp;
	head = new Node(0, NULL);
	for (int i = 1; i < 5; i++){
		head_insert(head, i);
	}

	//Iterate through the list and display each value
	tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->getData() << endl;
		tmp = tmp->getLink();
	}

	//Delete all nodes in the list before exiting
	tmp = head;
	while (tmp != NULL){
		NodePtr nodeToDel = tmp;
		tmp = tmp->getLink();
		delete nodeToDel;
	}
}

void testcoutcin() {
	int n_25(0), n_10(0), n_5(0), n_total(0), cost_per_person(0);
	cout << n_25 << " " << n_10 << " " << n_5 << " " << cost_per_person << endl;
	cout << "Please input the number of 25 cents:\n";
	cin >> n_25;
	cout << "Please input the number of 10 cents:\n";
	cin >> n_10;
	cout << "Please input the number of 5 cents:\n";
	cin >> n_5;

	n_total = n_25 * 25 + n_10 * 10 + n_5 * 5;
	cout << "The total number of cents:";
	cout << n_total;

	cout << "\njust wait for moment and please input how many seconds to wait!\n";

	cout << "Enter the cost per person: $";
	cin >> cost_per_person;

	cout << "Please input tab and return char:" << "\\t" << "\\n";
}

void fstropen(){
	ifstream in_stream;
	string infiledir = common_dir;

	string in_file = infile;
	string in_dir = common_dir + in_file;
	in_stream.open(in_dir);
	
	ofstream out_stream;
	string out_file = outfile;
	out_stream.open(common_dir + out_file);

	int data1(0), data2(0), data3(0);
	in_stream >> data1 >> data2 >> data3;
	out_stream << data1 + data2 + data3;
	in_stream.close();
	out_stream.close();


}

void multiplyBigInt(){
	float fInt1(0),fInt2(0);
	cout << "Please input big Integer1:" << endl;
	cin >> fInt1;
	cout << "Please input big Integer2:" << endl;
	cin >> fInt2;
	cout << "The result is: " << fInt1*fInt2 << endl;
	cout << "Please check.....";
}

//如何求2个大数的乘积
void multiplyBigIntEx(){
	//char num1[100];
	//char num2[100];

	int num1[100];
	int num2[100];
	int tempRes[100];
	cout << "Please input big Integer1:" << endl;
	cin >> num1[0];
	cout << "Please input big Integer2:" << endl;
	cin >> num2[0];
	int nlen1 = getArrayLen(num1);
	int nlen2 = getArrayLen(num2);
	int tempResLen = nlen1;
	int ncarry = 0;
	cout << "num1's length:" <<nlen1;
	cout << "num2's length:" << nlen2;
	/**
	for (int p2 = nlen2 - 1; p2 >= 0; p2--) {
		for (int p1 = nlen1 - 1; p1 >= 0;p1--) {
			int res = num1[p2] * num1[p1] + ncarry;
			tempRes[tempResLen--] = res % 10;
			ncarry = res / 10;
		}
		//tempRes[tempResLen] = Char(ncarry);
		//tempResLen = nlen1;
		//ncarry = 0;
	}
	**/
	cout << "Please check.....";
}

//a b 2个对象的子对象以及继承关系



//设计一个转账交易的小程序

//对不知道大小的数组进行排序，如何找到最大的数




string num2str(double i)

{

	stringstream ss;

	ss << i;

	return ss.str();

}

//字符串转数字：

int str2num(string s)

{

	int num;

	stringstream ss(s);

	ss >> num;

	return num;

}

/*
String BigNumMultip(String bigNum1, String bigNum2){

	if (bigNum1 == null || bigNum2 == null){
		return "输入有误";
	}
	if (bigNum1 == "0" || bigNum2 == "0"){
		return "0";
	}

	//将传进来的字符串参数转为字符数组并反转数组
	char[] num1 = new StringBuffer(bigNum1).reverse().toString().toCharArray();
	char[] num2 = new StringBuffer(bigNum2).reverse().toString().toCharArray();

	for (int i = 0; i<num1.length; i++){
	>'9'){
		return "输入的数字不能含有非法字符";
	}
	}
	for (int i = 0; i<num2.length; i++){
	>'9'){
		return "输入的数字不能含有非法字符";
	}
	}

	int resultLen = num1.length + num2.length; //结果的长度
	int[] result = new int[resultLen];

	for (int j = 0; j<num1.length; j++){
		i = "0;i<num2.length;i++){" int = "" resultstr = "new" stringbuffer = "" >= 0; i--){
			resultStr.append(result[i]);
		}

		return resultStr.toString();
	}< / num1.length; j++){>< / num2.length; i++){>< / num1.length; i++){>
	*/