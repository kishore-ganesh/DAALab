#include<stdio.h>
void heapify(int* heap, int index, int heapSize){
    int lChild = 2*index + 1;
    int rChild = 2*index + 2;
    int m = index;
    for(int i = 2*index+1; i<=2*index+2; i++){
        if(i < heapSize && heap[i] > heap[m]){
            m  = i;
        }
    }

    if(m!=index){
        int t = heap[index];
        heap[index] = heap[m];
        heap[m] = t;
        heapify(heap, m, heapSize);
    }
}

void reverseHeapify(int* heap, int index){
    int parent = (index/2);
    if(parent!=index){
        if(heap[parent] < heap[index]){
            int t = heap[parent];
            heap[parent] = heap[index];
            heap[index] = t;
            reverseHeapify(heap, parent);
        }

    }
}

int insert(int* heap, int value, int heapSize){
    heap[heapSize++] = value;
    reverseHeapify(heap, heapSize - 1);
    return heapSize;
}

int peek(int* heap){
    return heap[0];
}

int deleteTop(int* heap, int heapSize){
    int t = heap[0];
    heap[0] = heap[heapSize - 1];
    heap[heapSize - 1] = t;
    heapSize--;
    heapify(heap, 0, heapSize);
    return heapSize;
}

void increasePriority(int* heap, int index){
    heap[index]++;
    reverseHeapify(heap, index);
}

void printHeap(int* arr, int heapSize){
    for(int i = 0; i < heapSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main(){
    int arr[100] = {5, 6, 8, 2, 3, 1};
    int heapSize = 6;
    for(int i = heapSize/2 -1; i>=0; i--){
        heapify(arr, i, heapSize);
    }

    printHeap(arr, heapSize);
    heapSize = insert(arr, 10, heapSize);
    printHeap(arr, heapSize);
    heapSize = deleteTop(arr, heapSize);
    printHeap(arr, heapSize);
    

}
