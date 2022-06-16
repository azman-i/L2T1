#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int partition(int arr[], int l, int r)
{
   //  cout<<"hllo"<<endl;
  //   cout<<l<<"    "<<r<<endl;
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	//cout<<i<<endl;
	return i;
}
int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}
int kthSmallest(int arr[], int l, int r, int k)
{
     //If k is smaller than number of elements in array
   //   cout<<"hllo"<<endl;
    if (k > 0 && k <= r - l + 1)
    {

        int pos = randomPartition(arr, l, r);

//         If position is same as k
              //cout<<"pos"<<pos<<endl;
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l >k-1)
return kthSmallest(arr, l, pos-1, k);

         //Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    // If k is more than number of elements in array

    return INT_MAX;
}


int Partition_in_sort(int *a,int FirstIndex,int LastIndex)
{

//this will work for partition with respect to median
  int PivotIndex,Median;

  //cout<<endl;
//returns median
  Median=kthSmallest(a,FirstIndex,LastIndex,(((LastIndex-FirstIndex)/2)+1));
 cout<<"median"<<Median<<endl;
 //getting median index
  for(int i=0;a[i]!=0;i++)
  {
      if(a[i]==Median)
      {
          PivotIndex=i;
          break;
      }
  }
    //cout<<"pivotindex"<<PivotIndex<<endl;
    //exchanging  with  last index
  swap(a[PivotIndex],a[LastIndex]);
   int pivot=LastIndex;
   LastIndex=LastIndex-1;
   while(FirstIndex<LastIndex)
   {
       if(a[FirstIndex]<=a[pivot])
        FirstIndex++;
        else if(a[LastIndex]<=a[pivot])
        {
            swap(a[FirstIndex],a[LastIndex]);
            FirstIndex++;
        }
       else  if(a[FirstIndex]>a[pivot])
        {
            swap(a[FirstIndex],a[LastIndex]);
            LastIndex--;
        }
       else if(a[LastIndex]>a[pivot])
        {

            LastIndex--;
        }

   }

      if(a[FirstIndex]>=a[pivot])
  {
    swap(a[FirstIndex],a[pivot]);
   return FirstIndex;}
if(a[FirstIndex]<a[pivot])
  {
    swap(a[FirstIndex+1],a[pivot]);
   return FirstIndex+1;}
    //returning indexof pivot
}




void quicksort(int *a,int FirstIndex,int LastIndex)
{
// cout<<"hllo"<<endl;
    if(FirstIndex<LastIndex)
   {int pivot_position= Partition_in_sort(a,FirstIndex,LastIndex);
   //cout<<pivot_position<<endl;
//recurrence for left and right sub array
    quicksort(a,FirstIndex,pivot_position-1);
    quicksort(a,pivot_position+1,LastIndex);
   }
}
int main()
{
    int n;
    cin>>n;
    int a[40000];
    for (int i=0;i<n;i++)
        cin>>a[i];
       // cout<<"hllo"<<endl;
        quicksort(a,0,n-1);
        cout<<"final array"<<endl;
   for (int i=0;i<n;i++)
        cout<<a[i]<<"  ";
}
