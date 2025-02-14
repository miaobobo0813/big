# Big library

Version 2.0

## Get started

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

## Start using the library

#### Create a high-precision type (`big`) variables.
```Cpp
big a, c;
big b(200);
```
This code creates three big type variables named `a`, `b`, and `c`, and sets the number of digits for `b` to 200. 

Note: The type supports up to 5000 digits.

#### Write a value to a variable of type `big`.
```Cpp
big a, b;
a.intw(50);
b.stringw("10");
```
This code overwrites `a` with the value `50` and `b` with the value `10`.

Note: 

  - The function `intw()` only writes `int` value.

  - The function `stringw()` only writes `string` value.

#### Print a variable of type `big`.
```Cpp
big a;
a.intw(50);
a.print();
```
This code prints the variable `a`.

## Operations

### Comparison operations.

#### Compare a variable of type `int`.
```Cpp
big a;
a.intw(50);
int b;
cin >> b;
cout << a.comint(b);
```
In this example, if `a >= b`, the output will be `1`. Otherwise, the output will be `0`.

```Cpp
big a;
a.intw(50);
int b;
cin >> b;
cout << a.eqint(b);
```
In this example, if `a == b`, the output will be `1`. Otherwise, the output will be `0`.

#### Compare a variable of type `big`.
```Cpp
big a, b;
a.intw(50);
int tmp;
cin >> tmp;
b.intw(tmp);
cout << a.combig(b);
```
In this example, if `a >= b`, the output will be `1`. Otherwise, the output will be `0`.

```Cpp
big a, b;
a.intw(50);
int tmp;
cin >> tmp;
b.intw(tmp);
cout << a.eqbig(b);
```
In this example, if `a == b`, the output will be `1`. Otherwise, the output will be `0`.

#### Note: Comparison operations return a value of type `bool`.

### Arithmetic operations.

#### Add another variable of type `big`.
```Cpp
big a, b, c;
int t1, t2;
cin >> t1 >> t2;
a.intw(t1);
b.intw(t2);
c = a.plusbig(b);
c.print();
```
In this example, the program will output result of `t1 + t2`, namely the value of `a+b`.

Note: `plusbig()` returns a value of type `big`.

#### Subtract another variable of type `big`.
```Cpp
big a, b, c;
int t1, t2;
cin >> t1 >> t2;
a.intw(t1);
b.intw(t2);
c = a.subbig(b);
c.print();
```
In this example, the program will output result of `t1 - t2`, namely the value of `a-b`.

Note: 
  - `subbig()` returns a value of type `big`.
  - If the result is negative, throw an exception: "The answer is a negative number."

#### Multiply by another variable of type `int`.
```Cpp
big a, c;
int t1, b;
cin >> t1 >> b;
a.intw(t1);
c = a.mulint(b);
c.print();
```
In this example, the program will output the product of `t1 * b`, namely the value of `a*b`.

Note: `mulint()` returns a value of type `big`.
