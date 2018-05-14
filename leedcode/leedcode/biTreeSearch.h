/**
* <!--
* File   : biTreeSearch.h
* Author : fancy
* --!>
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstdlib>
#include <Stack>
#include <Queue>
using namespace std;
#define Element char
#define format "%c"

//此处要注意：不能取名为Node,因为与系统的Node或其他的定义的模板Node有重名，会出现一些莫名其妙的错误
typedef struct xNode{
	Element data;
	xNode *lchild;
	xNode *rchild;
} * Tree;


int index = 0;  //全局索引变量

//二叉树构造器,按先序遍历顺序构造二叉树
//无左子树或右子树用'#'表示
void treeNodeConstructor(Tree &root, Element data[]){
	Element e = data[index++];
	if (e == '#'){
		root = NULL;
	}
	else{
		root = (xNode *)malloc(sizeof(xNode));
		root->data = e;
		treeNodeConstructor(root->lchild, data);  //递归构建左子树
		treeNodeConstructor(root->rchild, data);  //递归构建右子树
	}
}

//深度优先遍历
void depthFirstSearch(Tree root){
	stack<xNode *> nodeStack;  //使用C++的STL标准模板库
	nodeStack.push(root);
	xNode *node;
	while (!nodeStack.empty()){
		node = nodeStack.top();
		printf(format, node->data);  //遍历根结点
		nodeStack.pop();
		if (node->rchild){
			nodeStack.push(node->rchild);  //先将右子树压栈
		}
		if (node->lchild){
			nodeStack.push(node->lchild);  //再将左子树压栈
		}
	}
}

//广度优先遍历
void breadthFirstSearch(Tree root){
	queue<xNode *> nodeQueue;  //使用C++的STL标准模板库
	nodeQueue.push(root);
	xNode *node;
	while (!nodeQueue.empty()){
		node = nodeQueue.front();
		nodeQueue.pop();
		printf(format, node->data);
		if (node->lchild){
			nodeQueue.push(node->lchild);  //先将左子树入队
		}
		if (node->rchild){
			nodeQueue.push(node->rchild);  //再将右子树入队
		}
	}
}