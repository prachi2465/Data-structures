#include<stdio.h>
#include<malloc.h>
typedef struct node *NODEPTR;
struct node
{
int info;
NODEPTR next;
};
//NODEPTR list= NULL;
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
void insbeg(NODEPTR *list,int x)
{
    NODEPTR p;
    p=getnode();
    p->info=x;
    p->next=*list;
    *list=p;
}
void traverse(NODEPTR list)
{
    NODEPTR p;
    p=list;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");

}
void delbeg(NODEPTR *list)
{
    NODEPTR p;
    if(*list==NULL)
    {
        printf("Stack underflow!!\n");
    }
    else
    {p=*list;
    *list=p->next;
    freenode(p);}
}
main()
{
    NODEPTR list;
    list=NULL;
    int ch ,x,y;
    while(1)
    {
    printf("Enter choice:\n1. INSERT BEGINNING\n2. DELETE BEGINNING\n3. TRAVERSE\n4. QUIT\n");
    scanf("%d",&ch);

        switch(ch)
    {
        case 1: {printf("Enter information:\n");
        scanf("%d",&x);
        insbeg(&list,x);
        break;}
        case 2:{ delbeg(&list);
        break;}
        case 3: {printf("Your stack is:\n");
        traverse(list);
        break;}
        case 4: exit(1);
        default: printf("WRONG CHOICE!!!!");

    }

    }
}


