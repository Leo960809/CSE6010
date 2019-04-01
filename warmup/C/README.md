Author          : Jinhao Jiang
Created         : September 12, 2018
Last Modified   : September 14, 2018

Affiliation          : Georgia Institute of Technology


Description
-------------

This program goes as follows:
(1) Create an empty priority queue;
(2) Ramdomly generate 20 data elements, of which the values and the priority are respectively random float numbers between [0.0, 10.0] and [0.0, 20.0], and print them as well;
(3) Insert it into the queue in accordance to the priority, smaller priority value indicates higher priority;
(4) Remove the elements one after another. Meanwhile, print the value and priority of the deleted items in order to verify the priority queue;
(5) Delete the queue by releasing the memory used by it.


Installation
------------

To install, simply run

    gcc A1C.c -std=c99 -o A1C


Execution
-----------

Run it using

    ./A1C 

