#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "intal.h"


static void merge(char** arr, int left, int middle, int right);
static void merge_sort(char** arr, int left, int right);
static char* leading_zero(char* a);
static int min(int a, int b);

static int min(int a, int b)
{
	return (a > b ? b : a);
}

static char* leading_zero(char* a)
{
	int count = 0;
	while(a[count] == '0' && a[count] != '\0')
		count++;
	int length = strlen(a);
	for(int i = 0; i < length; i++)
		a[i] = a[count + i];
	return a;
} 

char* intal_add(const char* intal1, const char* intal2)
{
	char *big, *small;
	if(intal_compare(intal1, intal2) > 0)
	{
		big = intal1;
		small = intal2;
	}	
	else
	{
		big = intal2;
		small = intal1;
	}

	int l1 = strlen(small);
	int l2 = strlen(big);
	int offs = l2 - l1;
	int carry = 0;
	int length = l2 + 2;
	int i, k;
	char* answer = (char*)malloc(sizeof(char) * length);
	for(i = 0; i < length - 1; i++)
		answer[i] = '0';
	--length;
	answer[length] = '\0';

	for(i = l1 - 1, k = length - 1; i >= 0; i--, k--)
	{
		int sum = (small[i] - '0') + (big[i + offs] - '0') + carry;
		answer[k] = sum % 10 + '0';
		carry = sum / 10;
	}

	for(i = l2 - l1 - 1; i >= 0; i--, k--)
	{
		int sum = (big[i] - '0') + carry;
		answer[k] = sum % 10 + '0';
		carry = sum / 10;
	}

	if(carry != 0)
		answer[k] = carry + '0';

	answer = leading_zero(answer);
	return answer;
}

char* intal_diff(const char* intal1, const char* intal2)
{
	int l1 = strlen(intal1);
	int l2 = strlen(intal2);
	char *big, *small;
	int l, s, length;
	if(l1 > l2)
	{
		length = l = l1; s = l2;
		big = intal1; small = intal2;
	}

	else if(l1 < l2)
	{
		length = l = l2; s = l1;
		big = intal2; small = intal1;
	}

	else
	{
		length = l = s = l1;
		if(strcmp(intal1, intal2) > 0)
		{
			big = intal1; small = intal2;
		}

		else if(strcmp(intal1, intal2) < 0)
		{
			big = intal2; small = intal1;
		}
		else if(strcmp(intal1, intal2) == 0)
		{
			char* temp = (char*)malloc(sizeof(char) * 2);
			temp[0] = '0'; temp[1] = '\0';
			return temp;
		}
	}

	int i, offs = l - s;

	char* answer = (char*)malloc(sizeof(char) * (length + 1));
	answer[length] = '\0';
	for(i = 0; i < length; i++)
		answer[i] = '0';
	length--;
	int carry = 0, diff = 0;
	for(i = s - 1; i >=0; i--, length--)
	{
		diff = (big[i + offs] - '0') - (small[i] - '0') - carry;
		if(diff < 0)
		{
			diff += 10;
			carry = 1;
		}	
		else
			carry = 0;
		answer[length] = diff + '0';
	}

	for(i = l - s - 1; i >= 0; i--, length--)
	{
		diff = (big[i] - '0') - carry;
		if(diff < 0)
		{
			diff += 10;
			carry = 1;
		}
		else
			carry = 0;
		answer[length] = diff + '0';
	}

	answer = leading_zero(answer);
	return answer;
}

char* intal_multiply(const char* intal1, const char* intal2)
{
	int l1 = strlen(intal1);
	int l2 = strlen(intal2);
	
	char* product = (char*)malloc(sizeof(char) * 2);
	product[0] = '0'; product[1] = '\0';
	if((intal_compare(intal1, product) == 0) || (intal_compare(intal1, product) == 0))
		return product;
	if(!l1 || !l2)
	    return product;

  int i, j, k;
  
  int length = l1 + l2;
  free(product);
  product = (char*)malloc(sizeof(char) * (length + 1));
  product[length] = '\0';

  for(i = 0; i < length; i++)
    product[i] = '0';
  
  int offs = 0, carry = 0;
  
  for(i = l2 - 1; i >= 0; i--)
  {
    for(j = l1 - 1, k = 0; j >= 0 && length - 1 - k - offs >= 0; j--, k++)
    {
      int sum = (intal2[i] - '0') * (intal1[j] - '0') + (product[length - 1- k - offs] - '0') + carry;
      product[length - 1 - k - offs] = sum % 10 + '0';
      carry = sum / 10;
    }

    if(carry > 0)
      product[length - 1 - k - offs] = (product[length - 1 - k - offs] - '0') + carry + '0';
    offs++;
    carry = 0;
  }
  product = leading_zero(product);
  return product;
}

