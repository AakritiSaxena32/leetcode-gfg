/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode *p)
{
    struct ListNode* curr=p, *prev=NULL, *temp=NULL;
    if(p==NULL || p->next==NULL)
    {
        return p;
    }
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
} 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* p1=l1, *p2=l2, *result=NULL, *temp=NULL;
    p1=reverse(p1);
    p2=reverse(p2); 
    int sum, carry=0;
    while(p1!=NULL || p2!=NULL || carry)
    {
        sum=carry;
        if(p1!=NULL)
        {
            sum+=p1->val;
            p1=p1->next;
        }

        if(p2!=NULL)
        {
            sum+=p2->val;
            p2=p2->next;
        }

        struct ListNode* newNode=(struct ListNode* )malloc(sizeof(struct ListNode));
        newNode->val=sum%10;
        carry=sum/10;
        newNode->next=NULL;

        if(result==NULL && temp==NULL)
        {
            result=temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }
    return reverse(result);   
}