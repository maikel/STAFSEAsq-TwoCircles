#include "STAFSEAsq/init/TwoCircles.h"

#include <cmath>
#include <cassert>
#include <vector>

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


template<typename floatT>
floatT norm(floatT x, floatT y) {
	return sqrt(x * x + y * y);
}

/**
 * calclute the distance to the surface of the problem
 */
template<typename floatT>
floatT TwoCircles<floatT>::distance(floatT x, floatT y) const {

	if (abs(y) < h) {
		if (x < a && y >= 0) {
			floatT mu = x*h - y*a;
			if (mu > 0)
				return norm(x-a, y-h);
			else
				return abs(norm(x,y)-R);
		} else if (x >= a && y >= 0) {
			floatT mu = (a-x)*h + (h-y)*b;
			if (mu > 0)
				return norm(x-a, y-h);
			else
				return abs(norm(x-a-b, y) - r);
		} else if (x < a && y < 0) {
			floatT mu = x*h + y*a;
			if (mu > 0)
				return norm(x-a, y+h);
			else
				return abs(norm(x,y)-R);
		} else if (x >= a && y < 0) {
			floatT mu = (a-x)*h + (y+h)*b;
			if (mu > 0)
				return norm(x-a, y+h);
			else
				return abs(norm(x-a-b, y) - r);
		}
	}
	return min(abs(norm(x,y) - R), abs(norm(x-a-b, y) - r));
}

}
}
