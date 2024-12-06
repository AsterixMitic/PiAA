#pragma once
#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class BinomialHeap {

    vector<Node*> trees;
    Node* minn;
    int count;

public:
    BinomialHeap() {
        minn = nullptr;
        count = 0;
        trees.clear();
    }

    bool is_empty() {
        return minn == nullptr;
    }

    void insert(int value) {
        Node* node = new Node(value);
        BinomialHeap heap;
        heap.trees.push_back(node);
        heap_union(heap);
    }

    int get_min() {
        return minn->value;
    }

    int extract_min() {
        Node* minNode = minn;
        trees.erase(remove(trees.begin(), trees.end(), minNode), trees.end());
        BinomialHeap heap;
        heap.trees = minNode->children;
        heap_union(heap);
        find_min();
        count--;
        return minNode->value;
    }

    void heap_union(BinomialHeap& h2) {
        trees.insert(trees.end(), h2.trees.begin(), h2.trees.end());
        count += h2.count;
        find_min();
    }

    void find_min() {
        minn = nullptr;
        for (Node* tree : trees) {
            if (minn == nullptr || tree->value < minn->value) {
                minn = tree;
            }
        }
    }

};