#include<stdio.h>
void display(int a[], int size){
    printf("The contents of array of size %d is:\n",size);
    printf("\n-----------------");
    for(int i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
    printf("\n-----------------");
}
int linearSearch(int a[], int size, int element){
    for(int i=0;i<size;i++){
        if(a[i] == element){
            return i;
        }
    }
    return -1;
}
int binarySearch(int a[], int size, int element){
    int s=0,e=size-1,mid;
    while(s<=e){
        mid = s-(s-e)/2;
        if(element==a[mid]) return mid;
        else if(element<a[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
int main()
{
    int a[] = {1,2,3,6,7,9,18,33,57,94};
    int size = sizeof(a)/sizeof(int);
    int element = 9;
    printf("Linear search : Index of %d is : %d\n",element,linearSearch(a,size,element));
    printf("Binary search : Index of %d is : %d\n",element,binarySearch(a,size,element));
    return 0;
}