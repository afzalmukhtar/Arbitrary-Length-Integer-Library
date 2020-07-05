#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "intal.h"

#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#define SUM(a, b) ((a) + (b))
#define SUB(a, b) ((a) - (b))

static char* remove_zeros(char* intal);
static void swap(char** a, char** b);
static void heapify(char** arr, int n, int i);
static void heap_sort(char** arr, int n);


static char* remove_zeros(char* intal)
{
	int c = 0;
	while(intal[c] == '0' && intal[c] != '\0')
		c++;
	int l = strlen(intal);
	for(int i = 0; i < l; i++)
		intal[i] = intal[c + i];
	return intal;
}

static void swap(char** a, char** b)
{
	char **temp = *a;
	*a = *b;
	*b = temp;
}

char* intal_add(const char* intal1, const char* intal2)
{
	char *larger, *smaller;
	int compare = intal_compare(intal1, intal2);
	larger = compare > 0 ? intal1 : intal2;
	smaller = compare > 0 ? intal2 : intal1;

	int s = strlen(smaller), l = strlen(larger);
	int shift = l - s, carry = 0, len = l + 2;
	int i, k;

	char* final_sum = (char*)malloc(sizeof(char) * len);
	for(i = 0; i < len - 1; i++)
		final_sum[i] = '0';
	final_sum[--len] = '\0';

	for(i = s - 1, k = len - 1; i >= 0; i--, k--)
	{
		int sum = SUM(SUM((smaller[i] - '0'), (larger[i + shift] - '0')), carry);
		final_sum[k] = SUM((sum % 10), '0');
		carry = sum / 10;
	}

	for(i = l - s - 1; i >= 0; i--, k--)
	{
		int sum = SUM((larger[i] - '0'), carry);
		final_sum[k] = SUM((sum % 10), '0');
		carry = sum / 10;
	}

	if(carry)
		final_sum[k] = SUM((carry), '0');

	if(final_sum[0] == '0')
		final_sum = remove_zeros(final_sum);
	return final_sum;
}

char* intal_diff(const char* intal1, const char* intal2)
{
	char *larger, *smaller;
	int l, s, len;
	int compare = intal_compare(intal1, intal2);

	if(compare == 0)
	{
		char* temp = (char*)malloc(sizeof(char) * 2);
		temp[0] = '0'; temp[1] = '\0';
		return temp;
	}

	larger = compare > 0 ? intal1 : intal2;
	smaller = compare > 0 ? intal2 : intal1;
	len = l = compare > 0 ? strlen(intal1) : strlen(intal2);
	s = compare > 0 ? strlen(intal2) : strlen(intal1);

	int i, k, shift = l - s;

	char* final_diff = (char*)malloc(sizeof(char) * (len + 1));
	final_diff[len] = '\0';
	for(i = 0; i < len; i++)
		final_diff[i] = '0';

	int carry = 0, diff = 0;
	for(i = s - 1, k = len - 1; i >=0; i--, k--)
	{
		diff = SUB(SUB((larger[i + shift] - '0'), (smaller[i] - '0')), carry);
		carry = diff < 0 ? 1 : 0;
		diff = diff < 0 ? diff + 10 : diff;
		final_diff[k] = SUM(diff, '0');
	}

	for(i = l - s - 1; i >= 0; i--, k--)
	{
		diff = SUB((larger[i] - '0'), carry);
		carry = diff < 0 ? 1 : 0;
		diff = diff < 0 ? diff + 10 : diff;
		final_diff[k] = SUM(diff, '0');
	}

	if(final_diff[0] == '0')
		final_diff = remove_zeros(final_diff);
	return final_diff;
}

