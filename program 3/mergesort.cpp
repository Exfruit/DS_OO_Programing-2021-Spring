#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 1000
#define LENGTH 50

void print_arr(int arr[], int length){
	for(int i = 0; i < length - 1; i++){
		cout << arr[i] << " ";
	}
	cout << arr[length - 1] << endl;
	return;
}
void merge(int arr[], int L[], int R[], int front, int mid, int end){
	int Lidx = 0, Ridx = 0;
    for(int i = front; i <= end; i++){
        if(L[Lidx] <= R[Ridx]){
            arr[i] = L[Lidx];
            Lidx++;
        }
        else{
            arr[i] = R[Ridx];
            Ridx++;
        }
    }
}
void yabai_mergesort(int arr[], int front, int end){
    if(front < end){
        int mid = (front+end) / 2;
        int L[mid + 1 - front + 1], R[end - mid + 1];
        for(int i = front, j = 0, k = 0; i <= end; i++){
        	if(i % 2 == 0){
        		L[j] = arr[i];
        		j++;
        	}
        	else{
        		R[k] = arr[i];
        		k++;
        	}
        }
        L[mid + 1 - front] = MAX, R[end - mid] = MAX;
        yabai_mergesort(L, front, mid);
        yabai_mergesort(R, front, mid);
        merge(arr, L, R, front, mid, end);
    }
} 

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int arr[LENGTH];
	for(int i = 0; i < LENGTH; i++){
		arr[i] = rand() % MAX;
	}
	cout << "Before sorted: " << endl;
	print_arr(arr, LENGTH);
	cout << "After sorted: " << endl;
	yabai_mergesort(arr, 0, LENGTH - 1);
	print_arr(arr, LENGTH);

	return 0;
}