# Big library

Version 2.0

## Start using

1. To download the library, please use the following command:
```Bash
git clone https://github.com/miaobobo0813/big.git
```

2. Copy "big.h" and "big.cpp" to your C++ include directory.
  - Use `echo | gcc -Wp,-v -x c++ -` (for GCC compilers) or `clang -E -x c++ -v -` (for Clang compilers) to find your C++ include directory.

3. Include the library in your code using:
   ```Cpp
   #include <big.h>
   ```

## Use the library

#### 1. Create a high-precision type (`big`) variables.
```Cpp
big a, b;
big c(200);
```
This code creates three big type variables named `a`, `b`, and `c`, and sets the number of digits for `c` to 200. 

Note: The type supports up to 5000 digits.

#### 2. Write a value to a variable of type `big`.
```Cpp
a.intw(50);
b.stringw("10");
```
This code overwrites `a` with the value `50` and `b` with the value `10`.

Note: 

  - The function `intw()` only writes `int` value.

  - The function `stringw()` only writes `string` value.
