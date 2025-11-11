#include<stdio.h>

int lin(int roll[],int n,int key){
    for(int i = 0;i<n;i++){
        if (key == roll[i]){
            return i;
            break;
        }
    }
    return -1;
}

int bin(int roll[],int n , int key){
    int start = 0;
    int end = n-1;
    int mid;
    for(int i = 0;i<n;i++){
        mid = (start+end)/2;
        if(key==mid){
            return i;
        }else if(key<mid){
            end = mid-1;
        }else{
            start = mid+1;
        }  
    }
     return -1;
}
int main(){
    int n,key,ch;
    printf("Enter no of students :");
    scanf("%d",&n);

    int roll[n];

    printf("Enter Elements inn Sorted form :\n");
    for(int i = 0;i<n;i++){
        scanf("%d",&roll[i]);
    }

    printf("Enter a key to search :");
    scanf("%d",&key);

    int pos = -1;
    printf("1.Linear Search\n2.Binary Search\n");
    printf("Select choice :");
    scanf("%d",&ch);
    if(ch == 1){
        pos = lin(roll,n,key);
    }else if(ch == 2){
        pos = bin(roll,n,key);
    }else{
        printf("invalid choice");
    }

    if(pos != -1){
        printf("Element found at : %d" ,pos+1);
    }else{
        printf("Element not found in array.");
    }
    return 0;
}
