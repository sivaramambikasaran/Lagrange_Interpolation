#!/bin/bash

echo "Enter the number of interpolation nodes"

read nodes

echo "Compiling the code..."

make -f makefile.mk clean >output.txt

make -f makefile.mk >output.txt

echo "Executing the code..."

./exec/Lagrange $nodes >output.txt

echo "Plotting the figure for interpolation using random nodes..."

pdflatex random_nodes.tex >output.txt

open random_nodes.pdf

echo "Plotting the figure for interpolation using uniformly spaced nodes..."

pdflatex uniform_spaced_nodes.tex >output.txt

open uniform_spaced_nodes.pdf

echo "Plotting the figure for interpolation using Chebyshev nodes..."

pdflatex chebyshev_nodes.tex >output.txt

open chebyshev_nodes.pdf

make -f makefile.mk clean >output.txt

rm output.txt