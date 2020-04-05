#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5
#define MAXSIZE 100


int i=0;             //�ַ������±�
char str[MAXSIZE];   //��ź�׺���ʽ

typedef enum Status {
	ERROR,
	SUCCESS
} Status;


typedef struct Stack_char
{
    char *base;
    char *top;
    int stackSize;
}Stack_char;

//����ջ����ź�׺���ʽ��ֵ���
typedef struct Stack_double
{
    double *base;
    double *top;
    int stackSize;
}Stack_double;

//��ʼ��ջ
Status initStack_char(Stack_char *S)
{
    S->base = malloc(STACK_INIT_SIZE * sizeof(Stack_char));
    if(!(S->base))
    	return ERROR;
    S->top = S->base;
    S->stackSize = STACK_INIT_SIZE;
    return SUCCESS;
}

Status initStack_double(Stack_double *S)
{
    S->base = malloc(STACK_INIT_SIZE * sizeof(Stack_double));
    if(!(S->base))
    	return ERROR;
    S->top = S->base;
    S->stackSize = STACK_INIT_SIZE;
    return SUCCESS;
}

//����ջ�ĳ���
int stackLength_char(Stack_char S)
{
    return (S.top - S.base);
}

int stackLength_double(Stack_double S)
{
    return (S.top - S.base);
}

//��ջ 
Status push_char(Stack_char *S, char e)
{
    if((S->top - S->base) >= S->stackSize)
    {
        S->base = realloc(S->base, (S->stackSize + STACK_INCREMENT) * sizeof(Stack_char));
        if(!(S->base))
        	return ERROR;
        S->top = S->base + S->stackSize;
        S->stackSize += STACK_INCREMENT;
    }
    *(S->top)++ = e;
    return SUCCESS;
}

Status push_double(Stack_double *S, double e)
{
    if((S->top - S->base) >= S->stackSize)
    {
        S->base = realloc(S->base, (S->stackSize + STACK_INCREMENT) * sizeof(Stack_double));
        if(!(S->base))
        	return ERROR;
        S->top = S->base + S->stackSize;
        S->stackSize += STACK_INCREMENT;
    }
    *(S->top)++ = e;
    return SUCCESS;
}

//��ջ 
Status pop_char(Stack_char *S, char *e)
{
    if(S->top == S->base) return ERROR;
    *e = *--(S->top);
    return SUCCESS;
}

Status pop_double(Stack_double *S, double *e)
{
    if(S->top == S->base) return ERROR;
    *e = *--(S->top);
    return SUCCESS;
}

//��ȡջ��Ԫ�ؽ��бȽ� 
Status getTop_char(Stack_char S, char *e)
{
    if(S.top == S.base) return ERROR;
    pop_char(&S, e);
    push_char(&S, *e);
    return SUCCESS;
}

/* ��׺���ʽת��׺���ʽ */
void transform(Stack_char S)
{
    char b,c; 
    int j;

    printf("��������׺���ʽ����#��ʾ�������: ");
    while(c != '#')
    {
        //����ַ�Ϊ���֣�ֱ�����
        if((c >= '0' && c <= '9') || c == '.') 
        {
            str[i++] = c;
        }
        //�������ַ�Ϊ + ���� - 
		//��ջ��Ϊ ( ���� Ϊ��ʱ��ֱ����ջ
		//��ջ�������ȼ����ڵ��ڸ÷���ʱ����ջ�������Ȼ��ŰѸ÷�����ջ 
        else if('+' == c || '-' == c)
        {
            getTop_char(S, &b);
            if(stackLength_char(S) == 0 || '(' == b)
            {
                push_char(&S, c);
                str[i++] = ' ';   //ջ��ÿ��ջһ�Σ��ַ��������һ���ո� 
            }else
            {
                do
                {
                    pop_char(&S, &b);
                    str[i++] = ' ';
                    str[i++] = b;
                }while(stackLength_char(S) != 0);
                push_char(&S, c);
                str[i++] = ' ';
            }
        }
        //��������ַ�Ϊ * ���� / ��ջΪ�ջ���ջ��Ϊ ( ֱ����ջ 
        //��ջ���ַ����ڻ��ߴ��ڸ����ȼ� ,��ջ���ķ������ 						   
        else if('*' == c || '/' == c)
        {
            getTop_char(S, &b);
            if(stackLength_char(S) == 0 || '(' == b)
            {
                push_char(&S, c);
                str[i++] = ' ';
            }else
            {
                if('*' == b || '/' == b)
                {
                    pop_char(&S, &b);
                    str[i++] = ' ';
                    str[i++] = b;
                    push_char(&S, c);
                    str[i++] = ' ';
                }else
                {
                    push_char(&S, c);
                    str[i++] = ' ';
                }
            }
        }
        //��������ַ�Ϊ '(' ֱ����ջ  
        else if('(' == c)
        {
            push_char(&S, c);
        }
        //��������ַ�Ϊ ')' ��ջ��Ķ���ȫ����ջ������� 
        else if(')' == c)
        {
            do
            {
                pop_char(&S, &b);
                if(b != '(')
                {
                    str[i++] = ' ';
                    str[i++] = b;
                }
            }while(b != '(');
        }

        scanf("%c", &c);
    }
    //���ջ�е������ַ�ȫ����ջ�����
    while(stackLength_char(S) != 0)
    {
        pop_char(&S, &b);
        str[i++] = ' ';
        str[i++] = b;
    }

    //��ӡ��׺���ʽ
    printf("\n��׺���ʽΪ��"); 
    for(j=0; j<i; ++j)
    {
        printf("%c", str[j]);
    }
    printf("\n");
}



double Calculate(Stack_double S, char str[])
{
    int j=0,k=0;
    char str2[MAXSIZE];
    char c;
    double a,b,d;
    c = str[j];
    while(j <= i)
    {
        while((c >= '0' && c <= '9') || c == '.')//���û���������������ַ�����ת����С�� 
        {
            str2[k] = c;
            str2[++k] = '\0';//atof()��ɨ�����nptr�ַ���������ǰ��Ŀո��ַ���ֱ������ 
							//���ֻ������Ųſ�ʼ����ת�������������Ƿ����ֻ����ַ���0�Ž���ת��
            
			c = str[++j];
            if(' ' == c)
            {
                d = atof(str2);// ���ַ�ת��Ϊdouble�� Ҫ�� ctype ͷ�ļ� 
                push_double(&S, d);
                k = 0;
            }
        }
        switch(c)
        {
            case '+':
                pop_double(&S, &a);
                pop_double(&S, &b);
                push_double(&S, b+a);
                break;
            case '-':
                pop_double(&S, &a);
                pop_double(&S, &b);
                push_double(&S, b-a);//�Ƚ���� 
                break;
            case '*':
                pop_double(&S, &a);
                pop_double(&S, &b);
                push_double(&S, b*a);
                break;
            case '/':
                pop_double(&S, &a);
                pop_double(&S, &b);
                if(0 == a) printf("���󣬳�������Ϊ�㣡\n");
                else push_double(&S, b/a);
                break;
        }
        c = str[++j];
    }


    pop_double(&S, &d);
    return d;
}



int main()
{
	while(1)
	{
		Stack_char S1;
	    Stack_double S2;
	    
	    initStack_char(&S1);
	    transform(S1);
	
	    initStack_double(&S2);
	    
	    printf("\n������Ϊ: %f\n\n", Calculate(S2, str));
			
	}
    
    return 0;
}



