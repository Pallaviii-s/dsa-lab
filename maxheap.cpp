#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

public:
    vector<int>& getHeap() {
        return heap;
    }
};

// Helper function to maintain the max-heap property (heapify up)
void heapifyUp(MaxHeap& pq, int index) {
    vector<int>& heap = pq.getHeap();
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Helper function to maintain the max-heap property (heapify down)
void heapifyDown(MaxHeap& pq, int index) {
    vector<int>& heap = pq.getHeap();
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(pq, largest);
    }
}

// Insert an element into the heap
void insert(MaxHeap& pq, int value) {
    vector<int>& heap = pq.getHeap();
    heap.push_back(value);
    heapifyUp(pq, heap.size() - 1);
}

// Delete the root of the heap (max element)
void deleteRoot(MaxHeap& pq) {
    vector<int>& heap = pq.getHeap();
    if (heap.empty()) {
        cout << "Heap is empty, nothing to delete!" << endl;
        return;
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(pq, 0);
}

// Display the contents of the heap
void display(MaxHeap& pq) {
    vector<int>& heap = pq.getHeap();
    if (heap.empty()) {
        cout << "Heap is empty!" << endl;
        return;
    }
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;
}

// Search for an element in the heap
bool search(MaxHeap& pq, int value) {
    vector<int>& heap = pq.getHeap();
    for (int i : heap) {
        if (i == value) {
            return true;
        }
    }
    return false;
}

// Heap Sort (Sort the elements in non-increasing order)
void heapSort(MaxHeap& pq) {
    vector<int>& heap = pq.getHeap();
    vector<int> original = heap;
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(pq, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        heapifyDown(pq, 0);
    }
    // Display the sorted array
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;
    heap = original; // Restore original heap
}

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\nPriority Queue Menu (using Max Heap):" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Search" << endl;
        cout << "5. Sort (Heap Sort)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(pq, value);
                break;
            case 2:
                deleteRoot(pq);
                break;
            case 3:
                display(pq);
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(pq, value)) {
                    cout << "Element found in the heap!" << endl;
                } else {
                    cout << "Element not found!" << endl;
                }
                break;
            case 5:
                heapSort(pq);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

/*
Insert and Delete operations are O(log n)
Display and Search are O(n)
Heap Sort is O(n log n)
*/