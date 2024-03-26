# C++ compiler calculator
This is a very simple c++ calculator that uses compiler to calculate all expressions. The idea is very simple, instead of writing the logic of a calculator, use the already correctly written logic of a compiler calculator. I'm pretty sure someone has already created such a calculator, but I came up with the idea myself because I was too lazy to implement the logic of the calculator.
## calculator capabilities
You can use all operations that you can use in c++. Also you can use all cmath functions such as sin, cos, tan and others.
## how it works
The compiler calculator works very simply. After receiving the expression you entered, it creates calculator.cpp the file then writes some code into it. This code will write to history.txt the expression that will be calculated by the compiler. Before writing an expression to calculator.cpp file, it needs to get some transformation to work properly. After calculator.cpp file has been compiled successfully, it execute. While calculator.cpp file is running, the main file checks for updates in history.txt file, and when it finds a new number, it outputs it to the console as a expression answer.
## addition
The calculator only works on Windows and is very slow compared to other c++ calculators, it's all because how it works