int intal_compare(const char* intal1, const char* intal2)
{
	if(strlen(intal1) > strlen(intal2)) 
		return 1;
	if(strlen(intal1) < strlen(intal2)) 
		return -1;
	int comparision = strcmp(intal1, intal2);
	if(comparision == 0) 
		return 0;
	return comparision > 0 ? 1 : -1;
}

char* intal_pow(const char* intal1, unsigned int n)
{
	char* zero = (char*)malloc(sizeof(char) * 2);
	zero[0] = '0'; zero[1] = '\0';

	if(intal_compare(intal1, zero) == 0)
		return zero;
	zero[0] = '1';

	if(n == 0)
		return zero;
	free(zero);
	if(n == 1)
	{
		char *result = intal1;
		return result;
	}
	else if(n % 2 == 0)
		return intal_multiply(intal_pow(intal1, n / 2), intal_pow(intal1, n / 2));
	else
		return intal_multiply(intal_multiply(intal_pow(intal1, n / 2), intal_pow(intal1, n / 2)), intal1);
}

char* intal_mod(const char* intal1, const char* intal2)
{
	if(!intal_compare(intal1, "0") || !intal_compare(intal2, "0"))
	{
		char *zero = (char*)malloc(sizeof(char) * 2);
		zero[0] = '0'; zero[1] = '\0';
		return zero;
	}	
		
	
	int l = strlen(intal1), l2 = strlen(intal2);
	if((l == 1) && (l2 == 1))
	{
		char* mod = intal_diff(intal1, intal2);
		return mod;
	}

	int length = l - l2;
	if(length == 0)
		length++;

	char *temp = (char*)malloc(sizeof(char) * (length + 1));
	char *q = (char*)malloc(sizeof(char) * (length + 1));
	
	int i = 0;
	do
	{
		temp[i] = '0';
		q[i] = intal1[l - length + i];
		i++;
	}while(i <= length);

	temp[0] = '1'; temp[length] = '\0';

	char* prod = intal_multiply(intal2, q);
	
	for( ; intal_compare(prod, intal1) > 0; q = intal_diff(q, temp), prod = intal_multiply(intal2, q));

	for(; intal_compare(temp, "0") >= 0; prod = intal_multiply(intal2, q))
	{
		int comparision = intal_compare(prod, intal1);
		q = comparision < 0 ? intal_add(q, temp) : intal_diff(q, temp);
		length = comparision < 0 ? length : length - 1;
		temp[length] = comparision < 0 ? temp[length] : '\0';
	}

	char* ans = intal_diff(prod, intal1);
	free(temp); free(q);
	return ans;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
	if(!intal_compare(intal1, "0") && !intal_compare(intal1, "0"))
	{
		char *zero = (char*)malloc(sizeof(char) * 2);
		zero[0] = '0'; zero[1] = '\0';
		return zero;
	}
	if(!intal_compare(intal1, "0"))
	{
		char *result = intal2;
		return result;
	}
	if(!intal_compare(intal2, "0"))
	{
		char *result = intal1;
		return result;
	}
	if(!intal_compare(intal1, intal2))
	{
		char *result = intal1;
		return result;
	}
	if(intal_compare(intal1, intal2) > 0)
		return intal_gcd(intal2, intal_mod(intal1, intal2));
	if(intal_compare(intal1, intal2) < 0)
		return intal_gcd(intal1, intal_mod(intal2, intal1));
}

char* intal_fibonacci(unsigned int n)
{
	char a[1001] = "0";
	char b[1001] = "1";
	char *sum;
	for(int i = 2; i <= n; i++)
	{
		sum = intal_add(a, b);
		strcpy(a, b);
		strcpy(b, sum);
	}
	return sum;
}

