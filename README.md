JSCPP
=====

I'm a JavaScript programmer. I *hate* C++. Sadly, I have to use it for school. I come from a world of "performance be damned" and high-level APIs.

[I wanted to like C++](http://programmers.stackexchange.com/questions/196369/how-can-i-learn-to-like-c), I really did.

After three years of dealing with C++, I was fed up. Before returning for my final semesters, I decided to write a library that made C++ a little more familiar. **This is C++ for the JavaScript programmer.**

Because I'm not allowed to use code I didn't write, I couldn't use things like [Boost](http://www.boost.org/) -- I had to roll my own.

Goals
-----

- replicate significant parts of the JavaScript standard library in C++ for familiarity
- ignore regexes and functional stuff (no `forEach`, for example)
- performance is not important
- aimed at small projects for school, not for your big C++ project
- don't overload `==` to be like `==` in JavaScript; make it like `===`

Pull requests are welcome!

Supported stuff
---------------

### Array

- from JavaScript
  - `concat(Array)` (only takes an array, unlike JavaScript)
  - `indexOf(item)`
  - `join([string])`
  - `lastIndexOf(item)`
  - `length()` (method, not a property)
  - `pop()`
  - `push(item)` (only takes one argument, unlike JavaScript)
  - `reverse()`
  - `shift()`
  - `slice()`
  - `sort`
  - `splice(index, howMany)` (always takes two arguments, unlike JavaScript)
  - `toString()`
  - `unshift(item)` (only takes one argument, unlike JavaScript)
- new stuff
  - `contains(item)`
  - `isEmpty()`
  - `size()` (alias of `length`)

### String

- from JavaScript
  - `charAt(index)`
  - `charCodeAt(index)`
  - `concat(string)`
  - `contains(string)` (strings only
  - `endsWith(string)` (strings only)
  - `indexOf(string)` (strings only)
  - `lastIndexOf(string)` (strings only)
  - `length()` (method, not a property)
  - `replace(original, new)` (strings only. Try `replaceAll` for global replace)
  - `slice`
  - `split` (returns a JSCPP::Array)
  - `startsWith(string)`
  - `substr`
  - `substring`
  - `toLowerCase()`
  - `toUpperCase()`
  - `trim()`
  - `trimLeft()`
  - `trimRight()`
- new stuff
  - `isEmpty()` (shorthand for `length() == 0`)
  - `repeat(amount)` (repeat a string)
  - `replaceAll(original, new)` (same API as `replace` but global)
  - `size()` (alias of `length`)
  - `toStdString()` (convert to std::string)

### Number

- from JavaScript
  - `toString`
- new stuff
  - `toInt`
  - `toUnsignedInt`
  - `toFloat`
  - `toDouble`

### Math

- from JavaScript
  - `E`, `LN2`, `LN10`, `LOG2E`, `LOG10E`, `PI`, `SQRT1_2`, `SQRT2`
  - `abs`
  - `acos`, `asin`, `atan`, `atan2`
  - `ceil`, `floor`
  - `sin`, `cos`, `tan`
  - `exp`
  - `round`
  - `log`
  - `max`, `min`
  - `pow`
  - `random`
  - `sqrt`

Usage
-----

For usage, see `test.cpp`. It aims to serve as example and test.
