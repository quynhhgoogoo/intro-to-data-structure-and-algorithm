/*malloc: acess to memory on heap*/

//========================= C ===========================================
#include <stdlib.h>
int main(){
    int *p;
    p = (int*)malloc(10*sizeof(int));     /* deference malloc with * in front would allow p to read/write here 
                                            alocate memory bytes for 10 intergers on heap*/

}

//========================= C ++ ===========================================
p = new int[5];