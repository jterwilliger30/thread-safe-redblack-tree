#include "./RedBlack.hpp"

int main()
{

    RB::RedBlack<int> test;
    test.insert(4);
    test.insert(12);
    test.insert(13);
    test.insert(14);

    test.print_tree(test.root);


}