#include "./RedBlack.hpp"

#include <iostream>
#include <string>

int main()
{

    RB::RedBlack<int> test;
    test.insert(4);
    test.insert(12);

    test.print_tree(test.root);


}