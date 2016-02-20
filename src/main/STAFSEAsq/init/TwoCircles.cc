#include "STAFSEAsq/init/TwoCircles.h"

#include <array>
#include <cmath>
#include <iostream>

using std::array;
using std::sqrt;
using std::min;
using std::abs;

namespace STAFSEAsq {
namespace init {

// You can only use this class with float or double

template class TwoCircles<float> ;
template class TwoCircles<double> ;

/**
 * Throw an exception if parameters are inconsistent.
 */
template<typename floatT>
TwoCircles<floatT>::TwoCircles(floatT _a, floatT _R, floatT _r) :
		a(_a), R(_R), r(_r) {
	h = R * R - a * a;
	b = r * r - h;
	if (h <= 0 || b <= 0) {
		throw InvalidParameter<floatT>(h, b);
	}
	h = sqrt(h);
	b = sqrt(b);
}

/**
 * Keep an empty the destructor for possible inheritance.
 */
template<typename floatT>
TwoCircles<floatT>::~TwoCircles() {
	// empty destructor
}

/*
 * Define some vector operations like Difference and scalar product here.
 */

template<typename floatT>
floatT operator*(const array<floatT, 2> &x, const array<floatT, 2> &y) {
	return x[0] * y[0] + x[1] * y[1];
}

template<typename floatT>
array<floatT, 2> operator*(floatT lambda, const array<floatT, 2> &x) {
	return array<floatT, 2>( { x[0] * lambda, x[1] * lambda });
}

template<typename floatT>
array<floatT, 2> operator-(const array<floatT, 2> &x,
		const array<floatT, 2> &y) {
	return {x[0]-y[0], x[1]-y[1]};
}

template<typename floatT>
floatT norm(array<floatT, 2> x) {
	return sqrt(x * x);
}

/**
 * calclute the distance to the surface of the problem
 */
template<typename floatT>
floatT TwoCircles<floatT>::distance(floatT x, floatT y) const {
	// vector representation of input
	array<floatT, 2> Y = { x, y };
	// vector to the origin of the snd circle
	array<floatT, 2> X = { a + b, 0 };
	// this vector defines hyperplane conditions
	array<floatT, 2> Q;

	if (abs(y) < h) {
		array<floatT, 2> upper = {a, h};
		array<floatT, 2> lower = {a, -h};

		if (x < a && y >= 0) {
			Q = {h, -a};
			floatT mu = Y*Q;
			if (mu > 0)
				return norm(Y-upper);
			else
				return abs(norm(Y)-R);
		} else if (x >= a && y >= 0) {
			Q = {-h, -b};
			floatT mu = (Y-upper)*Q;
			if (mu > 0)
				return norm(Y-upper);
			else
				return abs(norm(Y - X) - r);
		} else if (x < a && y < 0) {
			Q = {h, a};
			floatT mu = Y*Q;
			if (mu > 0)
				return norm(Y-lower);
			else
				return abs(norm(Y)-R);
		} else if (x >= a && y < 0) {
			Q = {-h, +b};
			floatT mu = (Y-lower)*Q;
			if (mu > 0)
				return norm(Y-lower);
			else
				return abs(norm(Y - X) - r);
		}
	}
	return min(abs(norm(Y) - R), abs(norm(Y - X) - r));
}

}
}
