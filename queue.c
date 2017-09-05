#include<stdio.h>
#include<malloc.h>
typedef struct node * NODEPTR;
struct node
{int info;
 NODEPTR next;};
NODEPTR list=NULL;
NODEPTR getnode()
{NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    return p;}
void freenode(NODEPTR p)
{free(p);}
void traverse()
{ NODEPTR p;
    p=list;
    while(p!=NULL)
    { printf("%d<- ",p->info);
        p=p->next; }
    printf("\n");}
void insend(int x)
{NODEPTR p,q;
    q=getnode();
    p=getnode();
    q->next=NULL;
    q->info=x;
    if(list==NULL)
    {
        list=q;
    }
    else
    {
        p=list;
    while(p->next!=NULL)
    { p=p->next; }
    p->next=q;
    }
    }
int delbeg()
{ int x;
    NODEPTR p;
    p=list;
    x=p->info;
    list=p->next;
    freenode(p);
    return x;}

main()
{int ch,x,y,d;
    while(1)
    {printf("Enter choice:\n1. INSERT END\n2. DELETE END\n3. TRAVERSE\n4. QUIT\n");
 scanf("%d",&ch);
        switch(ch)
    {   case 1:
        printf("Enter information:\n");
        scanf("%d",&x);
        insend(x);
        break;
        case 2:
        d=delbeg();
        printf("Deleted element is %d\n",d);
        break;
        case 3:
        printf("Your linked list is:\n");
        traverse();
        break;
        case 4:
        exit(1);
        default:
        printf("WRONG CHOICE!!!!");  } }}
