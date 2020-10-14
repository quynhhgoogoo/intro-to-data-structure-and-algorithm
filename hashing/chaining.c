#include <stdio.h>
#include "chaining.h"

/*array of linkedlist*/
struct Node *HT[10];
struct Node *temp;

/*Implement hashing function H(x)*/
int hash(int key){
    return key%10;
}

/*Insert element from key space to hash table*/
void Insert(struct Node *H[], int key){
    int index = hash(key);
    InsertNodeSort(H[index], key);
}

/*Create empty Hash*/
void createHash (struct Node *HT[]){
    int i;
    for(i=0; i<10; i++){
        HT[i] = NULL;
    } 
}
   
int main(){
    
    createHash(HT);
    Insert(HT,11);
    Insert(HT,5);
    Insert(HT,7);

    int key = 5;
    temp=LinearSearch(HT[hash(key)], key);
    printf("%d", temp->data);
       
    return 0;
}