#include <stdio.h>
#include <string.h>
int test01(int n){
    if(n<=1)
        return 1;
    else
        return n*test01(n-1);
}

int test02(){
    enum{CLUBS,DIAMONDS,HEARTS,SPADES}s;
    int i=DIAMONDS;
    s=HEARTS;
    ///s++;
    i=i+s+SPADES;
    return i;
}

int test03(int n){
    int rem;
    do{
        n/=10;
        rem=n%10;
        if(rem!=0)
            break;
    }while(n>0);
    return rem;
}

int test04(){
    char str1[10],str2[10];
    strcpy(str1,"abc");
    strcpy(str2,"abc");
    strcat(str1,strcat(str2,"ghi"));//strcat:串接文字
    return strcmp(str1,str2);//strcmp:比較2字串大小,s1>s2:大於1 s1<s2:小於0 s1=s2:0
}

int test05(){
    int a[]={1,2,3,4,5};
    int *p,*q;
    p=&a[8];
    q=p-3;
    p-=6;
    return p-q;
}

int test06(){
    int v=0xFF;
    v&=1;
    v|=0;
    v<<=3;
    v>>=1;
    return v;
}

int test07(){
    int grade=4,ans=0;
    switch(grade){
        case 4:ans+=4;
        case 3:ans+=2;
        case 2:ans+=2;
        case 1:ans+=1;
        default:ans=0;
    }
    return ans>0?ans:0;
}
int test08(){
    int i=0;
    return i++;
}
int test09(int n){
    int i=1;
    while(i<n)i*=2;
    return i;
}
int test10(int n){
    int div;
    if(n<=1)return 0;
    for(div=2;div*div<=n;div++){
        if(n%div ==0)return 0;
    }
    return 1;
}
int main(){
   printf("%d\n",test01(3));
   printf("%d\n",test02());
   printf("%d\n",test03(123));
   printf("%d\n",test04());
   printf("%d\n",test05());
   printf("%d\n",test06());
   printf("%d\n",test07());
   printf("%d\n",test08());
   printf("%d\n",test09(100));
   printf("%d\n",test10(7));
    
}