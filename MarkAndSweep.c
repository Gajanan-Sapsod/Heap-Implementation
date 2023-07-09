#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct node
{
    int key;
    struct node *next;
}Node;

Node *createnode(int data)
{
    Node *nptr=(Node *)malloc(sizeof(Node));
    nptr->key=data;
    nptr->next=NULL;
    return nptr;

}

void addnode(Node *arr[],int n1,  int n2)
{
    Node *t=arr[n1];
    Node *n=createnode(n2);
    if(t==NULL)
    {
        arr[n1]=n;

    }
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=n;
        n->next=NULL;
    }
}

int getnode(Node *root[], int a, int b)
{
       Node *t=root[a];
       int retval=0;
       if(t==NULL)
       {
          retval=0;
       }
       else
       {
        while(t!=NULL && retval==0)
        {
            if(t->key==b)
            {
                retval=1;
            }
            t=t->next;

        }
       }
       return retval;
}
//stack implemetation using linkedlist 
typedef  int item_type ;
typedef enum {False, True} boolean;
typedef struct node_tag
{
    item_type data;
    struct node_tag *next;
}sNode;
typedef struct stack_tag
{
    sNode *top;
}stack;
void initialise(stack *sptr)
{
    sptr->top=NULL;
}
void push(stack *sptr, item_type d)
{
    sNode *nptr=(sNode *)malloc(sizeof(sNode));
    nptr->data=d;
    nptr->next=sptr->top;
    sptr->top=nptr;
}
boolean isempty(stack *sptr)
{
    return !(sptr->top);//will return true if top is null
}
item_type top(stack *sptr)
{
    if(sptr->top!=NULL)
    return sptr->top->data;
    return -1;
}
void pop(stack *sptr)
{
    if(isempty(sptr))
    {
        printf("stack is already empty");

    }
    else{
    sNode *ptr=sptr->top;
    sptr->top=sptr->top->next;
    free(ptr);
    }
}
void dfs( int visit[], Node *adjlist[], int source)
{
    stack s;
    initialise(&s);
    push(&s, source);
    visit[source]++;

    while(!isempty(&s))
    {
        int i=top(&s);
        pop(&s);
        visit[i]=1;
        Node *t=adjlist[i];    

        while(t!=NULL)
        {
            if(!visit[t->key])
            {
                push(&s,t->key);
            }
            t=t->next;
        }

    }
    
    
    
}
int main()
{
    Node * adjlist[N];
    
    for(int i=0;i<N;i++)
    {
        adjlist[i]=NULL;
    }
    printf("How many edges\n");
    int n;
    scanf("%d", &n);
    int n1, n2;
    printf("Enter the value of node1 and node2, node1 is pointing to node2\n ");

    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &n1, &n2);
        addnode(adjlist, n1, n2);
    }
    /*
    //printing adjacency matrix for root1
    int arr[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            arr[i][j]=0;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
           if(getnode(adjlist, i, j))
           {
            arr[i][j]=1;
           }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
          printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    */
    int visit[N];
    for(int i=0;i<N;i++)
    {
        visit[i]=0;
    }
    dfs(visit, adjlist, 5);
    dfs(visit, adjlist, 1);
    printf("garbage nodes are\n");
    for(int i=0;i<N;i++)
    {
        if(visit[i]==0)
        {
            printf("%d\t", i);
        }
    }
}
