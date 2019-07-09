# Project 4

Complex number class
Design a class in C++, Java, and Python that represents complex numbers and supports important operations such as addition, subtraction,\
multiplication and division. For the C++ and Python versions you will need to implement the following functions for each operation:

- op: Complex × Complex → Complex
- op: Complex × double → Complex
- op: double × Complex → Complex

Where op is one of +, -, *, or /. In addition, you will need to overload the stream insertion operator << to print objects of this type.
A constructor must be defined as well as overloading the assignment operator to allow for implicit conversion from doubles to Complex.\
Any other methods you deem appropriate should also be included. The more complete your class the better.

The Java version will not have as many methods because Java does not allow for operator overloading or friend functions. Again, the more\
complete your Java class the better. Override the toString() method.

The Python version you should also include functions for converting from complexes to strings.

The required files for this project are: a complex.h file that contains the declaration of the complex class, a complex_cc file that\
contains the implementations of method and functions declared in the complex class, a main_cc that instantiates complex numbers and\
tests all methods and functions, a Complex.java file that is the Java implementation, and a Main.java file that instantiates and tests\
all methods of the Complex class. The python files required are a complex_py file.

Here is some example [code](https://web.njit.edu/~kapleau/teach/current/cs280/prj4.txt)