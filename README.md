# Arbitrary-Length-Integer-Library
This is my Arbitrary Length Integer Library Project in C
## Introduction
#### 1. What is an intal?
An intal is short for integer of arbitrary length, is an integer library to support the storage and usage of very large integers in C. The integers are stored in form of a 
null terminated string i.e. a null terminated character array, where the integers are converted to their character representative value and stored in this array.


#### 2. How is it different from an integer and integer data types supported by C?
The maximum size of an integer supported by C is 8 bytes, which is unsigned long long. Numbers larger than the limit supported by these data types will cause an overflow and 
there can be loss in data. Floating points donot solve this issue as they also have a set number of bytes for precision and numbers beyond that point are truncated and written in terms 
of powers of 10. This causes a loss in the exact integer values, and gives an approximate float value.
To overcome this limitations, an intal is used. Intals can be used to store numbers larger than the 8-bytes in size. This comes in very useful as the size of the array/string can increase
with increase in the size of the integer. Therefore there will be no loss in data and no overflow will be caused (as long as it does not exhaust all the memory).
___

## Approach on implementation
#### 1. Addition: ```char* intal_add(const char* intal1, const char* intal2)```

Using the basic school level logic, to add the corresponding numbers starting from the one's position and continuining till the end of either number. If one number is smaller than the other number then then the remaining numbers are considered to be added by zeros till it reaches the end. If the sum of two digits gives a number greater than 9, then the digit at ten's place is taken as a carry and the one's digit is used to fill up the space in the final summation array. If there is a carry after the addition of the last digit, then the carry is stored in an extra space before the last digit i.e. the carry now becomes the the first character in the array.

#### 2. Compare: ```int intal_compare(const char* intal1, const char* intal2)```

It is used to compare two intals. It checkes the length of two intals, and returns 1 if intal1 is greater than intal2, -2 if intal2 is greater and 0 if both are equal. If both the intals are of the same length, then it performs a lexicographical character by character comparision and returns 1 if intal1 is larger, -1 if intal2 is larger and 0 if equal. The extra zeros are removed from the final answer.

#### 3. Difference: ```char* intal_diff(const char* intal1, const char* intal2)```

Using the basic school level logic for subtraction, the greater number is reduced by the smaller number. Using the Compare operation, the larger and smaller number is decided, which is then subtracted with the corresponding character positions, starting from the last character(index n - 1) upto the first character(index 0). If the difference of two digits results in a negetive value then to convert them to a positive value, we add it by 10 (4 - 5 + 10 = 9) which gives the same value if we have a carry value from the adjacent character position. When the difference of two digits is negetive, the carry is set to 1, and the carry is subtracted from the next adjacent character index. This process continues till it reaches the very first character in the array. The final result is positive in value and any remaining 0's in the start of the array are removed.

#### 4. Multiply: ```char* intal_multiply(const char* intal1, const char* intal2)```

Multiplication is based on the logic of multiply, shift and add. In this, we calculate partial products by multiplying the LSB of the second number with all the number of the first number. This is the first partial product obtained. Then the next significant bit is multiplied by all the digits of the first number. The second partial product is added to the first partial product by shifting the second partial product by the same number characters as the character position of the current digit i.e. shifting by 1 character to the left everytime a new partial product is calculated. This is carried on till the the last digit of the second number has formed a partial product and added to the sum of the previous partial products.
To save sapce, only one array of size intal1 + intal2 is used to store the partial product, and each product calculated is added to the partial product array as it proceeds the multiplication process.

#### 5. Modulus: ```char* intal_mod(const char* intal1, const char* intal2)```

Modulus is based on a simple division algorithm, where the quotient is estimated at first and then the right quotient is calculated by incrementing and decrementing the values of respective character positions. Based on basic division logic, the estimated quotient is approximately equal to l1 - l2 number of digits of the dividend, where l1 = length of dividend and l2 = length of divisor. 
	The quotient is incremented by 1 at the most significant position of the quotient and compared with the dividend. The product of quotient with the divisor is calculated, and if the product is greater than the quotient, then the the quotient is reduced. If the values goes to negetives, then the increment and decrement then occurs at a lower significant bit. This process continues till the difference of the product and the dividend is less than the divisor. This difference is modulus of the dividend with respect to the divisor.

#### 6. Exponentiation: ```char* intal_pow(const char* intal1, unsigned int n)```

Exponent is calculated by continuously multiplying the number by itself. The number is multiplied with itself for n/2 times, and if n is even then the final answer is the product of the obtained exponent with itself, i.e. if y = (x^n), then final product = (y * y). If n is odd, then the original number is multiplied to the final product to obtained the final result, i.e. y = (x^n) (n is odd), then final product = (y * y * x).

#### 7. Greatest Common Divisor: ```char* intal_gcd(const char* intal1, const char* intal2)```

