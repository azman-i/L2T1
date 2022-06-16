#include<stdio.h>
#include<stdlib.h>

#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}


struct treeNode * searchItem(struct treeNode * node, int item)
{
    if(node==0) return 0;
    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};


struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    if(node==0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return newNode;
    }

    if(node->item==item) return 0; //already an item exists, so return NULL

    if(item<node->item && node->left==0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return newNode;
    }

    if(item>node->item && node->right==0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return newNode;
    }

    if(item<node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}



int calcNodeHeight(struct treeNode * node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}


int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{
    int sum=0;
       if(node==0)
        return 0;
       else
       {
           return 1+getSize(node->left)+getSize(node->right);

       }
}
int calcNodeDepth(struct treeNode * node) //return depth of a node
{
    //write your codes here
    struct treeNode *node1= 0;
    int count=0;
    node1=root;
    while(1)
    {if(node->item<node1->item)
    {
        node1=node1->left;
        count++;
    }
    if(node->item>node1->item)
    {
        node1=node1->right;
        count++;
    }
    if(node->item==node1->item)
    {
        return count;
    }
    }
}


int calculationNode(int item)
{
    struct treeNode * node = 0;
      node=root;
    while(1)
    {if(item<node->item)
    {
        node=node->left;

    }
    if(item>node->item)
    {
        node=node->right;
           }
    if(node->item==item)
    {
        return calcNodeDepth(node);
    }
    }
}

int calcDepth(int item)//return depth of an item in the tree
{
    struct treeNode *node = 0;
    int count=0;
    node=root;
    while(1)
    {if(item<node->item)
    {
        node=node->left;
        count++;
    }
    if(item>node->item)
    {
        node=node->right;
        count++;
    }
    if(node->item==item)
    {
        return count;
    }
    }
}
struct treeNode *getMinItemwithnode(struct treeNode *node)
{
    node=node->right;
    while(node->left!=0)
        node=node->left;
    return node;
}
int deleteItem(struct treeNode * node, int item)
{
    //write your code here, return TRUE, FALSE

    struct treeNode *parent=0;

      if(searchItem(root,item)!=0)
    {if((parent==0)&&(node==0))
        return -1;
        while(1)
        {
            if(item<node->item)
                {
                    parent=node;
                node=node->left;
            }
            if(item>node->item)
                {  parent=node;
                    node=node->right;
                }
            if(item==node->item)
            {

               if((node->left==0)&&(node->right!=0)&&(parent!=0))
               {

                   parent->left=0;
                   parent->right=node->right;
                   break;
               }
               if((node->left==0)&&(node->right!=0)&&(parent==0))
               {
                   root=node->right;
                   break;
               }
                if((node->right==0)&&(node->left!=0)&&(parent!=0))
                {

                    parent->left=node->left;
                    parent->right=0;
                    break;
                }
                if((node->right==0)&&(node->left!=0)&&(parent==0))
                {
                     root=node->left;
                     break;
                }
                if((node->left==0)&&(node->right==0)&&(parent!=0))//alright
                {

                    if(parent->item<node->item)
                        {parent->right=0;

                        }
                    if(parent->item>node->item)
                        {parent->left=0;

                        }
                        break;
                }
                if((node->left!=0)&&(node->right!=0))//alright
                {

               struct treeNode *returntree;

                   struct treeNode *parenttree=node;
                   returntree=node->right;
                   while(returntree->left!=0)
                      {
                          parenttree=returntree;
                          returntree=returntree->left;
                      }

                      if(parenttree==node)
                      {

                          parenttree->item=returntree->item;
                          parenttree->right=returntree->right;
                          break;
                      }
                      else{

                        node->item=returntree->item;
                        parenttree->left=returntree->right;
                    break;
                      }

                }
                if((parent==0)&&(node->left==0)&&(node->right==0))//alright
                    {
                    root=0;
                    break;
                    }
            }


        }

}
else
    return -1;
}



int getMinItem() //returns the minimum item in the tree
{
    //write your codes here
    struct treeNode * node = root;
    while(node->left!=0)
    {
       node=node->left;
    }
    return node->item;
}

int getMaxItem() //returns the maximum item in the tree
{
    //write your codes here
    struct treeNode * node = root;
    if(root!=0){
    while(node->right!=0)
    {
       node=node->right;
    }
    return node->item;
    }
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound) //returns number of items in the
{
   if(node==0)
    return 0;
   if(node->item>=leftBound&&node->item<=rightBound)
    return 1+rangeSearch(node->left,leftBound,rightBound)+rangeSearch(node->right,leftBound,rightBound);
   if(node->item<leftBound)
    rangeSearch(node->right,leftBound,rightBound);
   else
    rangeSearch(node->left,leftBound,rightBound);

}


void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}



int main(void)
{
    initializeTree();
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. \n");
        printf("6. PrintInOrder. 7. exit.   8.getsize\n");
         printf("9.Calculation item height   10.Minimum  11.Maximum\n");
        printf("12.Range search     13.Delete item   14.calculation Node Height\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(root, item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==8)
        {
            int item;
            //scanf("%d",&item);
            printf("%d\n",getSize(root));
        }
        else if(ch==9)
        {
            int item;
            scanf("%d",&item);
            printf("%d\n",calcDepth(item));
        }
        else if(ch==10)
        {
            int item;
            //scanf("%d",&item);
            printf("%d\n",getMinItem());
        }
        else if(ch==11)
        {
            int item;
            //scanf("%d",&item);
            printf("%d\n",getMaxItem());
        }
        else if(ch==12)
        {
            int item1,item2;
            scanf("%d  %d",&item1,&item2);
            printf("%d\n",rangeSearch(root,item1,item2));
        }
         else if(ch==13)
        {
            int item1;
            scanf("%d",&item1);
            int flag=deleteItem(root,item1);
              if(flag==-1)
                printf("not found or empty list\n");
        }
        else if(ch==14)
        {
            int item;
            scanf("%d",&item);
            printf("%d\n",calculationNode(item));
        }

    }

}
