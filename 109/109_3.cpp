#include<iostream>
using namespace std;

class B{
private:
    int a;

public:
    void f();               // 宣告函數 f
    virtual void g();       // 宣告虛擬函數 g
    ~B();                   // 宣告解構函數

    int get(){              // 宣告成員函數 get，用於取得成員變數 a 的值
        return a;
    }

    void set(int v){        // 宣告成員函數 set，用於設置成員變數 a 的值
        a=v; 
    } 
};

B::~B(){                    // 定義解構函數
    cout<<"66"<<endl;
}

void B::f(){                // 定義函數 f
    cout<<"11"<<endl;
} 

void B::g(){                // 定義虛擬函數 g
    cout<<"22"<<endl;
} 

class D : public B{         // 定義派生類別 D，繼承自基礎類別 B
private:
    int b;
public:
    void f();               // 宣告函數 f
    void g();               // 宣告函數 g
    ~D();                   // 宣告解構函數
    D(){                    // 定義構造函數
        set(1);
        b=2;
    }
    int getA(){             // 宣告成員函數 getA，用於取得基礎類別的成員變數 a 的值
        return get();
    }
    int getB(){             // 宣告成員函數 getB，用於取得派生類別的成員變數 b 的值
        return b;
    }
};

D::~D(){                    // 定義解構函數
    cout<<"99"<<endl;   
}

void D::f(){                // 定義函數 f
    cout<<"33"<<endl;   
}

void D::g(){                // 定義函數 g
    cout<<"44"<<endl;   
}

void f(B &p){               // 定義函數 f，傳入一個基礎類別 B 的參考
    p.f();                  // 呼叫 B 的函數 f
}

void g(B &p){               // 定義函數 g，傳入一個基礎類別 B 的參考
    p.g();                  // 呼叫 B 的虛擬函數 g
}

int main(){
    B b;                   // 建立一個基礎類別 B 的物件
    D d;                   // 建立一個派生類別 D 的物件
    // 呼叫物件 b 和物件 d 的函數 f
    b.f();
    d.f();
    // 呼叫函數 f 和函數 g，傳入物件 d 的參考
    f(d);
    g(d);

    // 宣告兩個指標，指向 B 類別和 D 類別的物件
    B *b1, *b2;
    b1= new B;
    b2= new D;
    // 用指標呼叫物件的函數 f 和 g
    b1->f();
    b2->f();
    b1->g();
    b2->g();
    // 釋放記憶體
    delete b1;
    delete b2;

    return 0;
}