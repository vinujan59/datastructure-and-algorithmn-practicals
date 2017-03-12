#include<stdio.h>
#include<iostream>
#include <chrono>
#include<stdlib.h>//random
#include<climits>//INT_MAX

using namespace std;
using namespace std::chrono;

//methods we are going to use
void merge_Sort(int* inputArray, int start, int End);
void merge(int* mergeArray, int start, int middle, int End);
void insertion_sort(int* inputArray , int inputSize);




int main(){
	int inputSize[7] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };//test cases
	cout <<"input size			merge			insertion .\n";
	for (int i = 0; i < 7; i++){
		cout << inputSize[i]<<"				";
		int *inputArray1;//declaring dynamic array
		int *inputArray2;//declaring dynamic array
		inputArray1 = new int[inputSize[i]];//initialising dynamic array
		inputArray2 = new int[inputSize[i]];//initialising dynamic array
		for (int j = 0; j < inputSize[i]; j++){
			inputArray2[j] = inputArray1[j] = rand() % (inputSize[i]+1);//adding numbers to two arrays
		}
		////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////time measuring/////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////
		auto start = std::chrono::high_resolution_clock::now();
		merge_Sort(inputArray1,0,inputSize[i]-1 );//function call
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		cout << microseconds<<"				";
		/////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////time measuring/////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////
		auto start1 = std::chrono::high_resolution_clock::now();
        insertion_sort(inputArray2,inputSize[i]);//function call
		auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
		long long microseconds1 = std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count();
		cout << microseconds1 ;
		/////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "\n";
        delete[] inputArray1;//deleting arrays
		delete[] inputArray2;
	}
	return 0;
}

//merge sort function it will recursively divude the array to single element
//parameters arrayName,array start index,array end index
void merge_Sort(int* inputArray, int start, int End){
	if (start < End){
		int q = (start + End) / 2;
		merge_Sort(inputArray, start, q);
		merge_Sort(inputArray, q+1 , End);
		merge(inputArray, start, q, End);
	}

}
//merge function wil sort the array and merge the as a single array
//parameters arrayName,array start index,array end index,q
void merge(int* inputArray, int start, int q, int End){
	int n1 = q - start + 1;
	int n2 = End - q;
	int *L;
	int *R;
	L = new int[n1+1];
	R = new int[n2+1];
	for (int i = 0; i < n1; i++){
		L[i] = inputArray[start + i];
	}
	for (int j = 0; j < n2 ; j++){
		R[j] = inputArray[q+ 1 + j];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0;
	int j = 0;

	for (int k = start; k <= End; k++){
		if (L[i] <= R[j]){
			inputArray[k] = L[i];
			i++;
		}
		else{
			inputArray[k] = R[j];
			j++;
		}
	}
	delete[] R;
	delete[] L;
}
//insertion function sort the array
////parameters arrayName,size of the array
void insertion_sort(int* inputArray,int inputSize){
	int i,key;
	for(int j=1;j<inputSize;j++){
        key = inputArray[j];
        i = j-1;
        while (i>-1 && inputArray[i]>key){
            inputArray[i+1] = inputArray[i];
            i--;
        }
        inputArray[i+1] = key;
	}
}