#include<iostream>
using namespace std;

class Number{
	private:
		int a;
	public:
		Number():a(7){}
		int getA(){return a;}
		int get(){return a;}
		int *getAaddress() {return &a;}
		void setA(int v){a=v;}
};
class Complex : public Number{
	private:
		int *b;
	public:
		Complex() {
			setA(4) ;
			b = new int(5);
		}
		
		Complex(int x, int y) {
			setA(x);
			b = new int(y);
		}
		
		int *getB() {return b;}
		int get() {return b[0];}
		//void setB() {b = getAaddress();cout<<b<<'\n'; }
		void setB() {b = getAaddress(); }
		void setB(int v) {b[0] = v;}
		
		int getsum() {
			return getA() + *b;
		}
		
		Complex *foo(){
			return new Complex(6, 7);
		}
		
		void foo(Complex &c) {
			c = Complex(8, 9);
		}
		
		Complex foo(Complex *c1, Complex&c2)
		{
			return Complex(c1->getA()+c2.getA(),*c1->getB() + *c2.getB());
		}
};

int main(){
	cout <<"\n====Anser====\n";
	Complex c1(1, 2);
	cout << c1.getsum() << endl;
	/* Problem 3-1 */
	
	Complex c2(3, 4);
	c2.setB() ;
	cout << c2.getsum() << endl;
	/* Problem 3-2 */
	
	Complex c3;
	cout << c3.getsum() << endl;
	/* Problem 3-3 */
	
	Complex *p;
	p = c3.foo(); //p改寫為new complex(6,7)
	cout << p->getsum() << endl;
	/* Problem 3-4 */
	
	Complex c4;
	c3.foo(c4);
	cout << c4.getsum() << endl;
	/* Problem 3-5 */
	
	Complex c5; 
	c5 = c5.foo(&c3, c4);
	cout << c5.getsum() << endl;
	/* Problem 3-6 */
	
	Number c6;
	c6.setA(5) ;
	cout << c6.get() << endl;
	/* Problem 3-7 */
	
	Complex c7;
	c7.setB(6) ;
	cout << c7.get() << endl;
	/* Problem 3-8 */
	
	Number *q = new Number();
	cout << q->get() << endl;
	/* Problem 3-9 */
	
	Number *r = new Complex(8, 9);
	cout << r->get() << endl;
	/* Problem 3-10 */
	
	return 0;
}

