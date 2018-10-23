Author          : Jinhao Jiang
Created         : September 26, 2018
Last Modified   : September 28, 2018

Affiliation          : Georgia Institute of Technology


Description
-------------

Based on the graph created by the program, "graphgen", analyze the components in the graph with application of the algorithm of Depth First Search.

For the command line arguments:
argv[1] indicates the input file. ("topology.txt" inside the folder "graphgen")
argv[2] indicates the output file. ("outfile.txt" inside the folder "components")


Installation
------------

To install, simply run

    gcc main.c components.h -std=c99 -o components


Execution
-----------

Run it using

(for instance)

    ./components topology.txt outfile.txt

