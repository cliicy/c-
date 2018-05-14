#include <sstream>
#include <iostream>

using namespace std;

namespace TrinaryTreeLCA{

	/*
	Trinary complete tree
	求最近的公共祖先 start
	*/
	const int maxDepth = 21;
	long long three[maxDepth], sum[maxDepth];
	void init() {
		three[0] = 1;
		sum[0] = 0;
		for (int i = 1; i<maxDepth; i++)
		{
			three[i] = three[i - 1] * 3;
			sum[i] = sum[i - 1] + three[i];
		}

		for (int i = 0; i < maxDepth; i++)
		{
			cout << three[i] << "\t";
		}
		cout << endl;

		for (int i = 0; i < maxDepth; i++)
		{
			cout << sum[i] << "\t";
		}
		cout << endl;
		//cout << "INT_MAX\t" << INT_MAX <<endl;
	}

	int getfather(long long a) {
		if (a <= 3)
			return 0;
		int i;
		for (i = 0; sum[i]<a; i++)
			;
		i--;
		_int64 tmp = (2 + a - sum[i]) / 3;
		_int64 father = sum[i] - tmp + 1;
		return (int)father;
	}
	int LCP(int a, int b) {
		while (a != b) {
			if (a > b) a = getfather(a);
			else b = getfather(b);
		}
		return a;
	}

	void do_getLCFather(){
		int a, b;
		init();
		while (scanf("%d%d", &a, &b) != EOF) {
			//cnt = 0;  
			int ans = LCP(a, b);
			printf("%d\n", ans);
		}
	}
	/*
	Trinary complete tree
	求最近的公共祖先 end
	*/
}