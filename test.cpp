#include "js.h"

#include <assert.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main() {

	// ARRAY
	// =====

	{

		using JSCPP::Array;

		{ // Creating arrays
		  // ---------------

			Array<int> empty;
			assert(empty.isEmpty());
			assert(empty.length() == 0);
			assert(!empty[0]);
			assert(!empty[2]);

		}

	}

	// STRING
	// ======

	{

		using JSCPP::String;

		{ // Creating strings
			// ----------------

			String empty;
			assert(empty == "");
			assert(empty.length() == 0);
			assert(empty.isEmpty());

			String name = "Ron";
			assert(name == "Ron");
			assert(name.length() == 3);
			assert(name.size() == 3);
			assert(!name.isEmpty());

			std::string stdnombre = "Ronaldo";
			String nombre = stdnombre;
			assert(nombre == "Ronaldo");

			char c = 'X';
			String letter = c;
			assert(letter == "X");
			assert(letter == 'X');

		}

		{ // Converting to std::string
			// -------------------------

			String name = "Champ Kind";
			std::string stdname = name.toStdString();

		}

		{ // Combining strings
			// -----------------

			String firstName, lastName, name;
			firstName = "Brian";
			lastName = "Fantana";
			name = firstName + ' ' + lastName;

			assert(name == "Brian Fantana");
			assert(firstName + lastName == "BrianFantana");
			assert(firstName + " " + lastName == "Brian Fantana");

			name = "Brian ";
			name += "Fantana";
			assert(name == "Brian Fantana");

			name = "Brian ";
			assert(name.concat("Fantana") == "Brian Fantana");
			name = "Brian ";
			assert(name.concat(lastName) == "Brian Fantana");

		}

		{ // String access
		  // -------------

			String name = "Veronica Corningstone";
			assert(name[1] == 'e');
			assert(name[0] == 'V');
			assert(name.charAt(7) == 'a');
			assert(name.charAt(4) == 'n');
			assert(name.charCodeAt(0) == 86);
			assert(name.charCodeAt(3) == 111);

			String misspelled = "Dan Siego";
			name[0] = 'S';
			name[4] = 'D';
			assert(misspelled == "San Diego");

		}

		{ // Find things within a string
			// ---------------------------

			String name = "Channel 4 News Team";

			assert(name.contains("Channel"));
			assert(name.contains(" "));
			assert(name.contains('4'));
			assert(!name.contains("San Diego"));

			assert(name.indexOf("Channel") == 0);
			assert(name.indexOf("4") == 8);
			assert(name.indexOf("San Diego") == -1);

			assert(name.lastIndexOf("e") == 16);
			assert(name.lastIndexOf("Channel") == 0);
			assert(name.lastIndexOf("San Diego") == -1);

			assert(name.startsWith("Channel"));
			assert(!name.startsWith("News"));
			assert(name.endsWith("Team"));
			assert(!name.endsWith("Channel"));

		}

		{ // Trimming
			// --------

			assert(String("Hello world").trim() == "Hello world");
			assert(String("Hello world").trimLeft() == "Hello world");
			assert(String("Hello world").trimRight() == "Hello world");

			assert(String("   Hello world").trim() == "Hello world");
			assert(String("   Hello world").trimLeft() == "Hello world");
			assert(String("   Hello world").trimRight() == "   Hello world");

			assert(String("Hello world   ").trim() == "Hello world");
			assert(String("Hello world   ").trimLeft() == "Hello world   ");
			assert(String("Hello world   ").trimRight() == "Hello world");

			assert(String("   Hello world  ").trim() == "Hello world");
			assert(String("   Hello world  ").trimLeft() == "Hello world  ");
			assert(String("   Hello world  ").trimRight() == "   Hello world");

			assert(String("").trim() == "");
			assert(String("     ").trim() == "");

		}

		{ // Upper and lowercase
			// -------------------

			String hi = "Good evening, San Diego. I'm Ron Burgundy?";
			assert(hi.toLowerCase() == "good evening, san diego. i'm ron burgundy?");
			assert(hi.toUpperCase() == "GOOD EVENING, SAN DIEGO. I'M RON BURGUNDY?");

			String empty;
			assert(empty.toLowerCase() == empty.toUpperCase());

		}

		{ // Using some more obscure operators
			// ---------------------------------

			String h = "hello";
			String w = "world";

			assert(h < w);
			assert(!(h > w));
			assert(h <= w);
			assert(!(h >= w));
			assert(h <= h);
			assert(h >= h);
			assert(!(h < h));
			assert(!(h > h));

			assert((!h) == false);
			assert(!!h);

			assert((~h) == -1);

		}

	}

	// MATH
	// =========

	{

		// TODO

	}

	// UTILITIES
	// =========

	{

	}

}
