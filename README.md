(NOT FINISHED)
This is my attempt at implementing a red black tree. It works on any data type that has defined operators of less than, greater than, and equal to.

- This program can only be compiled with C++ 11 or later.

Concepts to practice:
- Template metaprogramming... I don't think I've ever been this frustrated with syntax before. The compiler is very picky about template declarations vs definitions. Lesson learned: templates are not classes themselves. The compiler uses templates to make separate classes for each type, but there are important syntactic distinctions that result from this.
- Ternary operators
- Unique and shared pointers***

TO DO
- Rewrite to make thread-safe (yikes) -> Mutex on a per node bases? Parallel reads, sequential writes?
- Test using Valgrind
- Benchmarks
- Unit test cases



***I decided not to use unique/shared pointers in this module, since the single ownership enforced by unique pointers would require that a given tree node belongs to its parent node.
I read that this is not ideal, because nodes should belong to the overall data structure (a tree in this case), and not any sub-component within the tree. It is the tree destructor's responsibility to traverse & deallocate the tree. I have used raw pointers instead. The module will be tested with Valgrind to ensure there are no memory leaks. Results forthcoming.
