#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Base{
	protected:
		string value;
		int base;
	public:
		void set(string s, int b){
			value=s;
			base=b;
		};
		virtual void name(){
			cout<< "BaseName" <<endl ;
		}
		virtual int transferToDecimal(){}   //5-1
		void app(){
			cout<< "APP"<<endl;
		}
};
class Binary: public Base{
	public:
		void name(){
			cout<<"Binary"<<endl;
		}
		int transferToDecimal(){
			int decimal=0,p=0;
			for(int i=value.size()-1;i>=0;i--){
				decimal+=(value[i]-'0')*pow(base,p);
				p++;
			}
			return decimal;
		}
};
class Octal:public Base{
	private:
		string value;
		int vase;
	public:
		void name(){
			cout<<"Octal"<<endl;
		}
		int transferToDecimal(){
			int decimal=0,p=0;
			for(int i=value.size()-1;i>=0;i--){
				decimal+=(value[i]-'0')*pow(base,p);
				p++;
			}
			return decimal;
		}	
		Octal(){
			value="744";
			base=8;
		}
		void app(){
			cout<<"Unix Command"<<endl;
		}
};

class Hexadecimal:public Base{
	public:
		void name(){
			cout<<"Hexadecimal"<<endl;
		}
		int transferToDecimal(){
			int decimal=0,p=0;
			for(int i=value.size()-1;i>=0;i--){
				if(value[i]>='A' && value[i]<='E'){
					decimal+=(value[i]-'A'+10)*pow(base,p);   //5-2
				}
				else{
					decimal+=(value[i]-'0')*pow(base,p);
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
	Binary binary;
	Octal octal;
	Hexadecimal hexadecimal;
	
	Binary *ptr_base1=&binary;
	Octal *ptr_base2=&octal;
	Base *ptr_base3=&hexadecimal;
	
	ptr_base1->set("0111101",2);
	cout<<ptr_base2->transferToDecimal()<<endl;
	ptr_base2->name();
	ptr_base2->app();
	ptr_base3->set("A9C",16);
	cout<<ptr_base3->transferToDecimal()<<endl;
	ptr_base3->name();
	ptr_base3->app();
	
	return 0;
}

