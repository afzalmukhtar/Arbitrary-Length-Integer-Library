#include<stdlib.h>
#include<string.h>
int main() {
  char intal1[] = "5432154321543215432154321";
  char intal2[] = "1237691297123";
  
  int len1 = strlen(intal1);
  int len2 = strlen(intal2);
  
  if(!len1 || !len2)
  {
    char* temp = malloc(sizeof(char) * 2);
    temp[0] = '0'; temp[1] = '\0';
    return temp;
  }

  int i, j, k, l;
  
  int len = len1 + len2;
  char* final_product = malloc(sizeof(char) * (len + 1));
  final_product[len--] = '\0';
  for(i = 0; i <= len; i++)
    final_product[i] = '0';
  int shift = 0;
  for(i = len2 - 1; i >= 0; i--)
  {
    int num1 = intal2[i] - '0';
    int carry = 0;
    for(j = len1 - 1, k = 0; j >= 0 && len - k - shift >= 0; j--, k++)
    {
      int num2 = intal1[j] - '0';
      int index = len - k - shift;
      int sum = num1 * num2 + (final_product[index] - '0') + carry;
      final_product[index] = sum % 10 + '0';
      carry = sum / 10;
    }
    if(carry)
      final_product[len - k - shift] = (final_product[len - k - shift] - '0') + carry + '0';
    shift++;
  }
  
  printf("%s\n", final_product);
  return 0;
}