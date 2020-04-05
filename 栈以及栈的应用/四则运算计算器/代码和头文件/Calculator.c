#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5
#define MAXSIZE 100


int i=0;             //字符数组下标
char str[MAXSIZE];   //存放后缀表达式

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

//浮点栈，存放后缀表达式求值结果
typedef struct Stack_double
{
    double *base;
    double *top;
    int stackSize;
}Stack_double;

//初始化栈
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

//计算栈的长度
int stackLength_char(Stack_char S)
{
    return (S.top - S.base);
}

int stackLength_double(Stack_double S)
{
    return (S.top - S.base);
}

//入栈 
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

//出栈 
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

//获取栈顶元素进行比较 
Status getTop_char(Stack_char S, char *e)
{
    if(S.top == S.base) return ERROR;
    pop_char(&S, e);
    push_char(&S, *e);
    return SUCCESS;
}

/* 中缀表达式转后缀表达式 */
void transform(Stack_char S)
{
    char b,c; 
    int j;

    printf("请输入中缀表达式，以#表示输入结束: ");
    while(c != '#')
    {
        //如果字符为数字，直接输出
        if((c >= '0' && c <= '9') || c == '.') 
        {
            str[i++] = c;
        }
        //若输入字符为 + 或者 - 
		//当栈顶为 ( 或者 为空时，直接入栈
		//当栈顶的优先级大于等于该符号时，将栈顶输出，然后才把该符号入栈 
        else if('+' == c || '-' == c)
        {
            getTop_char(S, &b);
            if(stackLength_char(S) == 0 || '(' == b)
            {
                push_char(&S, c);
                str[i++] = ' ';   //栈中每入栈一次，字符数组添加一个空格 
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
        //如果输入字符为 * 或者 / 若栈为空或者栈顶为 ( 直接入栈 
        //若栈顶字符等于或者大于该优先级 ,将栈顶的符号输出 						   
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
        //如果输入字符为 '(' 直接入栈  
        else if('(' == c)
        {
            push_char(&S, c);
        }
        //如果输入字符为 ')' 则将栈里的东西全部出栈，并输出 
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
    //最后将栈中的所有字符全部出栈并输出
    while(stackLength_char(S) != 0)
    {
        pop_char(&S, &b);
        str[i++] = ' ';
        str[i++] = b;
    }

    //打印后缀表达式
    printf("\n后缀表达式为："); 
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
        while((c >= '0' && c <= '9') || c == '.')//设置缓冲区，将输入的字符可以转换成小数 
        {
            str2[k] = c;
            str2[++k] = '\0';//atof()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上 
							//数字或正负号才开始和做转换，而在遇到是非数字或者字符串0才结束转换
            
			c = str[++j];
            if(' ' == c)
            {
                d = atof(str2);// 将字符转换为double型 要用 ctype 头文件 
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
                push_double(&S, b-a);//先进后出 
                break;
            case '*':
                pop_double(&S, &a);
                pop_double(&S, &b);
                push_double(&S, b*a);
                break;
            case '/':
                pop_double(&S, &a);
                pop_double(&S, &b);
                if(0 == a) printf("错误，除数不能为零！\n");
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
	    
	    printf("\n计算结果为: %f\n\n", Calculate(S2, str));
			
	}
    
    return 0;
}



