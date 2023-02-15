#include<iostream>
using namespace std;
class Figure{
	public:
		Figure(){}
		virtual void draw(){}
};

class Line:public Figure{
	public:
		Line(){}
		void draw();
};

void Line::draw(){
	cout<<"draw like a line..."<<endl;
}

class Circle:public Figure{
	public:
		Circle(){}
		void draw();
};

void Circle::draw(){
	cout<<"draw like a circle...." << endl;
}
int main(){
	Figure *p1=new Line();
	Figure *p2=new Circle();
	p1->draw();
	p2->draw();
	
	return 0;
}

