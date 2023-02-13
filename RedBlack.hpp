#ifndef REDBLACK_HPP
#define REDBLACK_HPP

namespace RB {

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

        

        // TO DO
        void pop(T);
    };
} // Namespace RedBlack

// VERY IMPORTANT (I think)!!! Template implementation MUST be located in the header file.
#include "./RedBlack.tpp"

#endif
