Author          : Jinhao Jiang
Created         : September 24, 2018
Last Modified   : September 28, 2018

Affiliation          : Georgia Institute of Technology


Description
-------------

This program generate a graph based on the input data.

For the command line arguments:
argv[1] indicates the number of rows (columns) of the grids.
argv[2] indicates the probability of generating colored cell (marked with '1' in the program).


Installation
------------

To install, simply run

    gcc main.c graphgen.h -std=c99 -o graphgen


Execution
-----------

Run it using

(for instance)

    ./graphgen 10 0.3 topology.txt

