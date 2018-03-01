#include <iostream>
#include <fstream>

using namespace std;

void fstropen();
void testcoutcin();

#define common_dir "..\\..\\common\\"
#define infile "infile.txt"
#define outfile "outfile.txt"

int main() {

//	testcoutcin();
	fstropen();

    return 0;
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