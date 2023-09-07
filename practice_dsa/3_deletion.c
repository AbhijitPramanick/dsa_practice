#include<stdio.h>
void display(int a[], int size){
    printf("The contents of the the array of size %d is :\n",size);
    for(int i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void delete(int a[], int size, int element){
    int k,deleted = 0;
    if(size<=0){
        printf("Deletion cannot be performed.");
        return;
    }
    else{
        for(int i=0;i<size;i++){
            if(a[i]==element){
                while(i<size-1){
                    a[i]=a[i+1];
                    i++;
                }
                deleted = 1;
                size--;
                break;
            }
        }
    }
    if(deleted){
        printf("Deletion successful\n");
        display(a,size);
    }
    else{
        printf("Deletion unsuccessful\n");
    }
}
int main(){
    int arr[] = {1,3,6,8,9,12,14};
    int size = sizeof(arr)/sizeof(int);
    int element = 14;
    display(arr,size);
    delete(arr,size,element);
    return 0;
}