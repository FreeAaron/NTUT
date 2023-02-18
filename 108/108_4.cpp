#include<iostream>
using namespace std;

class N{
    public:
        N():np(new int[5]){}  //问题4-1：动态分配内存
        ~N(){
            delete[] np;  //问题4-2：内存释放
        }
    private:
        int *np;
};

class NChild:public N{
    public:
        NChild():N(),ncp(new int[1000]){}  //动态分配内存
        ~NChild(){
            delete[] ncp;  //内存释放
        }
    private:
        int *ncp;    
};

class Fibonacci : public N{
    public:
        Fibonacci(int n){
            p= new int[n];  //动态分配内存
            setFibonacci(n);
        }
        ~Fibonacci(){ delete []p;}  //内存释放
        int sumFibonacci(int n){
            int sum=0;
            for(int i=0;i<n;i++)
                sum+=p[i];
            return sum;
        }
        void incrementFibonacci(int n){
            for(int i=0;i<n;i++){
                p[i]+=n;
                cout<<p[i]<<endl;
            }
        }
    private:
        int *dp;
        int *p;
        
        void setFibonacci(int n){
            if(n>2){
                p[0]=1;
                p[1]=1;
                for(int i=2;i<n;i++){
                    p[i]=p[i-1]+p[i-2];
                    cout<<p[i]<<endl;
                }
            }
        }
};

int main(){ 
    for(int i=0;i<100;i++){
        N *p=new NChild;  //动态分配内存
        delete p;  //内存释放
    }

    Fibonacci f(5);
    cout << f.sumFibonacci(5) << endl;  //问题4-4：输出斐波那契数列前五项的和
    f.incrementFibonacci(2);
    cout << f.sumFibonacci(5)<<endl;  //问题4-5：输出斐波那契数列前兩项加二  前五項的和

    return 0;
}
