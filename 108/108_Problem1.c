#include<stdio.h>
#include<string.h>
typedef enum{dog,cat,lion=4,tiger,monkey,hippo,giraffe
}animal;
void f1(int a,int b){
	printf("%d\n",!a&&b);//a and b�H�޿�B��var>0:Ture <0:False,!:Ture<->False 
	printf("%d\n",~a&b);//a and b�H�줸�B�ⰵand 
}
void f2(){
	animal a=cat+hippo;
	animal b=cat;	
	animal c=hippo;	
	printf("%d\n",a);
		printf("%d\n",b);
				printf("%d\n",c);
}
void f3(int num){
	int k;
	k=(num>1?(num<=10?100:200):300);
	printf("%d\n",++k);
}
void f4(int num){
	float f=1.0;
	for(int i=1; i<=num;i++)
		f*=i;
	printf("%.2f\n",f); 
}
void f5(char *s1,char *s2){
	char str1[80]="",str2[]="a";
	int i=0;
	while(*(s1+i)<=*(s2+i)&&strlen(str1)<80){
		i++;
		strncat(str1,str2,1);
	}
	printf("%s\n",str1);
}
void f6(int x[],int size){
	int sum=0;
	for(int i=0;i<size;i++){
		switch((animal) x[i]+3){
			case dog:sum+=3;
				break;
			case cat:sum+=3;
				break;
			case lion:sum+=4;
			case tiger:sum+=4;
				break;
			default: sum+=1;
				break;
		}
	}
	printf("%d\n",sum);
} 
void f7(int a[],int p1,int*p2){
	a[0]=5;
	p1=*p2+1;
	*p2=1;
}
int f8(int n){
	if(n<2)
		return n;
	return f8(n-1)+f8(n-2);
}
int main(){
	int a[]={1,2,3,4};
	char s[2][12]={"problem","programmer"};
//	f1(16,8);
	f2();
//	f3(5);
//	f4(5);
//	f5(s[0],s[1]);
//	f6(a,4);
//	f7(a,a[1],&a[2]);
//	printf("%d\n",a[0]);
//	printf("%d\n",a[1]);
	printf("%d\n",f8(6));
	return 0;
}

