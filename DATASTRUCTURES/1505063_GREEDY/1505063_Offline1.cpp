#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX_HEAP_SIZE 100000

#define MAXREAL 999999.0

class HeapItem
{
public:
	char data; //actual data that is stored
	float key;
	HeapItem *right;
	HeapItem *left;
	//key value of the data, heap is constructed based on key
};


//MinHeap class, minimum item stored at the root of heap tree
class MinHeap
{
public:
	HeapItem **A; //stores heap items, e.g., nodes
	int heapLength;
	int * map;
     //struct HeapItem  *heapitem;
	MinHeap() //constructor
	{
		A = new HeapItem*[MAX_HEAP_SIZE];
		map = new int[MAX_HEAP_SIZE];
		heapLength=0;
	}

	~MinHeap() //destructor
	{
		if(map) delete [] map;
		if(A) delete [] A;
		map = 0; //set to NULL after deletion
		A = 0; //set to NULL after deletion
	}

    //Fills the heap with an array of integers
    //key values do not maintain heap property
    //May be used in some algorithms such as dijkstra's shortest path
	void initialize(int a[], char freq[],int n)
	{
		//heapLength = n;
		for(int i=0; i<n; i++) //nodes are stored from index 1 instead of 0 in the hea
        {
         A[i+1]=new HeapItem();

		 //map tracks which vertex is stored at which heap node
		}
	}

	//this function inserts a new (data,key) pair in the heap
    //call to buheapify is required
    void insertItemFirst(HeapItem* heapitem)
    {
        //Write your codes here
         //cout<<"inside6             "<<heapLength<<endl;
        heapLength=heapLength+1;
          // cout<<"inside6             "<<heapLength<<endl;
        A[heapLength]->data=heapitem->data;
        // cout<<"inside3"<<endl;

        A[heapLength]->key=heapitem->key;
        //cout<<"heaplengthkey   "<<A[heapLength]->key<<endl;
        A[heapLength]->right=heapitem->right;
         //cout<<"inside2"<<endl;

        A[heapLength]->left=heapitem->left;
        map[heapitem->data]=heapLength;
        //cout<<"inside"<<endl;
        buHeapify(heapLength);
        //cout<<"outside"<<endl;
    }
    void insertItem(HeapItem *h1,HeapItem *h2)
    {
        //Write your codes here
        // cout<<"inside6             "<<heapLength<<endl;
        heapLength=heapLength+1;
        A[heapLength]=new HeapItem();
          // cout<<"inside6             "<<heapLength<<endl;
        A[heapLength]->data='#';
        // cout<<"inside3"<<endl;

        A[heapLength]->key=h1->key+h2->key;
       // cout<<"heaplengthkey   "<<A[heapLength]->key<<endl;
        A[heapLength]->right=h2;
       //  cout<<"inside2"<<endl;

        A[heapLength]->left=h1;
        map[A[heapLength]->data]=heapLength;
        //cout<<"inside"<<endl;
        buHeapify(heapLength);
        //cout<<"outside"<<endl;
    }

    //this function removes (and returns) the node which contains the minimum key value
	HeapItem* removeMin()
	{
	    //write your codes here
	    HeapItem* t=A[1];
       if(heapLength>1)
	    {
	    t=A[1];
	    A[1]=A[heapLength];
	    A[heapLength]=t;
	  //  cout<<"remove1"<<endl;
	    heapLength--;
	    heapify(1);
	    return t;}
	    else
            {
                //cout<<"remove2"<<endl;
                heapLength=0;
                return t;
            }

	}





    //This function returns the key value of a data stored in heap
	float getKey(int data)
	{
		int i = map[data];
		return A[i]->key;
	}

    //This function heapifies the heap
    //When a key value of ith node is increased (because of update), then calling
    //this function will restore heap property
	void heapify(int i)
	{
		int l,r,smallest;
		while(1)
		{
			l=2*i;      //left child index
			r=2*i+1;    //right child index
			smallest=i;

			if(l>heapLength && r>heapLength)
				break; //nothing to do, we are at bottom
			else if(r>heapLength)
				smallest = l;
			else if(l>heapLength)
				smallest = r;
			else if( A[l]->key < A[r]->key )
				smallest = l;
			else
				smallest = r;

			if(A[i]->key <= A[smallest]->key)
				break;	//we are done heapifying
            else
			{
                //swap nodes with smallest child, adjust map array accordingly
				HeapItem *t;
				t=A[i];
				A[i]=A[smallest];
				map[A[i]->data]=i;
				A[smallest]=t;
				map[A[smallest]->data]=smallest;
				i=smallest;
			}

		}
	}

