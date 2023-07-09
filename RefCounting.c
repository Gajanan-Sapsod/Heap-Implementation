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


void dfs( int ref[], Node *adjlist[], int source)
{
    Node *t=adjlist[source];
    ref[source]++;
    
    if(t==NULL)
    {
        return ;
    }
    while(t!=NULL)
    {
        if(!ref[t->key])
        {
            //printf("%d\n", t->key);
            dfs( ref, adjlist, t->key);
        }
        t=t->next;

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
    int ref[N];
    for(int i=0;i<N;i++)
    {
        ref[i]=0;
    }
    dfs(ref, adjlist, 5);
    dfs(ref, adjlist, 1);
    printf("garbage nodes are\n");
    for(int i=0;i<N;i++)
    {
        if(ref[i]==0)
        {
            printf("%d\t", i);
        }
    }
}
