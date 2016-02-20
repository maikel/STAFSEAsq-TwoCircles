#include "TwoCircles.h"

#include <iostream>
#include <array>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	STAFSEAsq::TwoCircles<float> circles(5., 7., 6.);

	size_t N = 0;

	if (argc > 1) {
		stringstream conversion;
		conversion << argv[1];
		conversion >> N;
	}

	if (N == 0) {
		cerr << "N = 0, Aborting.\n";
		return -1;
	}

	array<float, 2> dim_X { -8, 17 };
	array<float, 2> dim_Y { -10, 10 };
	array<float, 2> h { (dim_X[1] - dim_X[0]) / N, (dim_Y[1] - dim_Y[0]) / N };

	vector<float> X(N);
	vector<float> Y(N);

	if (X.capacity() < N || Y.capacity() < N) {
		cerr << "Some allocation error occured.\n";
		return -1;
	}

	for (size_t i = 0; i < N; i++) {
		X[i] = dim_X[0] + i * h[0];
		Y[i] = dim_Y[0] + i * h[1];
	}

	cerr << "Calculating grid distances... ";

	vector<vector<float>> grid(N, vector<float>(N));
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			grid[i][j] = circles.distance(X[i], Y[j]);
		}
	}

	cerr << "done.\n";
	cerr << "Press a key to print data to standard output.\n";
	cerr << "Enter 'X' to abort.\n";
	cerr << "Input> ";
	if ((char) cin.get() != 'X') {
		cerr << "Writing to standard output.\n";
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < N; j++) {
				cout << X[i] << " " << Y[j] << " " << grid[i][j] << endl;
			}
			cout << endl;
		}
	} else {
		cerr << "Aborted.\n";
	}

	return 0;
}
