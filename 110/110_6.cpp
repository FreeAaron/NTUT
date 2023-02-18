#include <iostream>
#include <string>
#define PI 3
using namespace std;

class MathVector {      //補上空格與更正名稱為MathVector
private:
double *_content;
int _size;

public:
MathVector () { }

MathVector (double* input, int size = 0) {      //  補上input的參數型別為double*
    _content= new double[size];
    _size = size;
    for (int i= 0; i < _size; i++) {
        _content[i] = input[i];
    }
}

MathVector (const MathVector &input) {      // Problem 6-1: 補上拷貝建構子，並在參數前加上const
    _content = new double[input._size];
    _size = input._size;
    for (int i= 0; i < _size; i++) {
        _content[i] = input._content[i];
    }
}

~MathVector() {
    if (_content != NULL) {
        delete [] _content;         // Problem 6-2
    }
}

MathVector & operator= (const MathVector &input) { // Problem 6-3: 補上指定運算子，並在參數前加上const
    if (_content != NULL) {
        delete [] _content;
    }
    _size = input._size;
    _content = new double[_size];           // Problem 6-4
    for(int i = 0; i < _size; i++) {
        _content[i] = input._content[i];
    }
    return *this; // 補上回傳值// Problem 6-5
}

double & component(int index) const {
    return _content[index - 1];
}
};

class Shape {
protected:
MathVector _center;

public:
Shape(MathVector center) : _center(center) { } // Problem 6-5: 修正MathVector的名稱
virtual double perimeter() const = 0;           // Problem 6-6
virtual ~Shape() { }
};

class Circle : public Shape { // Problem 6-6: 加上繼承關係
private:
double _radius;

public:
Circle(double radius, MathVector center) : Shape(center) { // Problem 6-7: 加上初始化清單，並在MathVector的名稱前加上類別名稱
_radius = radius;
}
~Circle() override { } // Problem 6-8: 加上override關鍵字

double perimeter() const override { // Problem 6-9: 加上override關鍵字
    return 2 * _radius * PI;
}
};

int main() {
double y[2] = {1, 90};
MathVector output = MathVector(y, 2);
cout << output.component(2) << endl; // 90

Shape* output2 = new Circle(5, output); // Problem 6-10: 將Circle物件放入Shape型別的指標中
cout << output2->perimeter() << endl; // 30
delete output2;

return 0;
}

// 在C++中，const關鍵字可以用來表示某個值或變量是常量，也就是它的值不會被改變。在程式設計中，使用const可以增加代碼的可讀性和可維護性。

// 在上述程式碼中，const修飾的成員函數double & component(int index) const表示這個函數不會修改成員變數的值。這樣的函數可以在const對象或指向const對象的指針中調用，並且也可以讓編譯器進行更好的優化。例如，如果沒有使用const，則編譯器可能會認為這個函數可能會修改對象的狀態，從而導致一些意想不到的行為。

// 因此，使用const關鍵字可以增加程式碼的安全性和可靠性，讓程式設計更加優雅。