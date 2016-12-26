#include"CPLOT/cplot.hpp"

double Lagrange(std::vector<double> x, std::vector<double> f, double xplot) {
	int N			=	x.size();
	double fplot	=	0.0;
	for (int j=0; j<N; ++j) {
		double ftemp=	f[j];
		for (int k=0; k<j; ++k) {
			ftemp*=((xplot-x[k])/(x[j]-x[k]));
		}
		for (int k=j+1; k<N; ++k) {
			ftemp*=((xplot-x[k])/(x[j]-x[k]));			
		}
		fplot+=ftemp;
	}
	return fplot;
}

void plotinterp(std::string filename, std::vector<double> x, std::vector<double> f, int M) {
	std::vector<double> xplot;

	for (int j=0; j<M; ++j) {
		xplot.push_back(-1.0+2.0*double(j)/M);
	}
	std::vector<double> fplot;
	for (int j=0; j<M; ++j) {
		fplot.push_back(Lagrange(x, f, xplot[j]));
	}

	double fmax	=	fplot[0];
	double fmin	=	fplot[0];
	for (int j=1; j<M; ++j) {
		if (fplot[j] > fmax) {
			fmax	=	fplot[j];
		}
		if (fplot[j] < fmin) {
			fmin	=	fplot[j];
		}
	}

	cplot A(filename);
	A.xlabel("x");
	A.ylabel("f(x)");
	A.title("Interpolation");
	A.axes(-1,1,(1-fmin/fabs(fmin))*fmin,1.1*fmax);

	plot myplot;
	myplot.xdata(xplot);
	myplot.ydata(fplot);
	myplot.curve("","black","thick",true);
	myplot.marks("no marks", "");
	A.plots.push_back(myplot);

	myplot.xdata(x);
	myplot.ydata(f);
	myplot.marks("only marks","red");
	A.plots.push_back(myplot);

	A.makeplot();
}