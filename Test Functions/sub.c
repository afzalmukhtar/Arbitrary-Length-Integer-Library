#include<stdlib.h>
#include<string.h>
int main() {
  char intal1[] =      "543215432154321543215432154321";
  char intal2[] = "543215432154321543215432154321";
  int len1 = strlen(intal1);
  int len2 = strlen(intal2);
  char *larger, *smaller;
  int l, s, len;
  if(len1 > len2)
  {
    len = l = len1; s = len2;
    larger = intal1;
    smaller = intal2;
  }
  else if(len1 < len2)
  {
    len = l = len2; s = len1;
    larger = intal2;
    smaller = intal1;
  }
  else
  {
    len = l = s = len1;
    if(strcmp(intal1, intal2) > 0)
    {
      larger = intal1;
      smaller = intal2;
    }
    else if(strcmp(intal1, intal2) < 0)
    {
      larger = intal2;
      smaller = intal1;
    }
    else if(strcmp(intal1, intal2) == 0)
    {
      char* temp = malloc(sizeof(char) * 2);
      temp[0] = '0';
      temp[1] = '\0';
      return temp;
    }
  }
  int i, j, k;

  char* final_diff = malloc(sizeof(char) * (len + 1));
  final_diff[len] = '\0';
  for(i = 0; i < len; i++)
    final_diff[i] = '0';
    
  int carry = 0, diff = 0;
  
  for(i = s - 1, k = len - 1; i >=0; i--, k--)
  {
      diff = (larger[i] - '0') - (smaller[i] - '0') - carry;
      carry = diff < 0 ? 1 : 0;
      diff = diff < 0 ? diff + 10 : diff;
      final_diff[k] = diff + '0';
  }
  
  for(i = l - s - 1; i >= 0; i--, k--)
  {
    diff = (larger[i] - '0') - carry;
    carry = diff < 0 ? 1 : 0;
    diff = diff < 0 ? diff + 10 : diff;
    final_diff[k] = diff + '0';
  }
  
  if(final_diff[0] == '0')
  {
    int count = 0;
    for(i = 0; i < len; i++)
    {
      if(final_diff[i] == '0')
      {
        count++; continue;
      }
      final_diff[i - count] = final_diff[i];
    }
  }
  
  printf("%s\n", final_diff);
  
  return 0;
}