    //This function heapifies the heap form bottom to up
    //When a key value of ith node is decreased (because of update), then calling
    //this function will restore heap property
    //In addition, when a new item is inserted at the end of the heap, then
    //calling this function restores heap property
	void buHeapify(int f)
	{
	    if(f==0)
	    return;

        int i=f/2;
        int l,r,smallest;
        l=2*i;
        r=2*i+1;
        if(l>heapLength && r>heapLength)
				return; //nothing to do, we are at bottom
			else if(r>heapLength)
				smallest = l;
			else if(l>heapLength)
				smallest = r;
			else if( A[l]->key < A[r]->key )
				smallest = l;
			else
				smallest = r;

            if(A[i]->key <= A[smallest]->key)
				return;
				 else
			{
                //swap nodes with smallest child, adjust map array accordingly
				HeapItem *t;
				t=A[i];
				A[i]=A[smallest];
				map[A[i]->data]=i;
				A[smallest]=t;
				map[A[smallest]->data]=smallest;
				i=smallest;
			}
        buHeapify(f/2);
	}
      //The function updates the key value of an existing data
    //stored in the heap
	//Note that updates can result in an increase or decrease of key value
	//Call to heapify or buheapify is required
	void updateKey(int data, float key)
	{
		//Write your codes here.
		printf("%f   %d  before\n",key,data);
		int i=map[data];
		printf("%d  i\n",i);
		A[i]->key=key;
		A[i]->data=data;
		printf("%f     %d\n",A[i]->key,A[i]->data);
		if(i==heapLength)
       buHeapify(i);
       if(i==1)
        heapify(i);

	}
    void printHeap()
    {
        printf("Heap length: %d\n", heapLength);
        for(int i=1;i<=heapLength;i++)
        {
            printf("(%d,%.2f) ", A[i]->data, A[i]->key);
        }
        printf("\n");
    }

	bool isOne()
	{
		if(heapLength==1)return true;
		else return false;
	}



	HeapItem* BuildHuffmanTree(int a[],char freq[],int n)
	{
	    //cout<<"hello"<<endl;
	    for(int i=0;i<n;i++)
        {
            HeapItem *heap=new HeapItem();
            //cout<<"hello"<<endl;
            heap->data=freq[i];
            heap->key=a[i];
            //cout<<"hello2"<<endl;
            heap->right=0;
            heap->left=0;
           // cout<<"hello4"<<endl;
            insertItemFirst(heap);

          //  cout<<"hello1"<<endl;
        }
        //cout<<"hello"<<endl;
        while(heapLength!=1)
	    {HeapItem* h1=removeMin();
	    HeapItem* h2=removeMin();
	    HeapItem *newheapitem=new HeapItem();
	    //cout<<h1->key<<"     helll      "<<h2->key<<endl;
        insertItem(h1,h2);
	    }
	    return removeMin();
	}
	void printArr(int  arr[],int top)
	{
	    for(int i=0;i<top;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
	}

	void HuffmanPrint(HeapItem *root,int arr[],int top)
{
    // Assign 0 to left edge and recur
    if (root->left!=0)
    {
    // cout<<"rootitem      "<<root->key<<endl;
        arr[top] = 0;
        HuffmanPrint(root->left, arr, top + 1);
    }

    // Assign 1 to right edge and recur
    if (root->right!=0)
    {
       // cout<<"rootitem      "<<root->key<<endl;

        arr[top] = 1;
        HuffmanPrint(root->right, arr, top + 1);
    }

    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (root->right==0&&root->left==0)
    {
        printf("%c    ",root->data);

       printArr(arr, top);
    }
}

void MainHuffmanCode(int a[],char freq[],int n)
{
    initialize(a,freq,n);
    HeapItem* item=BuildHuffmanTree(a,freq,n);
    //cout<<item->key<<endl;
  //  cout<<"mainhuffman"<<endl;
    int arr[30], top = 0;
   //HuffmanPrint(root, arr, top);
  // cout<<item->right->left->left->key<<endl;
         HuffmanPrint(item,arr,top);

}
};






int main()
{
    int choice;
    int data;
    float key;
    MinHeap heap;
    int a[10000];
    char freq[10000];
    bool exit = false;
    int  n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>freq[i]>>a[i];
        heap.MainHuffmanCode(a,freq,n);


//    while(!exit)
//    {
//        printf("1. Insert 2. RemoveMin 3.Update 4. Print 5. Exit.\n");
//        scanf("%d",&choice);
//        switch(choice)
//        {
//        case 1:
//            scanf("%d%f",&data,&key);
//            heap.insertItem(data, key);
//            heap.printHeap();
//            break;
//        case 2:
//            HeapItem item;
//            item = heap.removeMin();
//            printf("Removed: (%d,%.2f)\n", item.data, item.key);
//            heap.printHeap();
//            break;
//        case 3:
//            scanf("%d%f",&data,&key);
//            heap.updateKey(data,key);
//            heap.printHeap();
//            break;
//        case 4:
//            heap.printHeap();
//            break;
//        case 5:
//            exit = true;
//            break;
//
//        }
//    }
////    return 0;
}
