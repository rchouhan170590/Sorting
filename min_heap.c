#include<stdio.h>
void Build_Heap(int ,int arr[]);
void Fix_Heap(int arr[],int ,int);
void swap(int *,int *);
int main()
{
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
      scanf("%d",&arr[i]);
      
    Build_Heap(size,arr);
    //print in non-Decreasing order
    for(int i=0;i<size;i++)
       printf("%d ",arr[i]);
    return 0;
}

void Build_Heap(int n,int arr[])
{
    int a=(n/2);
    for(int i=a;i>=1;i--)
       Fix_Heap(arr,i,n);
}

void Fix_Heap(int arr[],int i,int n)
{
    int leftc=2*i;
    int rightc=2*i+1;
    int lowest=i;
    if((leftc<=n)&&(arr[leftc-1]<arr[i-1]))
        lowest=leftc;
    if((rightc<=n)&&(arr[lowest-1]>arr[rightc-1]))
        lowest=rightc;
    if(lowest!=i)
    {
        swap(&arr[i-1],&arr[lowest-1]);
          Fix_Heap(arr,lowest,n);
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return ;
}
