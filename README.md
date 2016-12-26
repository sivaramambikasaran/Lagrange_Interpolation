# LAGRANGE
===

Obtains Langrange interpolation, given a set of input data points in the [-1,1] and the function values at those points. Also, plots the interpolant in the interval.

This is a pure header only library and hence using this is pretty straight forward. There is no binary library to link to, no configured header file and all that annoying s$!t.

To use LAGRANGE, download the repository and copy the folder `LAGRANGE` to the desired directory you want.

	g++-6 -I /path/to/LAGRANGE myprogram.cpp -o myprogram

On Linux or Mac OS X, another option is to cymlink or copy the folder `LAGRANGE` into `/usr/local/include/`. This way you can compile the program as:

	g++-6 myprogram.cpp -o myprogram

An example file can be found inside the folder named `examples`.

More documentation to follow soon. In the meantime, you can browse through the header files in the `LAGRANGE` directory to decipher the features.

The plot generated from the individual file is shown below:

![Chebyshev interpolation with 100 nodes and function values in the interval [-1,1]](https://github.com/sivaramambikasaran/Lagrange_Interpolation/blob/master/chebyshev_nodes.png)

![Interpolation with 10 random nodes and function values in the interval [-1,1]](https://github.com/sivaramambikasaran/Lagrange_Interpolation/blob/master/random_nodes.png)

![Interpolation with 10 uniformly spaced nodes and function values in the interval [-1,1]](https://github.com/sivaramambikasaran/Lagrange_Interpolation/blob/master/uniform_nodes.png)