#include "./RedBlack.hpp"
#include <vector>

int main()
{
    RedBlack<int> test;
    test.insert(4);
    test.insert(12);

    test.print_tree(test.root);


}