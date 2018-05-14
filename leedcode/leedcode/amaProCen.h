#include <unordered_map>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

namespace amazonStorageCenter{
typedef unordered_map<string, string> stringmap;
stringmap merge(stringmap a, stringmap b){
	stringmap temp(a);
	temp.insert(b.begin(), b.end());
	return temp;
}

//亚马逊设置货物存储中心
/*
分析：其实就是求矩形中某一个点到其他点的距离加权最小



方法一：

对每一个点求其到其他点的加权距离，然后比较最小。由于有M*N个点，对每一个点求加权距离是O（M*N）的，所以整体时间复杂度是O（M*M*N*N）的。

方法二：

首先做预处理，计算每一行有多少个点，每一列有多少个点，然后计算把其他行的点挪到我这一行需要的加权距离，把其他列的点挪到我这一列的加权距离，

然后对每一个点，计算挪到其所在行的代价 + 所在列的代价和，求出最小。时间复杂度O（M*N）。
calcMIN是方法一，calcDiego是方法二
*/
#define MAX_SIZE 500

int arr[MAX_SIZE][MAX_SIZE];
int sumOfRow[MAX_SIZE];
int sumOfCol[MAX_SIZE];
int costOfRow[MAX_SIZE];
int costOfCol[MAX_SIZE];

int rtnRow;
int rtnCol;

void do_stringMap(){
	stringmap first;
	stringmap second({ { "apple", "red" }, { "lemon", "yellow" } });
	stringmap third({ { "orange", "orange" }, { "strawberry", "red" } });
	stringmap fourth(second);
	stringmap fifth(merge(third, fourth));
	stringmap sixth(fifth.begin(), fifth.end());

	cout << "sixth contains:";
	for (auto& x : sixth)
		cout << " " << x.first.c_str() << ":" << x.second.c_str();
	cout << endl;

	//	if (!root){
	//		return res;
	//	}


}

void do_splitString(){
	char string1[] =
		"A string\tof ,,tokens\nand some  more tokens";
	char string2[] =
		"Another string\n\tparsed at the same time.";
	char seps[] = " ,\t\n";
	char *token1 = NULL;
	char *token2 = NULL;
	char *next_token1 = NULL;
	char *next_token2 = NULL;

	printf("Tokens:\n");

	// Establish string and get the first token:
	token1 = strtok_s(string1, seps, &next_token1);
	token2 = strtok_s(string2, seps, &next_token2);

	// While there are tokens in "string1" or "string2"
	while ((token1 != NULL) || (token2 != NULL))
	{
		// Get next token:
		if (token1 != NULL)
		{
			printf(" %s\n", token1);
			token1 = strtok_s(NULL, seps, &next_token1);
		}
		if (token2 != NULL)
		{
			printf("        %s\n", token2);
			token2 = strtok_s(NULL, seps, &next_token2);
		}
	}
}
int calcCost(int row, int col, int x, int y)
{
	int cost = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] != 0)
			{
				cost += (abs(x - i) + abs(y - j)) * arr[i][j];
			}
		}
	}
	return cost;
}

//methord 1
void calcMin(int row, int col)
{
	long long minCost = LLONG_MAX;
	long long tmpCost = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			tmpCost = calcCost(row, col, i, j);
			if (tmpCost < minCost)
			{
				minCost = tmpCost;
				rtnRow = i;
				rtnCol = j;
			}
		}
	}
}


//methord 2 死活想不明白
/*
首先做预处理，计算每一行有多少个点，每一列有多少个点，然后计算把其他行的点挪到我这一行需要的加权距离，把其他列的点挪到我这一列的加权距离，
然后对每一个点，计算挪到其所在行的代价+所在列的代价和，求出最小。时间复杂度O（M*N）。
*/
void calcDiego(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		sumOfRow[i] = 0;
		costOfRow[MAX_SIZE] = 0;
	}

	for (int j = 0; j < col; j++)
	{
		sumOfCol[j] = 0;
		costOfCol[MAX_SIZE] = 0;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sumOfRow[i] += arr[i][j];
			sumOfCol[j] += arr[i][j];
		}
	}


	for (int i = 0; i < row; i++)//cost for moving row j to row i
	{
		for (int j = 0; j < row; j++)
		{
			if (i == j || sumOfRow[j] == 0)
				continue;
			costOfRow[i] += (abs(j - i)) * sumOfRow[j];
		}
	}

	for (int i = 0; i < col; i++)//cost for moving col j to col i
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j || sumOfCol[j] == 0)
				continue;
			costOfCol[i] += (abs(j - i)) * sumOfCol[j];
		}
	}

	int cost = INT_MAX;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (costOfRow[i] + costOfCol[j] < cost)
			{
				cost = (costOfRow[i] + costOfCol[j]);
				rtnRow = i;
				rtnCol = j;
			}
		}
	}

}

void do_setStorageCenter(){
	int i, j;
	int row, col;
	cout << "INT_MAX\t" << INT_MAX << endl;
	cout << (500ULL * 500 * 500000) << endl;
	while (scanf("%d%d", &row, &col) == 2) {
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		//printf("calc\n " );
		//		calcMin(row, col);
		//		printf("%d %d\n", rtnRow, rtnCol);
		calcDiego(row, col);
		printf("%d %d\n", rtnRow, rtnCol);


	}
}

}