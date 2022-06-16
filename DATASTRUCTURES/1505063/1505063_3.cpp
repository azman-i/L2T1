#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;
struct listNode * tail;

void initializeList()
{
    list = 0;  //initially set to NULL
	tail = 0;
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

//add required codes to insert item at the beginning, remember to properly set the tail pointer!
int insertItem(int item) //insert at the beginning of the linked list
{
    struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;

    if(list==0){
            newNode->item=item;
            newNode->next=list;
        list=newNode;
        tail=newNode;
    }
    else{
	newNode->item = item ;
	newNode->next = list ; //point to previous first node
	list = newNode ;
	}//set list to point to newnode as this is now the first node
	return SUCCESS_VALUE ;
}
int insertBeforeItem(int oldItem, int newItem)
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

//add required codes to delete item, remember to properly set the tail pointer!

int deleteAfter(int item)
{
      	struct listNode * newNode ,*temp;
	//newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	//temp = (struct listNode*) malloc (sizeof(struct listNode)) ;
     temp=list;
	if(searchItem(item)!=0)
    {
       while(temp->next!=0)
       {
           if(temp->item==item)
           {
               temp->next=temp->next->next;
               if(temp->next==0)
               {
                   tail=temp->next;
               }
               return 0;
           }
           temp=temp->next;
       }
       if(temp->next==0)
       {
           printf("Not deleteable\n");
       }
    }
    else
        printf("not found");

}

int deleteItem(int item)
{
	struct listNode *temp, *prev ;
	temp = list ;
	prev=list; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) break ;
		prev = temp;
		temp = temp->next ; //move to next node
	}
	if (temp == 0) return NULL_VALUE ; //item not found to delete
	if ((temp == list)) //delete the first node
	{
		list = list->next;
		free(temp) ;
	}
	else if ((temp == list)&&(list==tail)) //delete the first node
	{
		list=0;
		tail=0;
		free(temp) ;
	}

	else
	{
		prev->next = temp->next ;
		free(temp);
	}
	return SUCCESS_VALUE ;
}


int insertLast(int item)
{
    //write your codes here

    struct listNode * newNode ,*temp;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	temp = (struct listNode*) malloc (sizeof(struct listNode)) ;
    temp=tail;
    if(list==0)
    {
        //printf("hello");
        insertItem(item);

    }

    else{
 // printf("%d  tail value",tail->item);
    tail->next=newNode;
    newNode->item=item;
    newNode->next=0;
    tail=newNode;
    //printf("%d newnode item  %d tail item",newNode->item,tail->item);
    }
}

int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. (Add from homework). 5. Print. 6. exit. 7.delete after 8.insert last\n");

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
            scanf("%d",&item);
            deleteAfter(item);
        }
        else if(ch==8)
        {
            int item;
            scanf("%d",&item);
           // printf("item inseide");
            insertLast(item);
        }


    }

}
