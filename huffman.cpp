#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Compare function for priority queue (min heap)
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return l->freq > r->freq;
    }
};

// Print Huffman codes from root of tree
void printCodes(MinHeapNode* root, string code) {
    if (!root)
        return;

    // If this is a leaf node, print the character and code
    if (!root->left && !root->right)
        cout << root->data << ": " << code << "\n";

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Main Huffman function
void HuffmanCodes(char data[], int freq[], int size) {
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    // Step 1: Create leaf nodes for each character
    for (int i = 0; i < size; i++)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Step 2: Build Huffman Tree
    while (minHeap.size() > 1) {
        MinHeapNode *left = minHeap.top(); minHeap.pop();
        MinHeapNode *right = minHeap.top(); minHeap.pop();

        // Create new internal node with combined frequency
        MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Step 3: Print the codes
    printCodes(minHeap.top(), "");
}

int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanCodes(data, freq, size);
    return 0;
}

