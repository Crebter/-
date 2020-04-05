#include<stdio.h>
#include<stdlib.h>
#include "../head/LinkStack.h"
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
 
Status initLStack(LinkStack *s)//初始化栈
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

Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
	if(!s->top)
		return 3;
	else if(0 == s->count)
		return SUCCESS;
	else
		return ERROR; 		
}

Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
	if(!s->top)	//并未生成栈 
		return 3;
	else if(0 == s->count) //空 
		return ERROR;
	else
	{
		*e = s->top->next->data;
		return SUCCESS;
	}	
			
}

Status clearLStack(LinkStack *s)//清空栈
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

Status destroyLStack(LinkStack *s)//销毁栈
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

Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	if(!s->top)
		return ERROR;
	else
	{
		*length = s->count;
		return SUCCESS;	
	}	
	
}

Status pushLStack(LinkStack *s,ElemType data)//入栈
{
	if(!s->top)
		return ERROR;
	else
	{
		StackNode *p = (StackNode*)malloc(sizeof(StackNode));
		printf("请输入你想要入栈的数据:\n");
		while(1)
		{
			if(0 == scanf("%d",&data))
			{
				fflush(stdin);
				printf("输入无效,请再次输入: ");
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

Status popLStack(LinkStack *s,ElemType *data)//出栈
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