char* intal_multiply(const char* intal1, const char* intal2)
{
	int len1 = strlen(intal1);
	int len2 = strlen(intal2);

	if(!intal_compare(intal1, "0") || !intal_compare(intal2, "0") || !len1 || !len2)
	{
		char* temp = (char*)malloc(sizeof(char) * 2);
	    temp[0] = '0'; temp[1] = '\0';
	    return temp;
	}

  int i, j, k;
  
  int len = len1 + len2;
  char* final_product = (char*)malloc(sizeof(char) * (len + 1));
  final_product[len--] = '\0';
  for(i = 0; i <= len; i++)
    final_product[i] = '0';
  
  int shift = 0;
  
  for(i = len2 - 1; i >= 0; i--)
  {
    int num1 = SUB(intal2[i], '0');
    int carry = 0;
    for(j = len1 - 1, k = 0; j >= 0 && len - k - shift >= 0; j--, k++)
    {
      int num2 = SUB(intal1[j], '0');
      int index = len - k - shift;
      int sum = num1 * num2 + SUM((final_product[index] - '0'), carry);
      final_product[index] = SUM((sum % 10), '0');
      carry = sum / 10;
    }
    if(carry)
      final_product[len - k - shift] = SUM(SUM((final_product[len - k - shift] - '0'), carry), '0');
    shift++;
  }

  if(final_product[0] == '0')
  	final_product = remove_zeros(final_product);
  return final_product;
}

int intal_compare(const char* intal1, const char* intal2)
{
	int len1 = strlen(intal1), len2 = strlen(intal2);
	if(len1 > len2) return 1;
	if(len1 < len2) return -1;
	int compare = strcmp(intal1, intal2);
	if(compare == 0) return 0;
	return compare > 0 ? 1 : -1;
}

char* intal_pow(const char* intal1, unsigned int n)
{
	char* zero = (char*)malloc(sizeof(char) * 2);
	zero[0] = '0'; zero[1] = '\0';
	if(intal_compare(intal1, zero) == 0)
		return zero;
	
	char* one = malloc(sizeof(char) * 2);
	one[0] = '1'; one[1] = '\0';
	char* result = one;
	if(n == 0)
		return one;
	if(n == 1)
	{
		result = intal1;
		return result;
	}

	for(int i = 0; i < n/2; i++)
		result = intal_multiply(result, intal1);
	result = intal_multiply(result, result);

	if(n % 2 != 0)
		result = intal_multiply(result, intal1);
	free(zero); free(one);
	return result;
}

char* intal_mod(const char* intal1, const char* intal2)
{
	char *zero = (char*)malloc(sizeof(char) * 2);
	zero[0] = '0'; zero[1] = '\0';
	if(!intal_compare(intal1, "0") || !intal_compare(intal2, "0"))
		return zero;
	
	int len = strlen(intal1);
	int len2 = strlen(intal2);
	if((len == 1) && (len2 == 1))
	{
		char* modulo = intal_diff(intal1, intal2);
		return modulo;
	}

	int size = len - len2;

	size = size == 0 ? size + 1: size;

	char *reduce = (char*)malloc(sizeof(char) * (size + 1));
	char *quotient = (char*)malloc(sizeof(char) * (size + 1));
	
	for(int i = 0; i <= size; i++)
	{
		reduce[i] = '0';
		quotient[i] = intal1[len - size + i];
	}

	reduce[0] = '1'; reduce[size] = '\0';

	char* product = intal_multiply(intal2, quotient);
	while(intal_compare(product, intal1) > 0)
	{
		quotient = intal_diff(quotient, reduce);
		product = intal_multiply(intal2, quotient);
	}

	while(intal_compare(reduce, zero) >= 0)
	{
		int comparision = intal_compare(product, intal1);
		if(comparision < 0)
			quotient = intal_add(quotient, reduce);

		else
		{
			quotient = intal_diff(quotient, reduce);
			size--;
			reduce[size] = '\0';
		}
		product = intal_multiply(intal2, quotient);
	}
	char* result = intal_diff(product, intal1);
	free(reduce); free(quotient);
	free(zero);
	return result;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
	char *zero = (char*)malloc(sizeof(char) * 2);
	zero[0] = '0'; zero[1] = '\0';
	
	if(!intal_compare(intal1,zero) && !intal_compare(intal1,zero))
		return zero;

	if(!intal_compare(intal1, zero))
	{
		char *result = intal2;
		return result;
	}
	if(!intal_compare(intal2, zero))
	{
		char *result = intal1;
		return result;
	}

	char gcd[3][1001];
	int compare = intal_compare(intal1, intal2);
	compare > 0 ? strcpy(gcd[0], intal1) : strcpy(gcd[0], intal2);
	compare > 0 ? strcpy(gcd[1], intal2) : strcpy(gcd[1], intal1);
	
	while( (intal_compare(gcd[1], zero) > 0) && intal_compare(gcd[0], gcd[1]))
	{
		strcpy(gcd[2], intal_mod(gcd[0], gcd[1]));
		strcpy(gcd[0], gcd[1]);
		strcpy(gcd[1], gcd[2]);
	}

	zero = malloc(sizeof(char) * (strlen(gcd[0]) + 1));
	strcpy(zero, gcd[0]);
	return zero;
}

