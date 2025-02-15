# Homogeneous-System-Solver

📌 Overview

The Homogeneous System Solver is a computational program designed to solve matrix equations of the form Ax = 0. It automates matrix operations such as determinant calculation, cofactor extraction, adjoint computation, and inverse matrix determination. This tool is beneficial for students, engineers, and mathematicians working with linear algebra and matrix equations.

🔥 Features

✅ Solves Homogeneous Systems: Computes solutions for Ax = 0.

✅ Matrix Operations: Implements determinant, cofactor, adjoint, and inverse calculations.

✅ Random Matrix Generation: Automatically generates matrix elements for demonstration.

✅ Matrix Multiplication: Computes X = A⁻¹B when applicable.

✅ Error Handling: Ensures matrix validity for inverse computation.

🎯 Use Cases

Mathematics & Engineering: Solve linear algebra problems efficiently.

Physics & Economics: Model systems using matrix equations.

Computer Science: Implement foundational algorithms in linear algebra.

🚀 Installation & Usage

Prerequisites

Ensure you have the following installed:

C++ Compiler (GCC, Clang, or MSVC)

Clone the Repository


git clone https://github.com/fadysameeh/Homogeneous-System-Solver.git
cd Homogeneous-System-Solver

Compile and Run the Program

Using g++ (Linux/macOS)

g++ main.cpp -o matrix_solver
./matrix_solver

Using MSVC (Windows)

cl main.cpp /Fe:matrix_solver.exe
matrix_solver.exe

Example Output
Generated Matrix A:
[ 2  3 ]
[ 1  4 ]

Determinant: 5
Adjoint Matrix:
[ 4 -3 ]
[-1  2 ]

Inverse Matrix:
[  0.8 -0.6 ]
[ -0.2  0.4 ]

Solution X = A⁻¹B:
[ 1.2 ]
[ 0.8 ]