char* intal_factorial(unsigned int n)
{
	char* inc = (char*)malloc(sizeof(char) * 2);
	inc[0] = '1'; inc[1] = '\0';

	char* factorial = inc;
	char* increment = inc;
	for(int i = 1; i < n; i++)
	{
		increment = intal_add(increment, inc);
		factorial = intal_multiply(factorial, increment);
	}
	return factorial;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
	if(k > n - k)
		k = n - k;
	char *C[k + 1];

	char* temp = (char*)malloc(sizeof(char) * 2);
	temp[0] = '0'; temp[1] = '\0';
	
	for(int i = 0; i <= k; i++)
		C[i] = temp;

	temp[0] = '1';
	C[0] = temp;

	int i, j;
	for(i = 1; i < n; i++)
		for(j = min(i, k); j > 0; j--)
			C[j] = intal_add(C[j], C[j - 1]);

	char *result = (char*)malloc(sizeof(char) * (strlen(C[k]) + 1));
	strcpy(result, C[k]);
	free(temp);
	return result;
}

int intal_max(char **arr, int n)
{
	int index = 0;
	for(int i = 1; i < n; i++)
		if(intal_compare(arr[i], arr[index]) > 0)
			index = i;
	return index;
}

int intal_min(char **arr, int n)
{
	int index = 0;
	for(int i = 1; i < n; i++)
		if(intal_compare(arr[i], arr[index]) < 0)
			index = i;
	return index;
}

int intal_search(char **arr, int n, const char* key)
{
	for(int i = 0; i < n; i++)
		if(!intal_compare(arr[i], key))
			return i;
	return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
	int low = 0, high = n;
	int mid, index = -1;
	for(mid = (low + high) / 2; low <= high; mid = (low + high) / 2)
	{
		if(intal_compare(arr[mid], key) < 0)
			low = mid + 1;
		if(intal_compare(arr[mid], key) > 0)
			high = mid - 1;
		if (intal_compare(arr[mid], key) == 0)
		{
			index = mid;
			high = mid - 1;
		}
	}
	return -1;
}

static void merge(char** arr, int left, int middle, int right)
{
	int i, j, k;
	int left_size = middle - left + 1;
	int right_size = right - middle;

	char *Left[left_size], *Right[right_size];

	for(i = 0; i < left_size; i++)
		Left[i] = arr[left + i];
	for(i = 0; i < right_size; i++)
		Right[i] = arr[middle + 1 + i];

	i = 0; j = 0; k = left;
	while(i < left_size && j < right_size)
	{
		if(intal_compare(Left[i], Right[j]) <= 0)
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while(i < left_size)
	{
		arr[k] = Left[i];
		k++; i++;
	}

	while(i < right_size)
	{
		arr[k] = Right[j];
		k++; j++;
	}
}

static void merge_sort(char** arr, int left, int right)
{
	if(left < right)
	{
		int middle = (left + right)/2;
		merge_sort(arr, left , middle);
		merge_sort(arr, middle + 1 , right);

		merge(arr, left, middle, right);
	}
}

void intal_sort(char **arr, int n)
{
	merge_sort(arr, 0, n - 1);
}

char* coin_row_problem(char **arr, int n)
{
	if(n == 0)
	{
		char* temp = (char*)malloc(sizeof(char) * 2);
		temp[0] = '0'; temp[1] = '\0';
		return temp;
	}

	char *sum0 = (char*)malloc(sizeof(char) * 1001);
	char *sum1 = (char*)malloc(sizeof(char) * 1001);
	char *sum2 = (char*)malloc(sizeof(char) * 1001);

	strcpy(sum0, "0");
	strcpy(sum1, arr[0]);

	for(int i = 2; i <= n; i++)
	{
		char *sum = intal_add(arr[i - 1], sum0);
		if(intal_compare(sum, sum1) > 0)
			strcpy(sum2, sum);
		else
			strcpy(sum2, sum1);
		strcpy(sum0, sum1);
		strcpy(sum1, sum2);
	}
	free(sum0);
	free(sum2);
	return sum1;
}