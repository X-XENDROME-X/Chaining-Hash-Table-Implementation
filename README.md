# Chaining Hash Table Implementation

This repository contains a C++ implementation of a chaining hash table, along with a custom hash function. The hash table is designed to categorize and store string tokens loaded from input files. The project includes sample input cases, testing scripts, and a Makefile for easy compilation and testing.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Input Format](#input-format)
- [Building and Testing](#building-and-testing)
- [Contributing](#contributing)
- [License](#license)

## Introduction

A chaining hash table is a type of hash table where each bucket (or slot) contains a linked list of elements. It's used to efficiently store and retrieve key-value pairs. In this project, we implement a chaining hash table to categorize and store string tokens based on a custom hash function.

## Features

- Implementation of a chaining hash table in C++.
- Custom hash function designed to sort strings into corresponding slots in the hash table.
- Sample input files and test cases provided.
- Makefile for easy compilation and testing.
- Ability to create custom input files and test the robustness of the hash function design.

## Usage

To use this implementation, follow these steps:

1. Clone the repository to your local machine.
2. Compile the code using the provided Makefile.
3. Run the program with a specified input file:
```bash
./encoder < testfilename.txt
```
4. Analyze the output to see the contents of the hash table, slot lengths, and standard deviation.

## Input Format

The input file format should adhere to the following rules:

1. The first line specifies the number of hash table slots (k), where 5 <= k <= 100.
2. The following lines consist of one token per line, in upper and lower case letters.
3. There are no duplicate tokens in a single input file.
4. The number of tokens (N) does not exceed 500.

Example (testfilename.txt):  
**`5`**  
**`Amazon Boeing apple Applebee abandon banana elephant boring barbaric`**  

## Building and Testing

To build and test the implementation, follow these steps:

1. Use the provided Makefile to compile the code.
2. Run the program with sample input files or create custom input files for testing:
```bash
./encoder < testfilename.txt
```
3. Analyze the output to ensure the hash function performs efficiently and the hash table functions correctly.

## License

This project is licensed under the [MIT License](LICENSE).

  


