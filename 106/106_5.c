/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<string.h>

int
test08 ()
{
  int i = 0;
  return i++;
}

int
test07 ()
{
  int grade = 4, ans = 0;
  switch (grade)
    {
    case 4:
      ans += 4;
    case 3:
      ans += 3;
    case 2:
      ans += 2;
    case 1:
      ans += 1;
    default:
      ans = 0;
      printf ("%d\n", ans );
    }

  return ans > 0 ? ans : 0;
}


int
test06 ()
{
  int v = 0xFF;
  printf ("%d\n", v);
  v &= 1;
  printf ("%d\n", v);
  v |= 0;
  printf ("%d\n", v);
  v <<= 3;
  printf ("%d\n", v);
  v >>= 1;
  return v;
}


int
test05 ()
{
  int a[] = { 1, 2, 3, 4, 5 };
  int *p, *q;
  p = &a[8];
  q = p - 3;
  p -= 6;
  return p - q;
}

int
test04 ()
{
  char str1[10], str2[10];
  strcpy (str1, "abc");
  strcpy (str2, "abc");
  strcat (str1, strcat (str2, "ghi"));
   printf ("%d\n",strcmp (str1, str2));
  return strcmp (str1, str2);
}

int
test03 (int n)
{
  int rem;
  do
    {
      n /= 10;
      rem = n % 10;
      if (rem != 0)
	break;
    }
  while (n > 0);
  return rem;
}

int
test02 (void)
{
  enum{ CLUBS, DIAMONDS, HEARTS, SPADES } s;
  int i = DIAMONDS;
  s = HEARTS;
  //s++;
  i = i + s + SPADES;
  return i;
}

int
test09 (int n)
{
  int i = 1;
  while (i < n)
    i *= 2;
  return i;
}

int
test10 (int n)
{
  int div;
  if (n <= 1)
    return 0;
  for (div = 2; div * div <= n; div++)
    if (n % div == 0)
      return 0;
  return 1;
}


int
main (void)
{
  // your code goes here
  printf ("%d\n", test08 ());
  printf ("%d\n", test07 ());
  printf ("%d\n", test06 ());
  printf ("%d\n", test05 ());
  printf ("%d\n", test04 ());
  printf ("%d\n", test03 (123));
  printf ("%d\n", test02 ());
  printf ("%d\n", test09 (100));
  printf ("%d\n", test10 (7));
  return 0;
}


