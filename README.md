(NOT FINISHED)
This is my attempt at implementing a red black tree. It works on any data type that has defined operators of less than, greater than, and equal to.

- Please note, because this implementation uses std::make_unique to create smart pointers, this program can only be compiled with C++ 14 or later... This program can be made compatible with C++ 11 while still using smart pointers if make_unique is not used, but I have chosen not to do that here.

Concepts to practice:
- Unique & shared pointers
- Template metaprogramming... I don't think I've ever been this frustrated with syntax before. The compiler is very picky when you have separtate header and implementation files.
- Ternary operators

TO DO
- Write destructors
- Rewrite to make thread-safe (yikes)
- Test using Valgrind
- Benchmarks
- Unit test cases
