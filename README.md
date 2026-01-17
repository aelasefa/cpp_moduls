# C++ Module Projects (CPP00 to CPP09)

This repository contains solutions for the C++ piscine/module exercises from **CPP00** to **CPP09**.  
Each folder contains an exercise focusing on different C++ concepts, from basic syntax and classes to templates and the Standard Template Library (STL).

---

## Table of Contents

- [CPP00 - Hello World & Basics](#cpp00---hello-world--basics)  
- [CPP01 - Classes and Constructors](#cpp01---classes-and-constructors)  
- [CPP02 - More on Classes & Operator Overloading](#cpp02---more-on-classes--operator-overloading)  
- [CPP03 - Inheritance and Polymorphism](#cpp03---inheritance-and-polymorphism)  
- [CPP04 - Abstract Classes & Interfaces](#cpp04---abstract-classes--interfaces)  
- [CPP05 - Operator Overloading Advanced](#cpp05---operator-overloading-advanced)  
- [CPP06 - Type Casting and Conversions](#cpp06---type-casting-and-conversions)  
- [CPP07 - Templates and Iterators](#cpp07---templates-and-iterators)  
- [CPP08 - Standard Template Library (STL)](#cpp08---standard-template-library-stl)  
- [CPP09 - Advanced STL and Performance](#cpp09---advanced-stl-and-performance)  

---

## CPP00 - Hello World & Basics

- Introduction to C++ syntax and compiling simple programs  
- Practice with input/output and basic program structure  
- Example: `main.cpp` prints "Hello World"

---

## CPP01 - Classes and Constructors

- Creating classes, constructors, destructors  
- Understanding encapsulation and member functions  
- Example: `Zombie` class with constructors and announce method

---

## CPP02 - More on Classes & Operator Overloading

- Copy constructors, assignment operators  
- Overloading operators for user-defined classes  
- Example: `Fixed` class demonstrating fixed-point arithmetic

---

## CPP03 - Inheritance and Polymorphism

- Class inheritance, virtual functions  
- Abstract classes and interface design  
- Example: Animal hierarchy with `Dog`, `Cat`, and polymorphic behavior

---

## CPP04 - Abstract Classes & Interfaces

- Pure virtual functions and abstract base classes  
- Implementing interfaces and overriding methods  
- Example: Different `Brain` implementations for animals

---

## CPP05 - Operator Overloading Advanced

- Overloading arithmetic and comparison operators  
- Friend functions and stream operators  
- Example: `Fixed` class with full operator overloading support

---

## CPP06 - Type Casting and Conversions

- Use of `reinterpret_cast`, `static_cast`, and `const_cast`  
- Low-level memory manipulation and pointer conversions  
- Example: Converting raw data buffers safely

---

## CPP07 - Templates and Iterators

- Writing template classes and functions  
- Using iterators with standard containers  
- Example: `Array` template class and generic algorithms

---

## CPP08 - Standard Template Library (STL)

- Mastering STL containers: `vector`, `deque`, `map`, `stack`  
- Using iterators, algorithms, and functors  
- Projects:
  - **Bitcoin Exchange**: Using `map` for date-rate lookup and input validation  
  - **Reverse Polish Notation**: Implement stack-based calculator using `stack`  
  - **MutantStack**: Extending `stack` with iterator support  

---

## CPP09 - Advanced STL and Performance

- Advanced manipulation of STL containers  
- Performance measurement and algorithm optimization  
- Project:
  - **PmergeMe**: Implement sorting using pairs with `vector` and `deque`, measuring time in microseconds  

---

## How to Compile and Run

Each exercise usually contains a single main source file or a set of files. Compile using:

```bash
c++ -Wall -Wextra -Werror -std=c++98 <filename>.cpp -o <executable>

