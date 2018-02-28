#include <iostream>

using namespace std;

int main() {
	int n_25, n_10, n_5,n_total;
	cout<< "Please input the number of 25 cents:\n";
	cin >> n_25;
	cout << "Please input the number of 10 cents:\n";
	cin >> n_10;
	cout << "Please input the number of 5 cents:\n";
	cin >> n_5;

	n_total = n_25*25+n_10*10+n_5*5;
	cout << "The total number of cents:";
	cout << n_total ;
	
	cout << "\njust wait for moment and please input how many seconds to wait!\n";
	
    return 0;
}

