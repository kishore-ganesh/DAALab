#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, wt;
}

void heapify(Edge* heap, int index, int heapSize){
    int lChild = 2*index + 1;
    int rChild = 2*index + 2;
    int m = index;
    for(int i = 2*index+1; i<=2*index+2; i++){
        if(i < heapSize && heap[i].wt < heap[m].wt){
            m  = i;
        }
    }

    if(m!=index){
        Edge t = heap[index];
        heap[index] = heap[m];
        heap[m] = t;
        heapify(heap, m, heapSize);
    }
}

void reverseHeapify(Edge* heap, int index){
    int parent = (index/2);
    if(parent!=index){
        if(heap[parent].wt > heap[index].wt){
            Edge t = heap[parent];
            heap[parent] = heap[index];
            heap[index] = t;
            reverseHeapify(heap, parent);
        }

    }
}

int insert(struct Edge* heap, Edge value, int heapSize){
    heap[heapSize++] = value;
    reverseHeapify(heap, heapSize - 1);
    return heapSize;
}

Edge peek(Edge* heap){
    return heap[0];
}

Edge deleteTop(Edge* heap, int heapSize){
    int t = heap[0];
    heap[0] = heap[heapSize - 1];
    heap[heapSize - 1] = t;
    heapSize--;
    heapify(heap, 0, heapSize);
    return heapSize;
}

void increasePriority(Edge* heap, int index){
    heap[index]++;
    reverseHeapify(heap, index);
}

int find(int* set, int i){
    while(set[i]!=i){
        i = set[i];
    }
    return i;
}
void* union_sets(int* set, int i, int j){
    union[find(i)] = find(j);
}
int main(){
    int V;
    cin >> V;
    int adjointMatrix[V][V] = {0};
    int E;
    cin >> E;
    int edgesHeap[E];
    int heapSize = -1;
    int minwt = 0;
    for(int i = 0; i < E; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        Edge k;
        k.u = u;
        k.v = v;
        k.wt = wt;
        insert(edgesHeap, k, heapSize);
    }

    while(heapSize>-1){
        Edge e = peek(edgesHeap);
        heapSize = deleteTop(heap, heapSize);
        if(find(set, u)!=find(set, v)){
            minwt+=e.wt;
            union_sets(set, u, v);
        }
    }
}