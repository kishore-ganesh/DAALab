#include<stdio.h>
#define V 9
#define INF 999
typedef struct Node NODE;
struct Node{
    int index;
    int edges[V];
    int weight;
};


NODE heap[V];

void heapify(int i, int heap_size){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int m = i;
    if(l < heap_size && heap[l].weight < heap[m].weight){
       m = l;
    }
    if(r < heap_size && heap[r].weight < heap[m].weight){
       m = r;
    }
    if(m!=i){
        NODE t = heap[i];
        heap[i] = heap[m];
        heap[m] = t;
        heapify(m, heap_size);
    }
}

NODE extractMin(int heap_size){
    NODE t = heap[0];
    heap[0] = heap[heap_size-1];
    heap[heap_size-1] = t;
    heap_size--;
    heapify(0, heap_size);
    return t; 
}

int findIndex(int i){
    for(int j = 0; j < V; j++){
        if(heap[j].index==i){
            return j;
        }
    }
}

void reverseHeapify(int index){
    int p = index/2;
    if(index!=p){
        if(heap[index].weight<heap[p].weight){
            NODE t = heap[index];
            heap[index] = heap[p];
            heap[p] = t;
            reverseHeapify(p);
        }
    }
}

void printHeap(){
    for(int i = 0; i < V; i++){
        printf("%d ", heap[i].weight);
    }
    printf("\n");
}

void dijkstra(int source){
    for(int i = 0; i < V; i++){
        heap[i].weight = INF;
    }
    heap[source].weight = 0;
    int heap_size = V;
    for(int i = V/2-1; i >= 0; i--){
        heapify(i, heap_size);
    }
    while(heap_size > 0){
        NODE t = extractMin(heap_size);
        printHeap();
        heap_size--;
        for(int i = 0; i < V; i++){
            if(t.edges[i]!=-1){
                int index = findIndex(i);
                if(t.weight + t.edges[i] < heap[index].weight){
                    heap[index].weight = t.weight + t.edges[i];
                    reverseHeapify(index);
                }
            }
        }
    }
}

int main(){
    for(int i = 0; i < V; i++){
        heap[i].index = i;
        for(int j = 0; j < V; j++){
            scanf("%d", &heap[i].edges[j]);
        }
    }
    int source = 0;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(heap[i].edges[j]==0){
                heap[i].edges[j] = INF;
            }
        }
    }
    dijkstra(source);
    for(int i = 0; i < V; i++){
        printf("1 -> %d: %d\n", heap[i].index, heap[i].weight);
    }
    
}
