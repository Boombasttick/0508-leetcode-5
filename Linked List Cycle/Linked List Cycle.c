/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
    {
        return 0;
    }
    struct ListNode* res = head;
    struct ListNode* tem = head->next;
    while (res != tem)
    {
        if (tem == NULL || tem->next == NULL)
        {
            return 0;
        }
        res = res->next;
        tem = tem->next->next;
    }
    return 1;
}

void addcontact(struct ListNode* pb,int* arr)
{
    int i=0;
    struct ListNode* pre = pb;
    pb->val=arr[0];
    for (i=1;i<4;i++){
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = arr[i];
        temp->next = NULL;
        pb->next =  temp;
        pb = pb->next;
    }
    pb->next = pre->next;
}

int main(){
    int arr1[] = {3,2,0,-4};
    // int arr2[] = {1,3};
    struct ListNode l1;
	// struct ListNode l2;
    addcontact(&l1,arr1);
    // addcontact(&l2,arr2);
    //struct ListNode* l3 = hasCycle(&l1);
    int a = hasCycle(&l1);
    printf("%d",a);
    return 0;
}