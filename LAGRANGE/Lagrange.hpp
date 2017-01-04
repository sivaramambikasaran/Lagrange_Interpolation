#ifndef _LAGRANGE__HPP_
#define _LAGRANGE__HPP_

#include <vector>
#include "CPLOT/cplot.hpp"

void find_max_min(std::vector<double> f, double& fmax, double& fmin) {
	int N	=	f.size();
	fmax	=	f[0];
	fmin	=	f[0];
	for (int j=1; j<N; ++j) {
		if (fmax < f[j]) {
			fmax	=	f[j];
		}
		if (fmin > f[j]) {
			fmin	=	f[j];
		}
	}
}

class Lagrange {
private:
	std::vector<double> xNodes;
	std::vector<double> fNodes;
	int N;

	std::vector<double> xPlot;
	std::vector<double> fPlot;
	int M;

	double x;
	double f;

	bool polyInterpComputed;

	void polyInterp();

public:
	//	Sets up the object by accepting the interpolation nodes and the function values
	Lagrange(std::vector<double> xNodes, std::vector<double> fNodes);

	//	Obtains the value of the interpolant at a specific location
	double polyInterp(double x);

	//	Obtains the value of the interpolant at a set of locations
	std::vector<double> polyInterp(std::vector<double> x);

	//	Draws the interpolant; Output is in the form of a tex file
	void drawplot(double a, double b, std::string fileName);
};

Lagrange::Lagrange(std::vector<double> xNodes, std::vector<double> fNodes) {
	this->xNodes		=	xNodes;
	this->fNodes		=	fNodes;
	this->N				=	xNodes.size();
	polyInterpComputed	=	false;
}

double Lagrange::polyInterp(double x) {
	this->x		=	x;
	f			=	0.0;
	for (int j=0; j<N; ++j) {
		double ftemp=	fNodes[j];
		for (int k=0; k<j; ++k) {
			ftemp*=((x-xNodes[k])/(xNodes[j]-xNodes[k]));
		}
		for (int k=j+1; k<N; ++k) {
			ftemp*=((x-xNodes[k])/(xNodes[j]-xNodes[k]));
		}
		f+=ftemp;
	}
	return f;
}

void Lagrange::polyInterp() {
	polyInterpComputed	=	true;
	this->fPlot.clear();
	for (int j=0; j<M; ++j) {
		fPlot.push_back(polyInterp(xPlot[j]));
	}
}

std::vector<double> Lagrange::polyInterp(std::vector<double> x) {
	this->xPlot	=	x;
	this->M		=	xPlot.size();
	polyInterp();
	return fPlot;
}

void Lagrange::drawplot(double a, double b, std::string fileName) {
	this->M		=	1000+10*N;
	this->xPlot.clear();
	xPlot.push_back(a);
	double dx	=	(b-a)/(M-1);
	for (int j=1; j<M; ++j) {
		xPlot.push_back(xPlot[j-1]+dx);
	}

	polyInterp();

	double fmax, fmin;
	double xmax, xmin;
	find_max_min(fPlot, fmax, fmin);
	find_max_min(xPlot, xmax, xmin);

	//	Setting up the canvas
	cplot A(fileName);
	A.xlabel("x");
	A.ylabel("f(x)");
	A.title("Interpolation");
	A.axes(xmin-0.1*xmin/fabs(xmin)*xmin, xmax + 0.1*xmax/fabs(xmax)*xmax, fmin - 0.1*fmin/fabs(fmin)*fmin, fmax + 0.1*fmax/fabs(fmax)*fmax);

	//	Setting up the plot; Plotting the interpolated curve
	plot myplot;
	myplot.xdata(xPlot);
	myplot.ydata(fPlot);
	myplot.curve("","black","thick",true);
	myplot.marks("no marks","");

	//	Adding the plot to the canvas
	A.plots.push_back(myplot);

	//	Setting up the plot; Plotting the interpolation nodes
	myplot.xdata(xNodes);
	myplot.ydata(fNodes);
	myplot.marks("only marks","red");

	//	Adding the plot to the canvas
	A.plots.push_back(myplot);

	//	Making the canvas with the plot(s)
	A.makeplot();
}

#endif //_LAGRANGE__HPP_