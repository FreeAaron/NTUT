/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Number
{
public:
  Number (int x, int y):real (x)
  {
    pImaginary = new int (y);
  }
  Number (Number & cn)
  {
    int n = (*cn.pImaginary) + 1;
    real = cn.real + 1;
    pImaginary = new int (n);
  }
  int getNumber ()
  {
    return real + (*pImaginary);
  }
  void addImaginary (int n)
  {
    pImaginary += n;
  }
  void newImaginary (int n)
  {
    delete pImaginary;
    pImaginary = new int[n];
    setImaginary (n);
  }
  int getReal ()
  {
    return real;
  }
  int getImaginary (int i)
  {
    return pImaginary[i];
  }
  void compute ()
  {
    pImaginary = &real;
  }
  void compute (Number * cn)
  {
    cn = new Number (3, 4);
  }
  void compute (Number & cn)
  {
    cn = Number (5, 6);
  }
  Number compute (Number cn, int n)
  {
    cn.real += n;
    return cn;
  }
  void deletemaginary ()
  {
    delete pImaginary;
  }

    void setImaginary (int n)
  {
    for (int i = 0; i < n; i++)
      pImaginary[i] = i * 2 + 1;
  }
  int real;
  int *pImaginary;

// private:
//   void setImaginary (int n)
//   {
//     for (int i = 0; i < n; i++)
//       pImaginary[i] = i * 2 + 1;
//   }
//   int real;
//   int *pImaginary;
};

int
main ()
{
  Number cn1 (1, 2);
  cout << cn1.getNumber () << endl;	//Problem 6-1 
  Number cn2 (3, 4);
  cn2.compute ();
  cout << cn2.getNumber () << endl;	//Problem 6-2
  Number cn3 (5, 6);
  cn3.newImaginary (3);
  cout << cn3.getReal () << endl;	//Problem 6-3
  Number cn4 (7, 8);
  cn4.newImaginary (5);
  cout << cn4.getImaginary (3) << endl;	//Problem 6 - 4 
  Number cn5 (9, 10);
  cn5.newImaginary (7);
  cn5.addImaginary (1);
  cout << cn5.getNumber () << endl;	//Problem 6-5
  Number cn6 (11, 12);
  cout << cn6.compute (cn6,1).getNumber () << endl;	//Problem 6-6

  return 0;
}
