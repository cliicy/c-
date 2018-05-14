#include "Common.h"
#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h>

static int gEightQueen[8] = { 0 };
static int gCount = 0;

/**
这个函数用来遍历八皇后
作用是将八皇后的各种情况
打印在命令行上
*/
void print_queen(){
	int outer, inner;
	for (outer = 0; outer <8; outer++){
		for (inner = 0; inner < gEightQueen[outer]; inner++)
			printf("* ");

		printf("# ");

		for (inner = gEightQueen[outer] + 1; inner < 8; inner++)
			printf("* ");

		printf("\n");
	}

	printf("=====================================\n");


}
/**
这个函数用来判断下一个皇后的位是否
是可行的
loop：这个是第几个皇后
value：这个是皇后的位置
*/
int is_OK(int loop, int value){
	int index, data;
	//这里是将前面的皇后都遍历一次，  
	//保证每个皇后都不能吃到下一个皇后  
	for (index = 0; index<loop; index++){
		data = gEightQueen[index];
		//下一个皇后不能在这个皇后的正下方  
		if (data == value){
			return 0;
		}
		//下一个皇后不能在这个皇后的右下角  
		if ((index + data) == (loop + value)){
			return 0;
		}
		//下一个皇后不能在这个皇后的左下角  
		if ((index - data) == (loop - value)){
			return 0;
		}

	}
	return 1;

}
/**
这个函数用来对皇后进行计算
index：从第几个皇后开始(从第几行开始)
*/
void eight_queue(int index){
	int loop;
	//这里是用来构造八个皇后  
	for (loop = 0; loop<8; loop++){
		//用来判断第index个皇后在loop位置是否可行  
		if (is_OK(index, loop)){
			//如果可行就将结构记录在这个全局数组中  
			gEightQueen[index] = loop;
			if (7 == index){
				//打印并将全局变量增加一次  
				gCount++;
				print_queen();
				//将index这个皇后清空，方便下一次遍历  
				gEightQueen[index] = 0;
				return;
			}
			//这里使用了递归  
			eight_queue(index + 1);
			//这里是回溯的思想,方便下一次遍历  
			gEightQueen[index] = 0;
		}

	}

}