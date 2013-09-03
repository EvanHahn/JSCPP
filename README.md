JSCPP
=====

<img src="http://evanhahn.com/wp-content/uploads/2013/09/jscpp-150x150.png" align="right">

I'm a JavaScript programmer. I *hate* C++. Sadly, I have to use it for school. I come from a world of "performance be damned" and high-level APIs.

[I wanted to like C++](http://programmers.stackexchange.com/questions/196369/how-can-i-learn-to-like-c), I really did.

Because I'm not allowed to use code I didn't write, I couldn't use things like [Boost](http://www.boost.org/) -- I had to roll my own.

After three years of dealing with C++, I was fed up. Before returning for my final semesters, I decided to write a library that made C++ a little more familiar.

Goals
-----

- replicate significant parts of the JavaScript standard library in C++ for familiarity
- ignore regexes and functional stuff (no `forEach`, for example) -- we're not trying to turn C++ into JavaScript
- performance is not important
- aimed at small projects for school, not for your big C++ project
- don't overload `==` to be like `==` in JavaScript; make it like `===`
- each component should be independent -- Array.join shouldn't return my string, it should return an std::string

Pull requests are welcome!

Supported stuff
---------------

### Array

from JavaScript

- `concat(Array)` (only takes an array, unlike JavaScript)
- `indexOf(item)`
- `join([string])`
- `lastIndexOf(item)`
- `length()` (method, not a property)
- `pop()`
- `push(item)` (only takes one argument, unlike JavaScript)
- `reverse()` (doesn't return the array, unlike JavaScript)
- `shift()`
- `slice()` (*TODO*)
- `sort()` (*TODO*)
- `splice(index, howMany)` (always takes two arguments, unlike JavaScript)
- `toString()`
- `unshift(item)` (only takes one argument, unlike JavaScript)

new stuff

- `isEmpty()` (alias of `length() == 0`)
- `contains(item)` (alias of `indexOf(item) != -1`)
- `first()` (get the first element)
- `last()` (get the last element)
- `size()` (alias of `length`)
- `toStdVector()` (returns a std::vector)

### String

from JavaScript

- operators: `==`, `+`, `+=`, `[]` (not for assignment), `!`, `<`, `>`, `<=`, `=>`, `~`
- `charAt(index)`
- `charCodeAt(index)`
- `concat(string)`
- `contains(string)` (strings only)
- `endsWith(string)` (strings only)
- `indexOf(string)` (strings only)
- `lastIndexOf(string)` (strings only)
- `length()` (method, not a property)
- `replace(original, new)` (strings only. Try `replaceAll` for global replace)
- `slice(beginSlice, [endSlice])`
- `split` (*TODO*)
- `startsWith(string)`
- `substr` (*TODO*)
- `substring` (*TODO*)
- `toLowerCase()`
- `toUpperCase()`
- `trim()`
- `trimLeft()`
- `trimRight()`

new stuff

- `isEmpty()` (shorthand for `length() == 0`)
- `repeat(amount)` (repeat a string)
- `replaceAll(original, new)` (same API as `replace` but global)
- `size()` (alias of `length`)
- `toStdString()` (convert to std::string)

### Math

from JavaScript

- `E`, `LN2`, `LN10`, `LOG2E`, `LOG10E`, `PI`, `SQRT1_2`, `SQRT2`
- `abs(value)`
- `acos(value)`, `asin(value)`, `atan(value)`, `atan2(x, y)`
- `ceil(value)`, `floor(value)`
- `sin(value)`, `cos(value)`, `tan(value)`
- `exp(value)`
- `round(value)`
- `log(value)`
- `max(a, b)`, `min(a, b)` (only takes 2 arguments; not 100% compliant)
- `pow(base, exponent)`
- `random()`
- `sqrt(value)`

new stuff

- `sign(value)` (returns 0, -1, or 1)

### Utils

from JavaScript

- `parseInt(string)` (alias of `atoi`; not 100% compliant with JavaScript)

Usage
-----

For usage, see `test.cpp`. It aims to serve as example and test.
