# How to

## How to get the sources

```batch
$ git clone https://github.com/zemasoft/wildcards
$ cd wildcards
$ git submodule update --init --recursive
```

## How to build tests

```batch
$ cmake . -Bbuild -DCMAKE_BUILD_TYPE=Debug -DWILDCARDS_BUILD_TESTS=ON
$ cmake --build build
```

## How to run the tests

```batch
$ cd build
$ ctest
```

## How to build tests

```batch
$ cmake . -Bbuild -DCMAKE_BUILD_TYPE=Release -DWILDCARDS_BUILD_EXAMPLES=ON
$ cmake --build build
```

## How to find examples

```batch
$ ls build/examples/example*
```
