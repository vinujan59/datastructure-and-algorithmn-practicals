#include<iostream>
using namespace std;

typedef int element_t; //Element type of the stack

int Parent(int i);
int Left(int i);
int Right(int i);
void Max_Heapify(int A[][2],int i,int* length);
void BuildMax_Heap(int A[][2],int* length);
element_t* pop(int A[][2],int* length);
int push(int A[][2],int  B[],int* length );
void print(int A[][2],int* length);

int main(){
    cout << "Create a priority Queue B using following {priority, value} tuples." << endl;
    cout << "B = {{1,12},{16,64},{2,72},{3,10},{12,4},{7,21},{4,24},{20,10}}" << endl;
    int B[][2] = {{1,12},{16,64},{2,72},{3,10},{12,4},{7,21},{4,24},{20,10}};
    int temp = sizeof(B)/sizeof(B[0]);
    int* length = &temp;
    BuildMax_Heap(B,length);
    print(B,length);
    cout << "push(B, {11,63}}" << endl;
    int arr[] = {11,63};
    push(B,arr,length);
    print (B,length);
    cout << "->print pop(B);" << endl;
    int* maximum = pop(B,length);
    cout << "--" << maximum[0];
    cout << "-" << maximum[1] << "--" << endl;
    print(B,length);
    cout << "->print pop(B);" << endl;
    maximum = pop(B,length);
    cout << "--" << maximum[0];
    cout << "-" << maximum[1] << "--" << endl;
    print(B,length);

    return 0;
}

int Parent(int i){
    if(i%2 == 0)
        return (i/2)-1;
    else
        return i/2;
}

int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

void Max_Heapify(int A[][2],int i,int *length){
    int l = left(i);
    int r = right(i);
    int largest;
    if ((l <= (*length) - 1) && (A[l][0] > A[i][0]))
        largest = l;
    else
        largest = i;
    if ((r <= (*length) - 1) && (A[r][0] > A[largest][0]))
        largest = r;
    if(largest != i){
        element_t temp1 = A[i][0];
        element_t temp2 = A[i][1];
        A[i][0] = A[largest][0];
        A[i][1] = A[largest][1];
        A[largest][0] = temp1;
        A[largest][1] = temp2;
        Max_Heapify(A,largest,length);
    }
    return ;
}

void BuildMax_Heap(int A[][2],int *length){
    for(int i = ((*length/2)-1) ; i >= 0 ; i--){
        Max_Heapify(A,i,length);
    }
}


element_t* pop(int A[][2],int* length){
    if (*length < 1){//under flow
        return NULL;
    }
    element_t* maximum = new int[2];
    maximum[0] = A[0][0];
    maximum[1] = A[0][1];
    A[0][0] = A[*length - 1][0];
    A[0][1] = A[*length - 1][1];
    (*length)--;
    Max_Heapify(A,0,length);
    return maximum;
}
int push(int A[][2],int B[],int* length){
    A[*length][0] = B[0];
     A[*length][1] = B[1];
    (*length)++;
    int i = (*length) - 1;
    while (i>=0 && A[Parent(i)][0] < A[i][0]){
        element_t temp = A[i][0];
        element_t temp2 = A[i][1];
        A[i][0]  = A[Parent(i)][0];
        A[i][1] = A[Parent(i)][1];
        A[Parent(i)][0] = temp;
        A[Parent(i)][1] = temp2;
        i = Parent(i);
    }
    return 1;
}



void print(int A[][2],int* length){
    for(int i = 0;i < *length;i++){
        cout << "-";
        for (int j = 0; j < 2;j++){
            cout << "-";
            cout << A[i][j] ;
        }
        cout << "--";
    }
    cout << "\n";
}


