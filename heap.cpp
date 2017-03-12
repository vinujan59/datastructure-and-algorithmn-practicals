#include<iostream>
using namespace std;

typedef int element_t;

int Parent(int i);
int Left(int i);
int Right(int i);
void Max_Heapify(int A[],int i,int* length);
void BuildMax_Heap(int A[],int* length);
element_t HeapMaximum(int A[]);
element_t HeapExtractMax(int A[],int* length);
int Max_HeapInsert(int A[],int  element_t,int* length );
int HeapIncreaseKey(int A[], int i, int amount);
void print(int A[],int* length);
void HeapSort(int A[],int* length);

int main(){
    int A[] = {6,5,3,1,8,7,2,4};
    int len = sizeof(A)/sizeof(A[0]);
    int* length = &len;
    cout << "A = {6, 5, 3, 1, 8, 7, 2, 4}" << endl;
    cout << "BuildMax-Heap(A)"<< endl;
    BuildMax_Heap(A,length);
    cout << "-> print A" << endl;
    print(A,length);
    cout << "-> print HeapMaximum(A)" << endl;
    cout << HeapMaximum(A) << endl;
    cout << "-> print HeapExtractMax(A)" << endl;
    cout << HeapExtractMax(A,length) << endl;
    cout << "Max-HeapInsert(A, 9)" << endl;
    Max_HeapInsert(A,9,length);
    cout << "-> print HeapMaximum(A)" << endl;
    cout << HeapMaximum(A) <<endl;
    cout << "Max-HeapInsert(A, 8)" << endl;
    Max_HeapInsert(A,8,length);
    cout << "-> print HeapMaximum(A)" << endl;
    cout << HeapMaximum(A) <<endl;
    cout << "-> printTree(A)" << endl;
    print(A,length);
    cout << "HeapIncreaseKey(A,4,10)" << endl;
    HeapIncreaseKey(A,4,10);
    cout << "-> print HeapMaximum(A)" << endl;
    cout << HeapMaximum(A) <<endl;
    cout << "-> printTree(A)" << endl;
    print(A,length);
    cout << "B = {12,64,72,10,4,21,24,10,63}" << endl;
    int B[] = {12,64,72,10,4,21,24,10,63};
    *length = sizeof(B)/sizeof(B[0]);
    cout << "HeapSort(B)" << endl;
    HeapSort(B,length);
    cout << "-> print B;" << endl;
    print(B,length);
    cout << "Create a priority Queue B using following {priority, value} tuples." << endl;
    cout << "B = {{1,12},{16,64},{2,72},{3,10},{12,4},{7,21},{4,24},{20,10}}" << endl;
    B = {{1,12},{16,64},{2,72},{3,10},{12,4},{7,21},{4,24},{20,10}};
    cout << "push(B, {11,63}}" << endl;

    return 0;
}
/*this function return the index of the parent*/
int Parent(int i){
    if(i%2 == 0)
        return (i/2)-1;
    else
        return i/2;
}
/*this function return the index of the left*/
int left(int i){
    return 2*i + 1;
}
/*this function return the index of the right*/
int right(int i){
    return 2*i + 2;
}
/*this function maintain heap property below i index*/
void Max_Heapify(int A[],int i,int *length){
    int l = left(i);
    int r = right(i);
    int largest;
    if ((l <= (*length) - 1) && (A[l] > A[i]))
        largest = l;
    else
        largest = i;
    if ((r <= (*length) - 1) && (A[r] > A[largest]))
        largest = r;
    if(largest != i){
        element_t temp1 = A[i];
        element_t temp2 = A[largest];
        A[i] = temp2;
        A[largest] = temp1;
        Max_Heapify(A,largest,length);
    }
    return ;
}
/*will implement max heap property for all elements*/
void BuildMax_Heap(int A[],int *length){
    for(int i = ((*length/2)-1) ; i >= 0 ; i--){
        Max_Heapify(A,i,length);
    }
}
/*return the maximum value of heap*/
element_t HeapMaximum(int A[]){
    return A[0];
}
/*remove the maximum value from heap*/
element_t HeapExtractMax(int A[],int* length){
    if (*length < 1){//under flow
        return NULL;
    }
    element_t maximum = A[0];
    A[0] = A[*length - 1];
    (*length)--;
    Max_Heapify(A,0,length);
    return maximum;
}
/*insert new value to heap and maintain heap property*/
int Max_HeapInsert(int A[],element_t element,int* length){
    A[*length] = element;
    (*length)++;
    int i = (*length) - 1;
    while (i>=0 && A[Parent(i)] < A[i]){
        element_t temp = A[i];
        A[i]  = A[Parent(i)];
        A[Parent(i)] = temp;
        i = Parent(i);
    }
    return 1;
}
/*this function will increase value of a node by the value key if previous value is less than key and return 1 as successful
else return -1*/
int HeapIncreaseKey(int A[], int i, int amount){
	if(amount < A[i]){
        cout << "new key is smaller than current key." << endl;
        return -1;
	}
	A[i] = amount;
	int j= i;
    while (j>=0 && A[Parent(j)] < A[j]){
        element_t temp = A[j];
        A[j]  = A[Parent(j)];
        A[Parent(j)] = temp;
        j = Parent(j);
    }
    return 1;
}
/*thus function sorts number in aascending order*/
void HeapSort(int A[],int* length){
    BuildMax_Heap(A,length);
    int temp1 = 0;
    int* temp = &temp1;
    for(int i = (*length)-1 ; i > 0 ;i--){
        element_t temp2 = A[0];
        A[0] = A[i];
        A[i] = temp2;
        *temp = i;
        Max_Heapify(A,0,temp);
    }
}
/*this function will print the heap*/
void print(int A[],int* length){
    for(int i = 0;i < *length;i++){
        cout << "-" << A[i] << "-";
    }
    cout << "\n";
}

