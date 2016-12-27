#include <iostream>
#include <cstdlib>
#include <cmath>
#include "LAGRANGE/Lagrange.hpp"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int N			=	atoi(argv[1]);
	int M			=	atoi(argv[2]);
	double RMAX		=	RAND_MAX;

	std::vector<double> f;

	for (int j=0; j<N; ++j) {
		f.push_back(rand()/RMAX);
	}

	std::vector<double> x;

	/****************************/
	//	Random set of points
	/****************************/

	for (int j=0; j<N; ++j) {
		x.push_back(-1.0+2.0*rand()/RMAX);
	}

	Lagrange random_nodes("random_nodes.tex", x, f, M);

	/****************************/
	//	Uniformly spaced points
	/****************************/

	x.clear();
	for (int j=0; j<N; ++j) {
		x.push_back(-1.0+(2.0*j+1)/N);
	}

	Lagrange uniform_nodes("uniform_spaced_nodes.tex", x, f, M);
	/****************************/
	//	Chebyshev points
	/****************************/

	x.clear();
	double pi	=	3.141592653589793238;
	for (int j=-N+1; j<N; j+=2) {
		x.push_back(sin(0.5*pi*j/N));
	}

	Lagrange cheb_nodes("chebyshev_nodes.tex", x, f, M);
}