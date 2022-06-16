#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;

void initializeList()
{
    list = 0;  //initially set to NULL
}

int insertItem(int item) //insert at the beginning of the linked list
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = list ; //point to previous first node
	list = newNode ; //set list to point to newnode as this is now the first node
	return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
	struct listNode *temp, *prev ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) break ;
		prev = temp;
		temp = temp->next ; //move to next node
	}
	if (temp == 0) return NULL_VALUE ; //item not found to delete
	if (temp == list) //delete the first node
	{
		list = list->next ;
		free(temp) ;
	}
	else
	{
		prev->next = temp->next ;
		free(temp);
	}
	return SUCCESS_VALUE ;
}


struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

int insertLast(int item)
{
    //write your codes here
    struct listNode * newNode ,*temp;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	temp = (struct listNode*) malloc (sizeof(struct listNode)) ;
	temp=list;
	printf("hello");
	if(list==0)
    {
        insertItem(item);
    }
    else{

	while(temp->next!=0)
    {
        printf("hello");
        temp=temp->next;
    }
    if(temp->next==0)
    {
        temp->next=newNode;
        (temp->next)->item=item;
        (temp->next)->next=0;
    }
    }
   // free(temp);
}

int insertBefore(int oldItem, int newItem)
{
	//write your codes here
	struct listNode * newNode ,*temp;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	temp = (struct listNode*) malloc (sizeof(struct listNode)) ;
	temp=list;
	while(temp->next->item!=oldItem)
    {
        temp=temp->next;
    }
    if(temp->next->item==oldItem)
    {
        newNode->next=temp->next;
        temp->next=newNode;
        temp->next->item=newItem;
    }

}

int deleteAfter(int item)
{
	//write your codes here
	struct listNode * newNode ,*temp;
	//newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	temp = (struct listNode*) malloc (sizeof(struct listNode)) ;
     temp=list;
	if(searchItem(item)!=0)
    {
       while(temp->next!=0)
       {
           if(temp->item==item)
           {
               temp->next=temp->next->next;
               return 0;
           }
           temp=temp->next;
       }
    }
    else
        printf("not found");
}

int deleteLast()
{
    //write your codes here
    struct listNode * newNode ,*temp;
    temp = (struct listNode*) malloc (sizeof(struct listNode)) ;
     temp=list;

       while(temp->next->next!=0)
       {

           temp=temp->next;
       }
       if(temp->next->next==0)
       {
           temp->next=0;
       }


}



int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. (Add from homework). 5. Print. 6. exit   7.insert last\n");
          printf("8.insert before  9.delete after   10.delete last\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)
        {
            int item;
            scanf("%d", &item);
            insertLast(item);
        }
         else if(ch==8)
        {
            int item1,item2 ;
            scanf("%d %d", &item1,&item2);
            insertBefore(item1,item2);
        }
         else if(ch==9)
        {
            int item1,item2 ;
            scanf("%d",&item1);
            deleteAfter(item1);
        }
        else if(ch==10)
        {
            deleteLast();
        }

    }

}
