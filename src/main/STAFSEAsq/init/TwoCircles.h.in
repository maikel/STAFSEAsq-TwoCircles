#ifndef TWOCIRCLES_H_
#define TWOCIRCLES_H_

#include <exception>
#include <sstream>

namespace STAFSEAsq {
namespace init {

/**
 * This class describes the intial condition for two circles where one has its
 * center in the origin (0,0) and the other in (x,0) for some positive x > 0.
 */
template <typename floatT>
class TwoCircles {
private:
	// x-position of the intersection of the circles
	floatT a;
	// radius of left circle
	floatT R;
	// radius of right circle
	floatT r;

	// calculated x position of the second circle is a+b
	floatT b;
	// cacluated height of the intersection points
	floatT h;

public:
	template<typename floatT2>
	class InvalidParameter : public std::exception {
	private:
		floatT h;
		floatT b;
	public:
		InvalidParameter(floatT2 _h, floatT2 _b): h(_h), b(_b) {}

		virtual const char* what() const throw() {
			std::ostringstream out;
			out << "height h = " << h << ", offset b = " << b << ".";
			return out.str().c_str();
		}
	};

	/**
	 * Set constant circle parameters and check if the given parameters are
	 * valid. I.e. if they really define two intersecting circles.
	 */
	TwoCircles(floatT _a, floatT _R, floatT _r);

	/**
	 * Default destructor. Does nothing but can be overwritten.
	 */
	virtual ~TwoCircles();

	/**
	 * calclute the distance of the point P = (x,y) to the surface of the
	 * problem.
	 */
	floatT distance(floatT x, floatT y) const;
};

}
}

#endif /* TWOCIRCLES_H_ */
