#ifndef JSCPP_ARRAY_H__
#define JSCPP_ARRAY_H__

#include <vector>
#include <string>
#include <ostream>

namespace JSCPP {

	template <class T>
	class Array {

		private:
			std::vector<T> realVector;

		public:

			T operator[](const unsigned int i) { return (i < size()) ? realVector[i] : NULL; }
			template <T> friend std::ostream& operator<<(std::ostream&, Array<T>&);

			unsigned int length() { return realVector.size(); }
			unsigned int size()   { return realVector.size(); }

			// TODO: sort

			std::string toString() { return ","; }

			// valueOf: not implemented

			T& first() { return realVector[0]; }
			T& last() { return realVector[size() - 1]; };

			bool isEmpty() { return length() == 0; }

	};

	template <class T> std::ostream& operator<<(std::ostream& out, Array<T>& arr) {
		out << '[' << arr.join(", ") << ']';
	}

};

#endif
