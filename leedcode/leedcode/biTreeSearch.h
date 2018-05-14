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

//�˴�Ҫע�⣺����ȡ��ΪNode,��Ϊ��ϵͳ��Node�������Ķ����ģ��Node�������������һЩĪ������Ĵ���
typedef struct xNode{
	Element data;
	xNode *lchild;
	xNode *rchild;
} * Tree;


int index = 0;  //ȫ����������

//������������,���������˳���������
//������������������'#'��ʾ
void treeNodeConstructor(Tree &root, Element data[]){
	Element e = data[index++];
	if (e == '#'){
		root = NULL;
	}
	else{
		root = (xNode *)malloc(sizeof(xNode));
		root->data = e;
		treeNodeConstructor(root->lchild, data);  //�ݹ鹹��������
		treeNodeConstructor(root->rchild, data);  //�ݹ鹹��������
	}
}

//������ȱ���
void depthFirstSearch(Tree root){
	stack<xNode *> nodeStack;  //ʹ��C++��STL��׼ģ���
	nodeStack.push(root);
	xNode *node;
	while (!nodeStack.empty()){
		node = nodeStack.top();
		printf(format, node->data);  //���������
		nodeStack.pop();
		if (node->rchild){
			nodeStack.push(node->rchild);  //�Ƚ�������ѹջ
		}
		if (node->lchild){
			nodeStack.push(node->lchild);  //�ٽ�������ѹջ
		}
	}
}

//������ȱ���
void breadthFirstSearch(Tree root){
	queue<xNode *> nodeQueue;  //ʹ��C++��STL��׼ģ���
	nodeQueue.push(root);
	xNode *node;
	while (!nodeQueue.empty()){
		node = nodeQueue.front();
		nodeQueue.pop();
		printf(format, node->data);
		if (node->lchild){
			nodeQueue.push(node->lchild);  //�Ƚ����������
		}
		if (node->rchild){
			nodeQueue.push(node->rchild);  //�ٽ����������
		}
	}
}