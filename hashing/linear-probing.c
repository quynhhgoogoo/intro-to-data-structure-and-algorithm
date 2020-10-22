#include <stdio.h>
#define SIZE 10

/*return value inside index's hashtable*/
int hash(int key){
    int index = key%SIZE;
    return index;
}

/*Seek for free space inside hashtable*/
int probe(int H[], int key){
    int index = hash(key);
    int i = 0;
    
    while(H[(index+i)%SIZE] != 0){
        i++;
    }
    return (index+i)%SIZE;
}

/*Insert an element inside hashtable*/
void Insert(int H[], int key){
    int index = hash(key);

    /*if index is already been occuppied*/
    if(H[index] != 0){
        index = probe(H, key);
    }
    H[index] = key;
}

/*Search an index in hashtable*/
int Search(int H[], int key){
    int index = hash(key);
    int i=0;

    while(H[(index+i)%SIZE]!=key){
        i++;
    }
    return (index+i)%SIZE;
}

int main(){
    int HT[10] ={0};
    
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);

    printf("\nKey found at %d", Search(HT,35));

    return 0;
}