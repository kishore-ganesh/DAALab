#include<vector>
#include<iostream>
using namespace std;

struct Edge
{
    int u, v, wt;
};

void heapify(Edge *heap, int index, int heapSize)
{
    int lChild = 2 * index + 1;
    int rChild = 2 * index + 2;
    int m = index;
    for (int i = 2 * index + 1; i <= 2 * index + 2; i++)
    {
        if (i < heapSize && heap[i].wt < heap[m].wt)
        {
            m = i;
        }
    }

    if (m != index)
    {
        Edge t = heap[index];
        heap[index] = heap[m];
        heap[m] = t;
        heapify(heap, m, heapSize);
    }
}

void reverseHeapify(Edge *heap, int index)
{
    int parent = (index / 2);
    if (parent != index)
    {
        if (heap[parent].wt > heap[index].wt)
        {
            Edge t = heap[parent];
            heap[parent] = heap[index];
            heap[index] = t;
            reverseHeapify(heap, parent);
        }
    }
}

int insert(struct Edge *heap, Edge value, int heapSize)
{
    heap[heapSize++] = value;
    reverseHeapify(heap, heapSize - 1);
    return heapSize;
}

Edge peek(Edge *heap)
{
    return heap[0];
}

int deleteTop(Edge *heap, int heapSize)
{
    
    if(heapSize==0){
        return -1;
    }
    Edge t = heap[0];
    heap[0] = heap[heapSize - 1];
    heap[heapSize - 1] = t;
    heapSize--;
    heapify(heap, 0, heapSize);
    return heapSize;
}

int main()
{
    int V;
    cin >> V;
    int adjointMatrix[V][V] = {0};
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            adjointMatrix[i][j] = -1;
        }
    }

    int E;
    cin >> E;
    Edge edgesHeap[E];
    int heapSize = 0;
    int minwt = 0;
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjointMatrix[u][v] = wt;
        adjointMatrix[v][u] = wt;
    }
    bool visited[V] = {0};
    int current = 0;
    int set[V];
    for(int i = 0; i < V; i++){
        set[i] = i;
    }
    cin >> current;
    do
    {
        if (!visited[current])
        {
            // cout << current << endl;
            visited[current] = true;
            for (int i = 0; i < V; i++)
            {
                if (!visited[i] && adjointMatrix[current][i] != -1)
                {
                    Edge k;
                    k.u = current;
                    k.v = i;
                    k.wt = adjointMatrix[current][i];
                    heapSize = insert(edgesHeap, k, heapSize);
                }
            }
        }
        while (heapSize > -1)
        {
            Edge e = peek(edgesHeap);
            heapSize = deleteTop(edgesHeap, heapSize);
            if (!(visited[e.u] && visited[e.v]))
            {
                    minwt += e.wt;
                    cout << e.u << " " << e.v << " " << visited[e.u] << " " << visited[e.v] << endl;
                    current = (visited[e.u]?e.v:e.u);
                    break;
            }
        }

    } while (heapSize > -1);
    cout << minwt << endl;
}