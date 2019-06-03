/*binary_search : a recursive binary search on a sorted array of intergers
Inputs:
- int a[] : sorted array of intergers
- int begin : lower index of the array to search
- int end : upper index of the array to search
- int t : number we are looking to find

Return : index of number in array, returns 1 if it is not found
*/

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(int a[], int begin, int end, int t){
    int mid;    /*mid point in array*/
    int diff;   /*difference from target*/


if (begin > end){
    return -1;
} else {
    mid = (begin+end)/2;
    diff = a[mid] - t;

    if(diff==0){
        return mid;
    } else if (diff < 0){
        return binary_search(a, mid+1, end, t);
    } else {
        return binary_search(a, 0, mid-1, t);
    }
}
}

int main(){
    int a[] = {1, 2, 3, 4, 5};

    /*Use our own binary search function*/
    cout<<"Searching for 4 :"<<binary_search(a, 0, 4, 4)<<endl;
    cout<<"Searching for 10 :"<<binary_search(a, 0, 4, 10)<<endl;

    /*Use the standard-library binary-search*/
    vector <int> v(a, a+4);
    cout<<"Binary search for 4 :"<<binary_search(v.begin(), v.end(), 4)<<endl;
    cout<<"Binary search for 10 :"<<binary_search(v.begin(), v.end(), 10)<<endl;
    /*Output : 1 is True, 0 is False*/

    return 0;
}