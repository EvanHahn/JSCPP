#ifndef JSCPP_H__
#define JSCPP_H__

#include <vector>
#include <string>
#include <string.h>
#include <ostream>
#include <math.h>

namespace JSCPP {

	template <class T> class Array;
	class Number;
	class String;
	class MathConstructor;
	class ConsoleContructor;

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

			String toString() { return join(","); }

			// valueOf: not implemented

			T& first() { return realVector[0]; }
			T& last() { return realVector[size() - 1]; };

			bool isEmpty() { return length() == 0; }

	};

	template <class T> std::ostream& operator<<(std::ostream& out, Array<T>& arr) {
		out << '[' << arr.join(", ") << ']';
	}

	class Number {

		private:
			double realDouble;

		public:

			Number()                     { realDouble = 0; }
			Number(const int n)          { realDouble = (double) n; }
			Number(const float n)        { realDouble = (double) n; }
			Number(const double n)       { realDouble = n; }
			Number(const unsigned int n) { realDouble = (double) n; }

			// TODO: all of these
			bool operator==(const Number& other);
			Number operator+(const Number& other);
			Number operator-(const Number& other);
			Number operator*(const Number& other);
			Number operator/(const Number& other);
			Number operator%(const Number& other);
			Number operator&(const Number& other);
			Number operator^(const Number& other);
			Number operator<<(const Number& other);
			Number operator>>(const Number& other);
			void operator+=(const Number& other);
			void operator-=(const Number& other);
			void operator*=(const Number& other);
			void operator/=(const Number& other);
			void operator%=(const Number& other);
			void operator&=(const Number& other);
			void operator^=(const Number& other);
			void operator<<=(const Number& other);
			void operator>>=(const Number& other);
			bool operator<(const Number& other);
			bool operator<=(const Number& other);
			bool operator>(const Number& other);
			bool operator>=(const Number& other);
			bool operator!() { return false; }
			Number operator~() { return Number(~realDouble); }

			friend std::ostream& operator<<(std::ostream&, Number&);

			static bool isInteger(const Number& n) {
				return false; // TODO
			}

			// toExponential: not implemented

			// toFixed: not implemented

			// toLocaleString: not implemented

			// toPrecision: not implemented

			String toString() { return String(""); }

			// valueOf: not implemented

			int toInt()         { return (int) realDouble; }
			int toUnsignedInt() { return (unsigned int) realDouble; }
			int toFloat()       { return (float) realDouble; }
			int toDouble()      { return realDouble; }

	}

	class String {

		private:
			std::string realString;
			int clamp(int number, int lower, int upper) {
				if (number < lower) return lower;
				if (number > upper) return upper;
				return number;
			}

		public:

			String()                      { realString = ""; }
			String(const char c)          { realString = c; }
			String(const char* str)       { realString = str; }
			String(const std::string str) { realString = str; }

			bool operator==(const String& other)    { return realString == other.realString; }
			String operator+(const String other)    { return realString + other.realString; }
			void operator+=(const String& other)    { realString += other.realString; }
			char& operator[](const unsigned int i)  { return charAt(i); }
			bool operator!()                        { return false; }
			bool operator<(const String& other)     { return realString < other.realString; }
			bool operator>(const String& other)     { return realString > other.realString; }
			bool operator<=(const String& other)    { return realString <= other.realString; }
			bool operator>=(const String& other)    { return realString >= other.realString; }
			int operator~()                         { return -1; }

			friend std::ostream& operator<<(std::ostream&, String&);

			unsigned int length() { return realString.size(); }
			unsigned int size()   { return length(); }

			char& charAt(const unsigned int i) { return realString[i]; }

			unsigned int charCodeAt(const unsigned int i) { return (unsigned int) realString[i]; }

			String concat(const String& other) { return realString + other.realString; }

			bool contains(const String& other) { return indexOf(other) != -1; }

			bool endsWith(const String& other) {
				if (contains(other)) {
					unsigned int lastSpot = (unsigned int) lastIndexOf(other);
					return (lastSpot + other.realString.size()) == size();
				} else {
					return false;
				}
			}

			// fromCharCode: not implemented

			int indexOf(const String& other) {
				std::size_t found = realString.find(other.realString);
				if (found == std::string::npos)
					return -1;
				else
					return (int) found;
			}

			int lastIndexOf(const String& other) {
				std::size_t found = realString.rfind(other.realString);
				if (found == std::string::npos)
					return -1;
				else
					return (int) found;
			}

			// localeCompare: not implemented

			// match: not implemented

			String replace(const String& needle, const String& replacement) {
				// TODO
				return "";
			}

			String replaceAll(const String& needle, const String& replacement) {
				String result = realString;
				while (result.contains(needle))
					result = result.replace(needle, replacement);
				return result;
			}

			// search: not implemented

			String slice(int beginSlice, int endSlice) {
				// TODO
				return "";
			}
			String slice(int beginSlice) { return slice(beginSlice, length()); }

			// TODO: split

			bool startsWith(const String& other) { return indexOf(other) == 0; }

			String substr(int start, int length) {
				// TODO
				return "";
			}
			String substr(int start) { return substr(start, length()); }

			String substring(int start, int end) {
				start = clamp(start, 0, length());
				end = clamp(end, 0, length());
				// TODO
				return "";
			}
			String substring(int start) { return substring(start, length()); }

			// toLocaleLowerCase: not implemented

			// toLocaleUpperCase: not implemented

			String toLowerCase() {
				String result;
				for (unsigned int i = 0, len = size(); i < len; i ++)
					result += tolower(realString[i]);
				return result;
			}

			// toString: not implemented

			String toUpperCase() {
				String result;
				for (unsigned int i = 0, len = size(); i < len; i ++)
					result += toupper(realString[i]);
				return result;
			}

			String trim() { return trimLeft().trimRight(); }

			String trimLeft() {
				unsigned int i;
				for (i = 0; (i < size()) && (charAt(i) == ' '); i ++);
				return realString.substr(i);
			}

			String trimRight() {
				if (isEmpty()) return "";
				unsigned int i;
        for (i = size() - 1; (i > 0) && (charAt(i) == ' '); i --);
        return realString.substr(0, i + 1);
			}

			// valueOf: not implemented

			bool isEmpty() { return length() == 0; }

			String repeat(const unsigned int times) {
				String result;
				for (unsigned int i = 0; i < times; i ++)
					result += realString;
				return result;
			}

			std::string toStdString() { return realString; }

	};

	std::ostream& operator<<(std::ostream& out, String& str) { out << str.realString; }

	class MathConstructor {

		public:

			static const double E = 2.718281828459045;
			static const double LN2 = 0.6931471805599453;
			static const double LN10 = 2.302585092994046;
			static const double LOG2E = 1.4426950408889634;
			static const double LOG10E = 0.4342944819032518;
			static const double PI = 3.141592653589793;
			static const double SQRT1_2 = 0.7071067811865476;
			static const double SQRT2 = 1.4142135623730951;

			// TODO: use cmath
			// http://www.cplusplus.com/reference/cmath/

			// TODO: abs

			// TODO: acos
			// TODO: asin
			// TODO: atan
			// TODO: atan2

			// TODO: ceil

			// TODO: sin, cos, tan

			// TODO: exp

			// TODO: floor

			// TODO: log

			// TODO: max
			// TODO: min

			// TODO: pow

			// TODO: random

			// TODO: round

			// TODO: sqrt

	};

	MathConstructor Math;

	class ConsoleContructor {

		public:

			// TODO
			void log();
			void info();
			void warn();
			void error();

			void assert(bool condition) { if (!condition) error("Assertion failed"); }
			void assert(bool condition, const String& msg) { if (!condition) error("Assertion failed: " + msg); }

	};

	ConsoleContructor console;

}

#endif
