Author          : Jinhao Jiang
Created         : September 3, 2018
Last Modified   : September 6, 2018

Affiliation          : Georgia Institute of Technology


Description
-------------

This program contains two parts:

(1) Define five functions in the header file (.h). Including: 
     a. "malloc_matrix": Apply for the dynamic allocation for a matrix which has n1 rows and n2 columns;
     b. "free_matrix": Release the dynamic memory of a matrix which has n1 rows and n2 columns;
     c. "fill_matrix": Fill a matrix, which has dimensions n1 by n2, with random floating point, double precision numbers;
     d. "print_matrix": Print a matrix with dimensions n1 by n2;
     e. "matrix_multiplication": Multiply Matrix a (n1 * n2) and Matrix b (n2 * n3), and store the product in Matrix c (n1 * n3).

(2) Write a test program (.c) to calculate an example: 
     a. Apply for dynamic allocation for Matrix A (4 * 3), Matrix B (3 * 2) and Matrix C (4 * 2);
     b. Fill and print Matrix A and B successively;
     c. Multiply Matrix A and B, store the product in Matrix C, and then print Matrix C.
     d. Release the memory of Matrix A, B and C.


Installation
------------

To install, simply run

    gcc A1B.c -std=c99 -o A1B


Execution
-----------

Run it using

    ./A1B 

