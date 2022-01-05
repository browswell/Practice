# Introduction

Min-heaps and max-heaps are special instances of trees, in that they maintain a property that their root node is always the minimum(or maximum) value in the tree.  That means they're particularly useful for ordered sets, such as a priority queue.  The other property of a min/max heap is that the heap is complete, up to the last level.  The implementation of the tree structure can be handled as an array, where the children of index I are at 2*I + 1 and 2*I + 2.


## Operations

Heaps have changes to the insert and delete operation, which involve shifting for maintaining their complete structure and property of minima/maxima.  
Heaps also have the operation heapify, which takes an unordered list and creates the appropriate heap.
Since heaps often act as a priority queue, one of the most used operations would be to pop the top element of the heap.  This is done by getting the root node for return, and deleting the root node from the heap, which forces the heap to rebalance.

## Pseudocode

class minheap{
    int *heap;
    int cur_size;

    int parent(int i){ return (i - 1) / 2; }

    void insert(int val){
        int i = cur_size;
        cur_size++;
        heap[cur_size] = val;

        while (i != 0 && heap[parent(i)] > heap[i]){
            swap(&heap[i], &heap[parent(i)]);
            i = parent(i);
        }
    }

    int pop(){
        int root = heap[0];
        heap[0] = heap[cur_size - 1];
        cur_size--;
        heapify(0);

        return root;
    }
    
    int delete(int val){
        int i = val;
        while(i != 0){
            swap(&heap[i], &heap[parent(i)]);
            i = parent(i);
        }
        return(pop());

    }

    void heapify(int index){
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int min = index;
        if(left < cur_size && heap[left] < heap[index])
            min = left;
        if(right < cur_size && heap[right] < heap[index])
            min = right;
        if(min != index){
            swap(&heap[index], &heap[min]);
            heapify(min);
        }
    }
}

