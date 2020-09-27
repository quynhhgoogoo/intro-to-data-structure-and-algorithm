/*Includes recursive functions for linkedlist*/

/*print nodes in linked list in ascending order recursively*/
void RDisplayA(struct Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        RDisplayA(p->next);
    }
}

/*print nodes in linked list in descending order recursively*/
void RDisplayD(struct Node *p){
    if(p!=NULL){
        RDisplayD(p->next);
        printf("%d ", p->data);
    }
}

/*count the number of nodes inside linkedlist*/
int CountNode(struct Node *p){
    int count = 0;
    
    if(p==NULL){
        return 0;
    }
    else{
        count = CountNode(p->next) + 1;
        return count;
    }
}

/*calculate the sum of linkedlist*/
int SumNode(struct Node *p){
    int sum = 0;
    
    if(p==NULL){
        return 0;
    }
    else{
        sum = SumNode(p->next) + p->data;
        return sum;
    }
}