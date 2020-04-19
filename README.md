
# Skip list

This project is a C++ implementation of the [skip list](https://en.wikipedia.org/wiki/Skip_list) data structure. A skip list has the interface of a set, meaning it has the operations `insert()`, `contains()` and `remove()`. All of them have `O(log n)` time complexity.

## Repository overview

- Type `make` to compile the program.
- Type `make run` to compile and run the program.
- Type `make tests` to compile and run the tests.
- Type `make clean` to remove generated files.

The file `list.h` contains the interface of the `List` class, which is the skip list. Its interface is also shown below:

```cpp
int size();
void insert(int value);
bool contains(int value);
void remove(int value);

Iterator begin();
Iterator end();
```

The file `main.cpp` contains a small example program that performs insertions and lookups, and measures the time for that.

The testing in this project includes unit tests and invariants. The invariants are checked after every `insert()` and `remove()` operation.

## Performance

Some measurements on my computer, with `check_invariations()` disabled.

| Number of elements  | Time for 100,000 `contains()` |
| ------------------- | ----------------------------- |
| 5,000               | 566 ms                        |
| 50,000              | 757 ms                        |
| 100,000             | 819 ms                        |
| 200,000             | 872 ms                        |
| 400,000             | 986 ms                        |

As the table shows, the number of elements does affect the time for `contains()`, but the growth is very slow thanks to the `O(log n)` time complexity of the skip list.

## 3rd party code

The unit tests in this project are done using [the Catch2 framework](https://github.com/catchorg/Catch2). It's being used under the BSL-1.0 license. The corresponding license file is `3RD-PARTY-LICENSES/catch2-license.txt`.

## Compatibility

This program was developed on Mac (macOS 10.14), but it should also work fine on Linux.