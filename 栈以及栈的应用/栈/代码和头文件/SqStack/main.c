#include <stdio.h>
#include <stdlib.h>
#include "../head/SqStack.h"

int main() 
{
	restart:;
	menu();
	//SqStack *s = (SqStack *)malloc(sizeof(SqStack));
	SqStack s;
	s.elem = NULL;
	int choice,judge,sizes,length;
	ElemType data;
	while(scanf("%d",&choice) != EOF)
	{
		
		
		fflush(stdin);
		choice =(char)(choice + 96);
		switch(choice)
		{
			case 'a':
				judge = initStack(&s,sizes);
				if(judge == SUCCESS)
					printf("初始化成功！\n");
				else
					printf("初始化失败！\n");
				Sleep(1000);
				menu();
				break;
			case 'b':
				judge = isEmptyStack(&s);
				if(3 == judge)
					printf("请先初始化栈！\n");
				else if(SUCCESS == judge)
					printf("栈为空！\n");
				else 
					printf("栈不为空\n");
				Sleep(1000);
				menu();
				break;
			case 'c':
				judge = getTopStack(&s,&data); 				
				if(3 == judge)
					printf("请先初始化栈！\n");
				else if(SUCCESS == judge)
					printf("栈顶元素为%d\n",data);
				else 
					printf("栈为空,请先把数据入栈\n");		
				Sleep(1000);
				menu();
				break;
			case 'd':
				judge = clearStack(&s);
				if(SUCCESS == judge)
					printf("清空成功！\n");
				else 
					printf("请先初始化栈！\n");		
				Sleep(1000);
				menu();
				break;
			case 'e':
				judge = destroyStack(&s);
				if(SUCCESS == judge)
					printf("销毁成功！\n");
				else 
					printf("请先初始化栈！\n");		
				Sleep(1000);
				menu();
				break;
			case 'f':
				judge =	stackLength(&s,&length);	
				if(SUCCESS == judge)
					printf("获取成功，栈的长度为：%d\n",length);
				else 
					printf("请先初始化栈！\n");		
				Sleep(1000);
				menu();
				break;
			case 'g':
				judge = pushStack(&s,data);
				if(3 == judge)
					printf("请先初始化栈！\n");
				else if(SUCCESS == judge)
					printf("入栈成功!");
				else 
					printf("栈满了！\n");		
				Sleep(1000);
				menu();
				break;
			case 'h':
				judge = popStack(&s,&data);								 
				if(judge == 3)
					printf("请先初始化栈！\n");
				else if(SUCCESS == judge)
					printf("出栈成功，该数据为%d\n",data);
				else if(ERROR == judge)
					printf("栈为空！\n");	
				Sleep(1000);
				menu();
				break;
			default:
				printf("您的输入有误！\n");
				Sleep(1000);
				menu();
				goto restart;	
			
		}
		
		
	}
	
	
	return 0;
}
