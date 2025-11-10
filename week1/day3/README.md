# 🧩 Recursion & Complexity

This README introduces two fundamental concepts in computer science:
1. **Recursion** — a problem-solving technique where a function calls itself.
2. **Algorithmic Complexity** — a way to measure how efficiently an algorithm runs.

---

## 🔁 1. Recursion

### 🧠 Definition
Recursion is a programming technique in which a function **calls itself** to solve smaller versions of the same problem until it reaches a **base case**.

Each recursive call reduces the problem’s size, and the base case stops the recursion.

### 💡 Example: Factorial
```cpp
int factorial(int n) {
    if (n == 0)               // Base case
        return 1;
    return n * factorial(n-1); // Recursive call
}

For factorial(4):

factorial(4) = 4 * factorial(3)
factorial(3) = 3 * factorial(2)
factorial(2) = 2 * factorial(1)
factorial(1) = 1 * factorial(0)
factorial(0) = 1 (Base case)


Key Components

Base Case → stops recursion (prevents infinite loop)

Recursive Case → reduces the problem toward the base case

⚠️ Common Pitfalls

Missing or incorrect base case → infinite recursion / stack overflow

Recomputing the same values → can cause exponential time complexity


⏱️ 2. Algorithmic Complexity
🧭 What It Means

Complexity describes how the time or memory usage of an algorithm grows as the input size increases.

Two main types:

Time Complexity → how fast an algorithm runs

Space Complexity → how much memory it uses

🕒 Time Complexity Notation (Big O)

| Notation   | Name          | Example                           |
| ---------- | ------------- | --------------------------------- |
| O(1)       | Constant time | Accessing an array element        |
| O(log n)   | Logarithmic   | Binary Search                     |
| O(n)       | Linear        | Loop through array                |
| O(n log n) | Linearithmic  | Merge Sort, Quick Sort (avg case) |
| O(n²)      | Quadratic     | Nested loops                      |
| O(2ⁿ)      | Exponential   | Recursive Fibonacci               |
