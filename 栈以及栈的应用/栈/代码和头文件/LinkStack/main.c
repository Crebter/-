#include <stdio.h>
#include <stdlib.h>
#include "../head/LinkStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	restart:;
	
	menu();
	LinkStack s;
	s.top = NULL;
	int choice,judge,sizes,length;
	ElemType data;
	while(scanf("%d",&choice) != EOF)
	{
		fflush(stdin);
		choice =(char)(choice + 96);
		switch(choice)
		{
			case 'a':
				judge = initLStack(&s);
				if(judge == SUCCESS)
					printf("��ʼ���ɹ���\n");
				else
					printf("��ʼ��ʧ�ܣ�\n");
				Sleep(1000);
				menu();
				break;
			case 'b':
				judge = isEmptyLStack(&s);
				if(3 == judge)
					printf("���ȳ�ʼ��ջ��\n");
				else if(SUCCESS == judge)
					printf("ջΪ�գ�\n");
				else 
					printf("ջ��Ϊ��\n");
				Sleep(1000);
				menu();
				break;
			case 'c':
				judge = getTopLStack(&s,&data); 				
				if(3 == judge)
					printf("���ȳ�ʼ��ջ��\n");
				else if(SUCCESS == judge)
					printf("ջ��Ԫ��Ϊ%d\n",data);
				else 
					printf("ջΪ��,���Ȱ�������ջ\n");		
				Sleep(1000);
				menu();
				break;
			case 'd':
				judge = clearLStack(&s);
				if(SUCCESS == judge)
					printf("��ճɹ���\n");
				else if(ERROR == judge)
					printf("���ȳ�ʼ��ջ��\n");
				else if(3 == judge)
					printf("ջ�Ѿ�Ϊ�գ�\n");		
				Sleep(1000);
				menu();
				break;
			case 'e':
				judge = destroyLStack(&s);
				if(SUCCESS == judge)
					printf("���ٳɹ���\n");
				else 
					printf("���ȳ�ʼ��ջ��\n");		
				Sleep(1000);
				menu();
				break;
			case 'f':
				judge = LStackLength(&s,&length);	
				if(SUCCESS == judge)
					printf("��ȡ�ɹ���ջ�ĳ���Ϊ��%d\n",length);
				else 
					printf("���ȳ�ʼ��ջ��\n");		
				Sleep(1000);
				menu();
				break;
			case 'g':
				judge = pushLStack(&s,data);
				if(3 == judge)
					printf("���ȳ�ʼ��ջ��\n");
				else if(SUCCESS == judge)
					printf("��ջ�ɹ���");
				else 
					printf("ջ���ˣ�\n");		
				Sleep(1000);
				menu();
				break;
			case 'h':
				judge = popLStack(&s,&data);								 
				if(judge == 3)
					printf("���ȳ�ʼ��ջ��\n");
				else if(SUCCESS == judge)
					printf("��ջ�ɹ���������Ϊ%d\n",data);
				else if(ERROR == judge)
					printf("ջΪ�գ�\n");		
				Sleep(1000);
				menu();
				break;
			default:
				printf("������������\n");
				Sleep(1000);
				menu();
				goto restart;	
			
		}
		
		
	}
	return 0;
}

