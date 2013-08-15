#ifndef JSCPP_MATH_H__
#define JSCPP_MATH_H__

#include <cmath>
#include <ctime>
#include <cstdlib>

namespace JSCPP {

	class MathConstructor {

		private:
			bool randomCalled;

		public:

			static const double E = 2.718281828459045;
			static const double LN2 = 0.6931471805599453;
			static const double LN10 = 2.302585092994046;
			static const double LOG2E = 1.4426950408889634;
			static const double LOG10E = 0.4342944819032518;
			static const double PI = 3.141592653589793;
			static const double SQRT1_2 = 0.7071067811865476;
			static const double SQRT2 = 1.4142135623730951;

			MathConstructor() {
				randomCalled = false;
			}

			double abs(double d) { return std::abs(d); } 

			double acos(double d) { return std::acos(d); }
			double asin(double d) { return std::asin(d); }
			double atan(double d) { return std::atan(d); }
			double atan2(double x, double y) { return std::atan2(x, y); }
			double sin(double d) { return std::sin(d); }
			double cos(double d) { return std::cos(d); }
			double tan(double d) { return std::tan(d); }
			double log(double d) { return std::log(d); }
			double exp(double d) { return std::exp(d); }
			double sqrt(double d) { return std::sqrt(d); }
			double pow(double b, double e) { return std::pow(b, e); }

			double ceil(double d) { return std::ceil(d); }
			double floor(double d) { return std::floor(d); }
			double round(double d) {
				if (d >= 0) {
					return floor(d + .5);
				} else {
					return ceil(d - .5);
				}
			}

			double max(double a, double b) {
				if (a >= b)
					return a;
				else
					return b;
			}

			double min(double a, double b) {
				if (a <= b)
					return a;
				else
					return b;
			}

			double random() {
				if (!randomCalled) {
					std::srand(std::time(NULL));
					randomCalled = true;
				}
				return std::rand() / RAND_MAX;
			}

			int sign(double d) {
				if (d == 0)
					return 0;
				else
					return d / abs(d);
			}

	};

	MathConstructor Math;

};

#endif
