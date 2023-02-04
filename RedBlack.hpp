#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <string>
#include <iostream>

template <typename T> class Node
{
private:

public:
    Node(T);

    T val;
    bool isRed;

    Node<T> *left, *right, *parent;
};


template <typename T> class RedBlack
{
private:
    void balance_tree(Node<T>*);

public:
    RedBlack();

    Node<T>* root;

    void insert(T);

    Node<T>* search(T desired_val, Node<T>*);
    Node<T>* search(T desired_val);

    void print_tree(const std::string& prefix, const Node<T> *node, bool isLeft);
    void print_tree(const Node<T> *node);

    // TO DO
    void pop(T);
};

// VERY IMPORTANT (I think)!!! Template implementation MUST be located in the header file.
#include "./RedBlack.cpp"

// Explicit instantiation of supported types (only integers for now)
template class RedBlack<int>;

#endif