char* intal_fibonacci(unsigned int n)
{
	char *fib0 = "0", *fib1 = "1";
	char *sum;
	for(int i = 2; i <= n; i++)
	{
		sum = intal_add(fib0, fib1);
		fib0 = fib1;
		fib1 = sum;
	}
	return sum;
}

char* intal_factorial(unsigned int n)
{
	char* one = (char*)malloc(sizeof(char) * 2);
	one[0] = '1'; one[1] = '\0';

	char* fact = one;
	char* increment = one;
	for(int i = 1; i < n; i++)
	{
		increment = intal_add(increment, one);
		fact = intal_multiply(fact, increment);
	}
	return fact;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
	char* one = (char*)malloc(sizeof(char) * 2);
	one[0] = '1'; one[1] = '\0';
	
	char* zero = (char*)malloc(sizeof(char) * 2);
	zero[0] = '0'; zero[1] = '\0';

	if(k > n - k)
		k = n - k;
	if(n == k || k == 0)
		return one;
	char C[k + 1][1001];
	
	for(int i = 1; i <= k; i++)
		strcpy(C[i], zero);

	strcpy(C[0], one);
	int i, j;
	for(i = 1; i <= n; i++)
		for(j = MIN(i, k); j > 0; j--)
			strcpy(C[j], intal_add(C[j], C[j - 1]));

	char *result = (char*)malloc(sizeof(char) * (strlen(C[k]) + 1));
	strcpy(result, C[k]);
	free(one); free(zero);
	return result;
}

int intal_max(char **arr, int n)
{
	int max = n - 1;
	for(int i = 0; i < n/2; i++)
	{
		max = intal_compare(arr[i], arr[max]) > 0 ? i : max;
		max = intal_compare(arr[i + n/2], arr[max]) > 0 ? i + n/2 : max;
	}
	return max;
}

int intal_min(char **arr, int n)
{
	int min = n - 1;
	for(int i = 0; i < n/2; i++)
	{
		min = intal_compare(arr[i], arr[min]) < 0 ? i : min;
		min = intal_compare(arr[i + n/2], arr[min]) < 0 ? i + n/2 : min;
	}
	return min;
}

int intal_search(char **arr, int n, const char* key)
{
	for(int i = 0; i < n; i++)
		if(intal_compare(key, arr[i]) == 0)
			return i;
	return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
	int l = 0, h = n;
	int index = -1;
	while(l <= h)
	{
		int mid = (l + h) / 2;
		l = intal_compare(arr[mid], key) < 0 ? mid + 1 : l; 
		h = intal_compare(arr[mid], key) > 0 ? mid - 1 : h;
		if (intal_compare(arr[mid], key) == 0)
		{
			index = mid;
			h = mid - 1;
		}
	}
	return index;
}

static void heapify(char** arr, int n, int i)
{
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	largest = (left < n) && (intal_compare(arr[left], arr[largest]) == 1) ? left : largest;
	largest = (right < n) && (intal_compare(arr[right], arr[largest]) == 1) ? right : largest;

	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

static void heap_sort(char** arr, int n)
{
	int i;
	for(i = n/2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for(i = n - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void intal_sort(char **arr, int n)
{
	heap_sort(arr, n);
}

char* coin_row_problem(char **arr, int n)
{
	if(n == 0)
	{
		char* zero = (char*)malloc(sizeof(char) * 2);
		zero[0] = '0'; zero[1] = '\0';
		return zero;
	}

	char *temp0 = (char*)malloc(sizeof(char) * 1001);
	char *temp1 = (char*)malloc(sizeof(char) * 1001);
	char *temp2 = (char*)malloc(sizeof(char) * 1001);

	strcpy(temp0, "0");
	strcpy(temp1, arr[0]);

	for(int i = 2; i <= n; i++)
	{

		char *temp = intal_add(arr[i - 1], temp0);
		intal_compare(temp, temp1) > 0 ? strcpy(temp2, temp) : strcpy(temp2, temp1);
		strcpy(temp0, temp1);
		strcpy(temp1, temp2);
	}

	free(temp0);
	free(temp2);

	return temp1;
}