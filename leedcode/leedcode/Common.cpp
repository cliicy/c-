#include "Common.h"
#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h>

static int gEightQueen[8] = { 0 };
static int gCount = 0;

/**
����������������˻ʺ�
�����ǽ��˻ʺ�ĸ������
��ӡ����������
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
������������ж���һ���ʺ��λ�Ƿ�
�ǿ��е�
loop������ǵڼ����ʺ�
value������ǻʺ��λ��
*/
int is_OK(int loop, int value){
	int index, data;
	//�����ǽ�ǰ��Ļʺ󶼱���һ�Σ�  
	//��֤ÿ���ʺ󶼲��ܳԵ���һ���ʺ�  
	for (index = 0; index<loop; index++){
		data = gEightQueen[index];
		//��һ���ʺ���������ʺ�����·�  
		if (data == value){
			return 0;
		}
		//��һ���ʺ���������ʺ�����½�  
		if ((index + data) == (loop + value)){
			return 0;
		}
		//��һ���ʺ���������ʺ�����½�  
		if ((index - data) == (loop - value)){
			return 0;
		}

	}
	return 1;

}
/**
������������Իʺ���м���
index���ӵڼ����ʺ�ʼ(�ӵڼ��п�ʼ)
*/
void eight_queue(int index){
	int loop;
	//��������������˸��ʺ�  
	for (loop = 0; loop<8; loop++){
		//�����жϵ�index���ʺ���loopλ���Ƿ����  
		if (is_OK(index, loop)){
			//������оͽ��ṹ��¼�����ȫ��������  
			gEightQueen[index] = loop;
			if (7 == index){
				//��ӡ����ȫ�ֱ�������һ��  
				gCount++;
				print_queen();
				//��index����ʺ���գ�������һ�α���  
				gEightQueen[index] = 0;
				return;
			}
			//����ʹ���˵ݹ�  
			eight_queue(index + 1);
			//�����ǻ��ݵ�˼��,������һ�α���  
			gEightQueen[index] = 0;
		}

	}

}