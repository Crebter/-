#include "../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>

void menu(){
 	system("CLS");
 	printf("****************ջ����ʾ*****************\n");
    printf("*   1.��ʼ��ջ           5.����ջ       *\n");
    printf("*   2.�ж�ջ�Ƿ�Ϊ��     6.���ջ����	*\n");
    printf("*   3.�õ�ջ��Ԫ��       7.��ջ         *\n");
    printf("*   4.���ջ           	 8.��ջ    	*\n");
    printf("****************************************\n");
    printf("��ѡ�����Ĳ�����"); 
 }

Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	if(s->elem)
	{
		return ERROR;
	}		
	else
	{	
		printf("��������Ҫ���ɵ�ջ�Ĵ�С:\n");
		while(1)
		{
			if(0 == scanf("%d",&sizes))	
			{
				fflush(stdin);
				printf("������Ч,���ٴ�����: ");
			}
			else
			{
				s->elem = (ElemType*)malloc(sizes*sizeof(ElemType)); 
				s->top = -1;
				s->size = sizes;
				return SUCCESS;
			}
		}
		
	}	
		
}

Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(!s->elem)
		return 3;
	else if(-1 == s->top)
		return SUCCESS;
	else
		return ERROR;		 
}	

Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
	if(!s->elem)
		return 3;
	else if(-1 == s->top)
		return ERROR;
	else
	{
		*e = s->elem[s->top];
		return SUCCESS;	
	}		
}

Status clearStack(SqStack *s)//���ջ
{
	if(!s->elem)
		return ERROR;//�ȳ�ʼ�� 
	else
	{
		s->top = -1;
		return SUCCESS;	
	}	
}

Status destroyStack(SqStack *s)//����ջ
{
	if(!s->elem)
		return ERROR;//�ȳ�ʼ��
	else
	{	
		//free(s->elem);
		free(s);
		s->elem = NULL;
		return SUCCESS;	
	}	
	 
}

Status stackLength(SqStack *s,int *length)//���ջ����
{
	if(!s->elem)
		return ERROR;
	else
	{
		*length = s->top + 1;
		return SUCCESS;	
	}	
}

Status pushStack(SqStack *s,ElemType data)//��ջ
{
	if(!s->elem)
		return 3;
	else if(s->top == s->size-1)//ջ���� 
	{
		return ERROR;		
	}
	else
	{	
		printf("����������Ҫ��ջ�����ݣ�\n");
		while(1)
		{
			if(0 == scanf("%d",&data))
			{
				fflush(stdin);
				printf("������Ч,���ٴ�����: ");
			}
			else
			{
				s->top++;
				s->elem[s->top] = data;
				return SUCCESS;
			}
		}
	}
	
		
}

Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if(!s->elem)
		return 3;
	else if(-1 == s->top)
		return ERROR;
	else
	{	
		*data = s->elem[s->top];
		s->top--;
		return SUCCESS;	
	}		
}
