#include<stdio.h>
#include<stdlib.h>
#include "../head/LinkStack.h"
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
 
Status initLStack(LinkStack *s)//��ʼ��ջ
{
	if(s->top)
		return ERROR;
	else
	{
		s->top = (LinkStackPtr)malloc(sizeof(StackNode));
		s->count = 0;
		return SUCCESS;			
	}	
	
}

Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(!s->top)
		return 3;
	else if(0 == s->count)
		return SUCCESS;
	else
		return ERROR; 		
}

Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	if(!s->top)	//��δ����ջ 
		return 3;
	else if(0 == s->count) //�� 
		return ERROR;
	else
	{
		*e = s->top->next->data;
		return SUCCESS;
	}	
			
}

Status clearLStack(LinkStack *s)//���ջ
{
	if(!s->top)
		return ERROR;
	else if(!s->top->next)
		return 3;
	else
	{
		StackNode *q = NULL;
		StackNode *p = s->top->next;
		while(p)
		{
			q = p->next;
			free(p);
			p = q;	
		}
		s->count = 0;
		s->top = NULL;
		return SUCCESS;	
	}

}

Status destroyLStack(LinkStack *s)//����ջ
{
	if(!s->top)
		return ERROR;
	else 
	{
		LinkStackPtr q,p = s->top->next;
		while(s->count != 0)
		{
			q = p->next;
			free(p);
			s->top->next = q;
			s->count--;	
		}
		free(s->top);
		s->top = NULL; 
		return SUCCESS;	
	}	
}

Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	if(!s->top)
		return ERROR;
	else
	{
		*length = s->count;
		return SUCCESS;	
	}	
	
}

Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
	if(!s->top)
		return ERROR;
	else
	{
		StackNode *p = (StackNode*)malloc(sizeof(StackNode));
		printf("����������Ҫ��ջ������:\n");
		while(1)
		{
			if(0 == scanf("%d",&data))
			{
				fflush(stdin);
				printf("������Ч,���ٴ�����: ");
			}
			else
			{
				p->data = data;
				p->next = s->top->next;
				s->top->next = p;
				s->count++;
				return SUCCESS;
			}
			
		}

	}
}

Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	if(!s->top)
	{
		return 3;
	}
	else if(0 == s->count )
	{
		return ERROR;	
	}	
	else{	
		LinkStackPtr q,p = s->top->next;
		*data = p->data;
		q = p->next;
		free(p);
		s->top->next = q;
		s->count--;		
	}
	return SUCCESS;			
		
}


