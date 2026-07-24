# N-number-of-fibonacci
solution to the problem of finding n number of fibonacci using own classes
# BigInt и вычисление чисел Фибоначчи на C++

Project Structure
List (my std::vector)

Template-based singly linked list.

Implements copy constructor and assignment operator (Rule of Three).

LongInt

Class for storing large numbers.

Uses List to store digits as decimal places.

add()

Function for adding two LongInt numbers, working digit by digit.

Handles carries, just like "column" addition.

print_fib()

Demonstration function that computes Fibonacci numbers.

Example Output
The program sequentially outputs Fibonacci numbers from 0 to 100, showcasing the big integer arithmetic in action.

text
Fib(0) = 0
Fib(1) = 1
...
Fib(100) = 354224848179261915075
