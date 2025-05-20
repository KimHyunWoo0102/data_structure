#pragma once

template<typename T>
class MultiLinkedNode:public Node {
public:
    T data;
    MultiLinkedNode* nextProduct;
    MultiLinkedNode* nextCustomer;

    MultiLinkedNode(const T& d) : data(d), nextProduct(nullptr), nextCustomer(nullptr) {}
};