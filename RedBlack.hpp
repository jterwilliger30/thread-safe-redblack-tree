#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <iostream>

namespace RB {

    template <typename T> class Node
    {
    private:

    public:
        Node(T);
        // Compiler generated destructor is fine for this class.

        T val;
        bool isRed;

        Node<T> *left, *right, *parent;
    };


    template <typename T> class RedBlack
    {
    private:
        Node<T>* rotate_right(Node<T>*);
        Node<T>* rotate_left(Node<T>*);
        void flip_colors(Node<T>*);

        bool isRed(Node<T>*);

        void recursive_destroy(Node<T>*);

    public:
        RedBlack();
        ~RedBlack();

        Node<T>* root;

        void insert(T);
        T pop(T);

        Node<T>* search(T desired_val, Node<T>*);
        Node<T>* search(T desired_val);

        void print_tree(const std::string& prefix, const Node<T> *node, bool isLeft);
        void print_tree(const Node<T> *node);

        // TO DO
        void pop(T);

    };
} // Namespace RedBlack

/* VERY IMPORTANT!!! Template implementation MUST be located in the header file. 
Otherwise the compiler cannot make class definition for each type. */
#include "./RedBlack.tpp"

#endif
