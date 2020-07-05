#include<stdlib.h>
#include<string.h>
int main() {
  char a[] = "1234512345123451234512345";
  char b[] = "543215432154321543215432154321";
  int l1 = strlen(a);
  int l2 = strlen(b);
  int len = (l1 >= l2 ? l1 : l2);
  len = len + 2;
  
  char* final_sum = malloc(sizeof(char) * (len));
  for(int i = 0; i < len; i++)
    final_sum[i] = '0';
  len--;
  final_sum[len] = '\0';
  
  int sum = 0, carry = 0;
  for(l1--, l2--, len--; l1 >= 0 && l2 >= 0; l1--, l2--, len--)
  {
      sum = a[l1] + b[l2] - '0' - '0';
      final_sum[len] = sum % 10 + carry + '0';
      carry = sum / 10;
  }
  
  for(; l1>= 0; l1--, len--)
    final_sum[len] = a[l1];
  for(; l2 >= 0; l2--, len--)
    final_sum[len] = b[l2];
    
  printf("%s\n", final_sum);
  return 0;
}