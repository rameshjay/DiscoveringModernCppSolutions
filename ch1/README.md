
# 1.10 Exercises

## 1.10.1 Age

Write a program that asks input from the keyboard and prints the result on the screen and
writes it to a file. The question is: “What is your age?”

## 1.10.2 Arrays and Pointers

1. Write the following declarations: pointer to a character, array of 10 integers, pointer to
an array of 10 integers, pointer to an array of character strings, pointer to pointer to
a character, integer constant, pointer to an integer constant, constant pointer to an
integer. Initialize all these objects.

2. Make a small program that creates arrays on the stack (fixed-size arrays) and arrays
on the heap (using allocation). Use valgrind to check what happens when you do not
delete them correctly.

## 1.10.3 Read the Header of a Matrix Market File

The Matrix Market data format is used to store dense and sparse matrices in ASCII format.
The header contains some information about the type and the size of the matrix. For a
sparse matrix, the data is stored in three columns. The first column is the row number, the
second column the column number, and the third column the numerical value. When the
value type of the matrix is complex, a fourth column is added for the imaginary part.
An example of a Matrix Market file is

```
%%MatrixMarket matrix coordinate real general
%
% ATHENS course matrix
%
2025
2025
100015
1
1
.9273558001498543E-01
1
2
.3545880644900583E-01
...................
```
The first line that does not start with % contains the number of rows, the number of columns,
and the number of non-zero elements on the sparse matrix.
Use fstream to read the header of a Matrix Market file and print the number of rows and
columns, and the number of non-zeroes on the screen.
