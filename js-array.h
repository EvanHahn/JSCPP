#ifndef JSCPP_ARRAY_H__
#define JSCPP_ARRAY_H__

#include <vector>
#include <string>
#include <sstream>
#include <ostream>

namespace JSCPP {

	template <class T>
	class Array {

		private:
			std::vector<T> realVector;
			T at(const unsigned int i) {
				if (i < size())
					return realVector[i];
				else
					return false;
			}

		public:

			T operator[](const unsigned int i) { return at(i); }
			template <T> friend std::ostream& operator<<(std::ostream&, Array<T>&);

			unsigned int length() { return realVector.size(); }
			unsigned int size()   { return length(); }

			int indexOf(T el) {
				for (unsigned int i = 0; i < size(); i ++) {
					if (at(i) == el)
						return i;
				}
				return -1;
			}

			int lastIndexOf(T el) {
				for (int i = size() - 1; i >= 0; i --) {
					if (at(i) == el)
						return i;
				}
				return -1;
			}

			void push(T el) { realVector.push_back(el); }
			void unshift(T el) { realVector.insert(realVector.begin(), el); }

			T pop() {
				T result = realVector.back();
				realVector.pop_back();
				return result;
			}

			T shift() {
				T result = realVector.front();
				realVector.erase(realVector.begin());
				return result;
			}

			void reverse() {
				unsigned int count = size();
				T temp;
				unsigned int otherIndex;
				for (unsigned int i = 0; i < (count / 2); i ++) {
					otherIndex = count - i - 1;
					temp = realVector[i];
					realVector[i] = realVector[otherIndex];
					realVector[otherIndex] = temp;
				}
			}

			std::string join(std::string sep) {
				std::stringstream ss;
				for (unsigned int i = 0; i < size(); i ++) {
					if (i != 0)
						ss << sep;
					ss << at(i);
				}
				return ss.str();
			}
			std::string join() { return join(","); }
			std::string toString() { return join(); }

			// valueOf: not implemented

			T& first() { return at(0); }
			T& last() { return at(size() - 1); };

			bool contains(T el) { return indexOf(el) != -1; }

			bool isEmpty() { return length() == 0; }

			std::vector<T> toStdVector() { return realVector; }

	};

	template <class T> std::ostream& operator<<(std::ostream& out, Array<T>& arr) {
		out << '[' << arr.join(", ") << ']';
		return out;
	}

};

#endif
