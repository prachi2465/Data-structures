#include<stdio.h>
#include<malloc.h>
typedef struct node * NODEPTR;
struct node
{
 int info;
 NODEPTR next;
};
NODEPTR list=NULL;

NODEPTR getnode()
{
 NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    return p;
}

void freenode(NODEPTR p)
{
 free(p);
}

void insbeg(int x)
{
 NODEPTR p;
    p=getnode();
    p->info=x;
    p->next=list;
    list=p;
}

void traverse()
{
 NODEPTR p;
    p=list;
    while(p!=NULL)
    { 
     printf("%d-> ",p->info);
        p=p->next;
    }
    printf("\n");
}

void insend(int x)
{
 NODEPTR p,q;
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
    { 
     p=p->next;
    }
    p->next=q;
    }
    }

int delbeg()
{ 
 int x;
    NODEPTR p;
    p=list;
    x=p->info;
    list=p->next;
    freenode(p);
    return x;
}

int delend()
{
 int x;
    NODEPTR p,q;
    p=list;
    x=p->info;
    while(p->next!=NULL)
    { 
     q=p;
        p=p->next; 
    }
    q->next=NULL;
    freenode(p);
    return x;
}

void insaft(int x,int y)
{
 NODEPTR p,q;
    p=list;
    q=getnode();
    while(p->info!=y)
    { p=p->next;}
    q->next=p->next;
    p->next=q;
    q->info=x;
}

int delaft(int y)
{
 int x;
    NODEPTR p,q;
    p=list;
    q=getnode();
    while(p->info!=y)
    { p=p->next;  }
    q=p->next;
    x=q->info;
    p->next=q->next;
    freenode(q);
    return x;
}

main()
{
 int ch,x,y,d;
    while(1)
    {printf("Enter choice:\n1. INSERT BEGINNING\n2. INSERT END\n3. INSERT AFTER\n4. DELETE BEGINNING\n5. DELETE END\n6. DELETE AFTER\n7. TRAVERSE\n8. QUIT\n");
 scanf("%d",&ch);
        switch(ch)
    {case 1:
        printf("Enter information:\n");
        scanf("%d",&x);
        insbeg(x);
        break;
        case 2:
        printf("Enter information:\n");
        scanf("%d",&x);
        insend(x);
        break;
        case 3:
        printf("Enter information:\n");
        scanf("%d",&x);
        printf("After which node you want to insert information:\n");
        scanf("%d",&y);
        insaft(x,y);
        break;
        case 4:
        d=delbeg();
        printf("Deleted element is %d\n",d);
        break;
        case 5:
        d=delend();
        printf("Deleted element is %d\n",d);
        break;
        case 6:
        printf("After which node you want to delete information:\n");
        scanf("%d",&y);
        d=delaft(y);
        printf("Deleted element is %d\n",d);
        break;
        case 7:
        printf("Your linked list is:\n");
        traverse();
        break;
        case 8:
        exit(1);
        default:
        printf("WRONG CHOICE!!!!");  } }}

