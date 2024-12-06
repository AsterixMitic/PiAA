#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node* parent;
    vector<Node*> children;

    Node(int val) {
        value = val;
        parent = nullptr;
        children.clear();
    }
};