#include "../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>

void menu(){
 	system("CLS");
 	printf("****************栈的演示*****************\n");
    printf("*   1.初始化栈           5.销毁栈       *\n");
    printf("*   2.判断栈是否为空     6.检测栈长度	*\n");
    printf("*   3.得到栈顶元素       7.入栈         *\n");
    printf("*   4.清空栈           	 8.出栈    	*\n");
    printf("****************************************\n");
    printf("请选择您的操作："); 
 }

Status initStack(SqStack *s,int sizes)//初始化栈
{
	if(s->elem)
	{
		return ERROR;
	}		
	else
	{	
		printf("请输入你要生成的栈的大小:\n");
		while(1)
		{
			if(0 == scanf("%d",&sizes))	
			{
				fflush(stdin);
				printf("输入无效,请再次输入: ");
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

Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if(!s->elem)
		return 3;
	else if(-1 == s->top)
		return SUCCESS;
	else
		return ERROR;		 
}	

Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
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

Status clearStack(SqStack *s)//清空栈
{
	if(!s->elem)
		return ERROR;//先初始化 
	else
	{
		s->top = -1;
		return SUCCESS;	
	}	
}

Status destroyStack(SqStack *s)//销毁栈
{
	if(!s->elem)
		return ERROR;//先初始化
	else
	{	
		//free(s->elem);
		free(s);
		s->elem = NULL;
		return SUCCESS;	
	}	
	 
}

Status stackLength(SqStack *s,int *length)//检测栈长度
{
	if(!s->elem)
		return ERROR;
	else
	{
		*length = s->top + 1;
		return SUCCESS;	
	}	
}

Status pushStack(SqStack *s,ElemType data)//入栈
{
	if(!s->elem)
		return 3;
	else if(s->top == s->size-1)//栈满了 
	{
		return ERROR;		
	}
	else
	{	
		printf("请输入你想要入栈的数据：\n");
		while(1)
		{
			if(0 == scanf("%d",&data))
			{
				fflush(stdin);
				printf("输入无效,请再次输入: ");
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

Status popStack(SqStack *s,ElemType *data)//出栈
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
