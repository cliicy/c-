#pragma once
#include <stdio.h>

namespace LeetCode{

struct TreeNodeLeet {
	int val;
	TreeNodeLeet* left;
	TreeNodeLeet* right;
	TreeNodeLeet(int x) :val(x), left(NULL), right(NULL) {}
};

class leetcode
{
public:
	leetcode();
	~leetcode();
};
}//namespace LeetCode
