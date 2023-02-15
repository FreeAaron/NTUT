#include <iostream>
using namespace std;

// 建立 Number 類別
class Number{
    public:
        // 建構子，初始設定 real 和 pImaginary 的值
        Number(int x,int y):real(x){
            pImaginary=new int(y);
        }

        // 複製建構子，用來複製物件時使用
        Number(Number &cn){
            int n=(*cn.pImaginary)+1;
            real =cn.real+1;
            pImaginary =new int(n);
        }

        // 取得數字，加總 real 和 pImaginary 的值
        int getNumber(){
            return real+(*pImaginary);
        }

        // 增加 pImaginary 的值
        void addImaginary(int n){
            pImaginary += n;
        }

        // 設定 pImaginary 的新值，並刪除原先的空間
        void newImaginary(int n){
            delete pImaginary;
            pImaginary=new int[n];
            setImaginary(n);
        }

        // 取得 real 的值
        int getReal(){
            return real;
        }

        // 取得 pImaginary 中指定位置的值
        int getImaginary(int i){
            return pImaginary[i];
        }

        // 計算 pImaginary 的值，使它等於 real
        void compute(){
            pImaginary=&real;
        }

        // 計算新的 Number 物件，此方法為第一種
        void compute(Number *cn){
            cn=new Number(3,4);
        }

        // 計算新的 Number 物件，此方法為第二種
        void compute(Number &cn){
            cn=Number(5,6);
        }

        // 計算新的 Number 物件，此方法為第三種
        Number compute(Number cn , int n){
            cn.real+=n;
            return cn;
        }

        // 刪除 pImaginary 的空間
        void deleteImaginary(){
            delete pImaginary;
        }

    private:
        // 設定 pImaginary 的值，為一串由小到大的奇數數列
        void setImaginary(int n){
            for(int i=0;i<n;i++)
                pImaginary[i]=i*2+1;
        }
        int real;
        int *pImaginary;
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
