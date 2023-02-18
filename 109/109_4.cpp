#include<iostream>
using namespace std;

class Figure {
public:
    Figure() {} // 建構函式
    virtual void draw() {} // 虛擬函數
};

class Line : public Figure { // 繼承自 Figure 類別
public:
    Line() {} // 建構函式
    void draw(); // 實作 Figure 的虛擬函數 draw()
};

void Line::draw() { // Line 的 draw() 函數實作
    cout << "畫一條線..." << endl;
}

class Circle : public Figure { // 繼承自 Figure 類別
public:
    Circle() {} // 建構函式
    void draw(); // 實作 Figure 的虛擬函數 draw()
};

void Circle::draw() { // Circle 的 draw() 函數實作
    cout << "畫一個圓形..." << endl;
}

int main() {
    Figure* p1 = new Line(); // 創建一個指向 Line 物件的 Figure 指標
    Figure* p2 = new Circle(); // 創建一個指向 Circle 物件的 Figure 指標
    p1->draw(); // 調用 Figure 的虛擬函數 draw()
    p2->draw(); // 調用 Figure 的虛擬函數 draw()

    return 0;
}


// 此程式碼使用了多型和虛擬函數的概念，建立了 Figure 抽象類別，並讓 Line 和 Circle 兩個類別繼承自 Figure，同時實作了 Figure 的虛擬函數 draw()，在 main() 函數中，創建了指向 Line 和 Circle 物件的 Figure 指標，並調用了 draw() 函數，此時根據指標指向的實際物件類型，會調用到對應類別的 draw() 函數，這就是多型的體現。
