#include<iostream>
#include<string>
#include<cmath>

using namespace std;

// 基底類別 Base
class Base{
protected:
    string value;  // 值
    int base;      // 進位制
public:
    // 設定值和進位制
    void set(string s, int b){
        value = s;
        base = b;
    };
    // 虛擬函式 name，顯示基底類別名稱
    //virtual void name(){
    void name(){
        cout << "BaseName" << endl;
    }
    // 虛擬函式 transferToDecimal，將值轉換成十進位並回傳
    virtual int transferToDecimal()=0;   //5-1
    //  virtual int transferToDecimal(){}   //5-1
    // 函式 app，顯示 APP
    void app(){
        cout << "APP" << endl;
    }
};

// 衍生類別 Binary
class Binary: public Base{
public:
    // 函式 name，顯示 Binary
    void name(){
        cout << "Binary" << endl;
    }
    // 函式 transferToDecimal，將二進位值轉換成十進位並回傳
    int transferToDecimal(){
        int decimal = 0, p = 0;
        for(int i=value.size()-1;i>=0;i--){
            decimal += (value[i]-'0')*pow(base,p);
            p++;
        }
        return decimal;
    }
};

// 衍生類別 Octal
class Octal:public Base{
private:
    string value;  // 值
    int vase;      // 進位制
public:
    // 函式 name，顯示 Octal
    void name(){
        cout << "Octal" << endl;
    }
    // 函式 transferToDecimal，將八進位值轉換成十進位並回傳
    int transferToDecimal(){
        int decimal = 0, p = 0;
        for(int i=value.size()-1;i>=0;i--){
            decimal += (value[i]-'0')*pow(base,p);
            p++;
        }
        return decimal;
    }   
    // 建構子，預設值為 744（八進位）和 8（進位制）
    Octal(){
        value = "744";
        base = 8;
    }
    // 函式 app，顯示 Unix Command
    void app(){
        cout << "Unix Command" << endl;
    }
};

// 衍生類別 Hexadecimal
class Hexadecimal:public Base{
public:
    // 函式 name，顯示 Hexadecimal
    void name(){
        cout << "Hexadecimal" << endl;
    }
    // 函式 transferToDecimal，將十六進位值轉換成十進位並回傳
    int transferToDecimal(){
        int decimal = 0, p = 0;
        for(int i=value.size()-1;i>=0;i--){
            if(value[i]>='A' && value[i]<='E'){
                decimal += (value[i]-'A'+10)*pow(base,p);  //5-2
            }
            else{
                decimal += (value[i]-'0')*pow(base,p);
				}
				p++;
			}
			return decimal;
		}
		void app(){
			cout<<"MAC Address"<<endl;
		}
};

int main(){
// 創建 Binary、Octal、Hexadecimal 三個對象
Binary binary;
Octal octal;
Hexadecimal hexadecimal;

// 創建指向 Base 類型的指針 ptr_base1，讓其指向 binary 對象
Binary *ptr_base1 = &binary;
// 創建指向 Octal 類型的指針 ptr_base2，讓其指向 octal 對象
Octal *ptr_base2 = &octal;
// 創建指向 Base 類型的指針 ptr_base3，讓其指向 hexadecimal 對象
Base *ptr_base3 = &hexadecimal;

// 設置 binary 對象的 value 為 "0111101"，base 為 2
ptr_base1->set("0111101", 2);
// 輸出 octal 對象轉換為十進制的結果
cout << ptr_base2->transferToDecimal() << endl;  //5-3
// 輸出 octal 對象的名字
ptr_base2->name();                              //5-4
// 輸出 octal 對象的 app
ptr_base2->app();                              //5-5
// 設置 hexadecimal 對象的 value 為 "A9C"，base 為 16
ptr_base3->set("A9C", 16);                              
// 輸出 hexadecimal 對象轉換為十進制的結果
cout << ptr_base3->transferToDecimal() << endl;                              //5-6
// 輸出 hexadecimal 對象的名字
ptr_base3->name();                              //5-7
// 輸出 hexadecimal 對象的 app
ptr_base3->app();                              //5-8

return 0;

}
