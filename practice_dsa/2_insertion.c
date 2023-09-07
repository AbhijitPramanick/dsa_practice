//Tutorial link : https://www.youtube.com/watch?v=o9WevKSnHL4&list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi&index=10

#include<stdio.h>
#include<stdlib.h>

//Traversal
void display(int a[], int n){
    printf("Contents of the array of size %d is:\n",n);
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}

//Insertion
void insert(int a[], int n,int capacity, int element, int pos)
{
    if(pos<0 || pos>n-1 || n>=capacity){
        printf("Insertion unsuccessful.\n");
    }
    else{
        printf("Performing insertion...\n");
        for(int i=n;i>=pos;i--){

            a[i+1] = a[i];
        }
        a[pos] = element;
        printf("Insertion successful. New array is:\n");
        display(a,n+1);
    }
}

//Sorted insertion
void sortedInsertion (int a[], int size, int capacity, int element){
    if(capacity<=size){
        printf("Capacity full. Insertion not possible.\n");
        return;
    }
    int k;
    int inserted = 0;
    for(int i=0;i<size;i++){
        if(element<a[i]){
            k=size-1;
            while(k>=i){
                a[k+1] = a[k];
                k--;
            }
            a[i] = element;
            inserted = 1;
            break;
        }
    }
    if(!inserted) a[size] = element;
    display(a,size+1);
}
int main()
{
    int arr[10] = {1,23,44,56};
    int capacity = 10;
    int size= 4;
    int element = 200;
    int position = 1;
    display(arr,size);
    insert(arr,size,capacity,element,position);
    sortedInsertion(arr,size,capacity,element);
    return 0;
}