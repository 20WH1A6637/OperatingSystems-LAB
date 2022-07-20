#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
struct list
{
    int seg;
    int base;
    int limit;
    struct list *next;
};
struct list *p;
void insert(struct list *q,int base,int limit,int seg)
{
    if(p==NULL)
    {
        p = (struct list*)malloc(sizeof(struct list));
        p->limit=limit;
        p->base=base;
        p->seg=seg;
        p->next=NULL;
    }
    else
    {
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=(struct list*)malloc(sizeof(struct list));
        q->next ->limit=limit;
        q->next ->base=base;
        q->next ->seg=seg;
        q->next ->next=NULL;
    }
}
int find(struct list *q,int seg)
{
    while(q->seg!=seg){
        q=q->next;
    }
    return q->limit;
}
int search(struct list *q,int seg)
{
    while(q->seg!=seg){
        q=q->next;
    }
    return q->base;
}
int main()
{
    p=NULL;
    int seg,offset,limit,base,c,s,physical;
    printf("Enter segment table\n");
    printf("Enter -1 as segment value for termination\n");
    do
    {
        printf("Enter segment number");
        scanf("%d",&seg);
        if(seg!=-1)
        {
            printf("Enter base value:");
            scanf("%d",&base);
            printf("Enter value for limit:");
            scanf("%d",&limit);
            insert(p,base,limit,seg);
        }
    } while(seg!=-1);
    printf("Enter offset:");
    scanf("%d",&offset);
    printf("Enter segmentation number:");
    scanf("%d",&seg);
    c=find(p,seg);
    s=search(p,seg);
    if(offset<c)
    {
        physical=s+offset;
        printf("Address in physical memory %d\n",physical);
    }
    else
    {
        printf("error");
    }
}
/*Output
Enter segment table
Enter -1 as segment value for termination
Enter segment number1
Enter base value:1
Enter value for limit:3
Enter segment number2
Enter base value:4
Enter value for limit:18
Enter segment number-1
Enter offset:3
Enter segmentation number:1
error
Enter segment table
Enter -1 as segment value for termination
Enter segment number1
Enter base value:1
Enter value for limit:4
Enter segment number2
Enter base value:5
Enter value for limit:19
Enter segment number-1
Enter offset:10
Enter segmentation number:2
Address in physical memory 15
*/
