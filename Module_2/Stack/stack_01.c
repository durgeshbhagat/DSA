#include<stdio.h>

// Using stdlib header file for malloc and free functions.
#include<stdlib.h>

// header for boolean data types true/false
#include <stdbool.h>

#define INT_MIN -9999

// defining a new user-defined
// data type STACK -> mySTACK
typedef struct STACK
{
    int *array;
    int max_size;
    int top;
}mySTACK;


// Operations supported on STACK
mySTACK* init_stack(int max_size);
void push(mySTACK *s, int x);
void show_stack(mySTACK *s);
int pop(mySTACK *s);
int get_top(mySTACK *s);
void delete_stack(mySTACK *s);
bool check_stack_overflow(mySTACK *s);
bool check_stack_underflow(mySTACK *s);


int main()
{
    mySTACK *s1; 
    mySTACK *s2;
    int x;

    printf("Enter size of stack: ");
    int size;
    scanf("%d", &size);

    // Initiliazing the stack by calling init_stack
    s1 = init_stack(size);
    
    int userin;
    while(userin!=4){
        printf("\n---- STACK ----");
        printf("\n(1) Diplay\n(2) Push\n(3) Pop\n(4) Quit\n");
        printf("Enter choice: ");
        scanf("%d", &userin);
        switch(userin){
            case 1:
                show_stack(s1);
                break;
            case 2:
                printf("\nEnter element to push to stack: ");
                int item; 
                scanf("%d", &item);
                push(s1, item);
                break;
            case 3:
                item = pop(s1);
                break;
            case 4:
                printf("\nQuitting...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    // push(s1, 4);
    // push(s1, 1);
    // push(s1, 19);
    // show_stack(s1);
    // x = pop(s1);
    // printf("\nDeleted element is: %d\n", x);
    // show_stack(s1);

    return 0;
}

mySTACK* init_stack(int max_size)
{ 
    mySTACK *s;
    // Allocate memory for stack
    // Type casting the void* pointer return type of malloc to myStack*
    s = (mySTACK*) malloc(sizeof(mySTACK));
    if(s==NULL)
        return NULL;

    // Allocate memory for items array
    // Type casting the void* pointer return type of malloc to int*
    s->array = (int*) malloc(sizeof(int) * max_size);
    // free the stack memory if array memory not allocated
    if(s->array ==NULL)
    {
        free(s);
        return NULL;
    }
    // Assigning the max_size and top
    s->max_size = max_size;
    s->top = -1;
    return s;
    
}

void push(mySTACK *s, int x)
{
    if(check_stack_overflow(s))
        printf("\nSTACK overflow \n");
    else
    {
        s->top +=1;
        s->array[s->top] = x;
        printf("\n%d is added to stack.\n", x);
    }
}

void show_stack(mySTACK *s)
{
    int i;
    printf("\nSTACK elements are: \n");
    for(i=0; i<=s->top; i++)
        printf("%d ", s->array[i]);
    printf("\n");
}

int pop(mySTACK *s)
{
    int x;
    if(check_stack_underflow(s))
    {
        printf("\nSTACK Underflow \n");
        return INT_MIN;
    }
    else
    {
        x = s->array[s->top];
        s->top -=1;
        printf("\n%d is deleted from the stack.\n", x);
        return x;
    }
}

int get_top(mySTACK *s)
{
    int x;
    if(check_stack_underflow(s))
    {
        printf("\nSTACK Underflow \n");
        return INT_MIN;

    }
    else
    {
        x = s->array[s->top];
        return x;
    }
}

bool check_stack_overflow(mySTACK *s)
{
    return (s->max_size -1 == s->top);
}

bool check_stack_underflow(mySTACK *s)
{
    return (s->top ==-1);
}

void delete_stack(mySTACK *s)
{
    if(s)
    {
        if(s->array)
            free(s->array);
        free(s);
    }
}