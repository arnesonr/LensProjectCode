Files submitted:
lens.c
Makefile
readme.txt
project.tex
project.dvi
project.pdf

To compile lens.c, type: 'g++ lens.c -o lens'

To run the program type: 'lens file.pgm', where file.pgm is the name of the file that the output will be written to (it need not exist, it will be created, if it already exists it will be written over).  The program will then ask you to input the number of lens galaxies and source galaxies as well as their parameters.  The output can be viewed using gimp.

Some interesting examples to consider are:

An "Einstein ring" with the following parameters:  
Lens Galaxy: [b = 100, xcen = 0, ycen = 0, axis ratio = 1.0, position angle = 0]
Source Galaxy: [amp = 30, sigma = 10, xcen = 0, ycen = 0, axis ratio = 1.0, position angle = 0]

An "Einstein cross" with the following parameters:
Lens Galaxy: [b = 50, xcen = 0, ycen = 0, axis ratio = 0.5, position angle = 0]         
Source Galaxy: [amp = 10, sigma = 2, xcen = 0, ycen = 0, axis ratio = 1.0, position angle = 0]
