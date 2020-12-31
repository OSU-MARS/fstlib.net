### Overview
A .NET 5.0 wrapper providing access to the [fstlib](https://github.com/fstpackage/fstlib) data serialization library for reading
and writing .fst files.

Managed APIs are not provided for `FstDb`, `FstTableProxy`, and `FstStreamer` as these classes are not currently implemented in 
fstlib.

### Dependencies
Because a binary distribution of [fstlib](https://github.com/fstpackage/fstlib) 0.1.1 (April 2019) is not available, this repo
contains a copy of the fstlib sources which are built as a dependency for fstlib.net.dll and linked statically.

Development environment is Visual Studio 2019 Community Edition.