Greatest Common Divisor is the largest number that is a factor of both th numbers. To find this we use Euclidean algorithm, which is based on the principle that the greatest common divisor of two numbers does not change if the larger number is replaced by its difference with the smaller number. So we subtract the larger number by the smaller number, and then the new answer is subtracted from the smaller number of the previous two numbers. This continues till it reaches the case where both the numbers are same, or when either one number is zero. 
Subtraction is replaced by the modulus operation, which is in essence repeated subtractions till a number is obtained smaller than the minuend. This continues till the base condition is reached. And the final non-zero answer is returned. 
###### NOTE: We assume that the gcd(0, 0) is 0.


#### 8. N-th Fibonacci Number: ```char* intal_fibonacci(unsigned int n)```

Fibonacci Number is one in which each number is the sum of the preceding two numbers. The simplest series will be when the 1st fibonacci number is 0 and the second is 1. Therefore n-th fibonacci number follows the recursive relation:
Fib(n) = Fib(n - 1) + Fib(n - 2), for all n >= 2
where, F(0) = 0 and F(1) = 1.
Using this recursive relation, the fibonacci number is calculated till the it reaches the n-th number.

#### 9. Factorial of N: ```char* intal_factorial(unsigned int n)```

Factorial of N is calculated by multiplying each number from 1 to N. It follows the recursive relation:
Fact(n) = n * Fact(n - 1), where Fact(0) = 1.
We continuously multiply each number starting from n and reducing down till it reaches 0 or 1, and returning the final product as the factorial of n.

#### 10. Binomial Coefficient: ```char* intal_bincoeff(unsigned int n, unsigned int k)```

Binomial Coefficient is also known as combinations and is represented as nCk. The values of the binomial coefficient can be represented in form of Pascal's Triangle, where the sum of two adjacent numbers from the previous row is equal to the Binomial Coefficient of that position, i.e. it follows the recursive relation:
C(n, k) = C(n - 1, k) + C(n - 1, k - 1), where C(n, 0) = C(n , n) = 1.
The relation C(n, k) = C(n, n - k) is used to reduce the number of steps taken to calculate the Binomial Coefficient. 
We one array, and follow the relation that C[k] = C[k] C[k - 1], i.e. the previous value of C[k] and C[k - 1] will hold the valus of the previous row of the Pascal's triangle. The first loop runs for n-times, i.e. the number of rows, where as the second loop runs for the minimum of n and k, which is the column value. This continues till the last loop is completed and the value at C[k] is returned as the result.

#### 11. Maximum: ```int intal_max(char **arr, int n)```

This is based on a modified search algorithm, where the array is divided into two, and the elements on either side of the half array is compared. The larger of the two is compared with the element at the max index. If any element is larger than the element at the max index, the the max index is updated to the larger element's index. When the half of the array is reached, the max index is returned.

#### 12. Minimum: ```int intal_min(char **arr, int n)```

This is based on a modified search algorithm, where the array is divided into two, and the elements on either side of the half array is compared. The smaller of the two is compared with the element at the min index. If any element is smaller than the element at the min index, the the min index is updated to the smaller element's index. When the half of the array is reached, the min index is returned.

#### 13. Search: ```int intal_search(char **arr, int n, const char* key)```

This is based on a simple search algorithm where every element in the array is compared to the key. If the key matches at an index, the index is returned and the search is stopped.

#### 14. Binary Search: ```int intal_binsearch(char **arr, int n, const char* key)```

This search algorithm works on a sorted array. It divides the array into half, and compares the key with the middle value. If the Key is found, it returns the mid index, else if the key is smaller than the middle value, it searching in the left half of the array, else the right half by following the same divide and compare middle value procedure. If the Key isn't present in the array, -1 is returned.

#### 15. Sorting: ```void intal_sort(char **arr, int n)```

Using a Heap Sort to perform the sort operation. A max heap is created using the heap logic where the parent is the larger than its two child elements, where the parent and child are related with the following relations:
parent = i
left child = 2 * i + 1
right child = 2* i + 2
Traversing the entire array and converting it into a heap, by checking if the parent is larger than either of its child, and swaping the larger of the child with the parent if the parent is smaller than any of its children. After a heap is formed, the elements are popped out from the top and stored at the end of the array. This changed array is then heapified except the last index where the popped element is stored. This continues till the last element is popped.
The array so obtained will be sorted in ascending order.

#### 16. Coin Row Problem: ```char* coin_row_problem(char **arr, int n)```

Coin row problem is to find the maximum sum of coins that can be obtained if the adjacent coins aren't picked. Therefore it follows the recursive relation:
F(n) = maximum(C(n) + F(n - 2), F(n - 1)), for n > 1.
Where F(0) = 0 and F(1) = C(0). Where C is the coin array and F is the sum array.
If no coin is given then no Coin will be picked, therefore the sum is 0. If one coin is given then that is the only coin picked. Therefore the sum is equal to the value of that coin. for n > 1, the recursive algorithm is followed till it reaches the value n. The Sum value at n is returned as the answer.

##### Code by: Afzal
