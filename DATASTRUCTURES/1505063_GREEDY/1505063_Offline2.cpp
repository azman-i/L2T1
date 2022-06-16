#include<iostream>
#include<cstdio>
using namespace std;


 void merge(int a[],int p,int q,int r)
    {

        int n1=q-p+1;
        int n2=r-q;
        int L[100];
        int R[100];
        for(int i=1;i<=n1;i++)
        {
            L[i]=a[p+i-1];
        }
        for(int j=1;j<=n2;j++)
        {
            R[j]=a[q+j];
        }
        L[n1+1]=100000;
        R[n2+1]=100000;
        int i=1, j=1;
        for(int k=p;k<=r;k++)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i=i+1;
            }
            else
            {
                a[k]=R[j];
                j=j+1;
            }
        }
    }
void merge_sort(int a[],int p,int r)
    {
        int q;
        if(p<r)
        {
         q=(p+r)/2;
         merge_sort(a,p,q);
         merge_sort(a,q+1,r);
         merge(a,p,q,r);
        }
    }

void GreedyAlgorithm(int a[],int p,int r,int NumberOfTaka)
{
    merge_sort(a,p,r);
    int sum=0;
    int sum1[30],j=0;
    for(int i=r;i>=1;i--)
   {
       //cout<<a[i]<<endl;
       if(NumberOfTaka>0)
       {int d=NumberOfTaka/a[i];\

       sum1[i]=d;
       sum=sum+d;
     //  cout<<"Value  "<<a[i]<<"        "<<d<<endl;
    NumberOfTaka=NumberOfTaka-d*a[i];
       }
   }
   printf("%d\n",sum);
   for(int i=r;i>=1;i--)
   {
       printf("%d  %d\n",a[i],sum1[i]);
   }

}
int main()
{
    int n;

    cin>>n;
    int a[1000];
     for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int NumberOfTaka;
    cin>>NumberOfTaka;
    int p=1,r=n;

    GreedyAlgorithm(a,p,r,NumberOfTaka);



     return 0;
}


