# include<stdio.h>                              
# include<string.h>                             
float test01(void){                             
	int a = 5, b = 2;                               
	return a / b;                                   
}                                               
int test02(void){                               
	enum {Spring, Summer, Fail = 5, Winter} season;     
	int x;                                    
	x = Spring + Summer + Fail + Winter;       
	return x;                                  
}                                               
int test03(void){                               
	int n = 1;                                      
	for(;;){                                        
		n *= 5;                                         
		if (n > 55) break;                              
	}                                               
	return n;                                       
}                                               
int test04(void){                                
	struct {char str1[10], str2[10];} s;          
	strcpy(s.str1, "yahoo");                        
	strcpy(s.str2, "google");                       
	strcat(s.str1, strcat(s.str2, "adobe"));              
	return strcmp(s.str1, s.str2);   
}                                               
int test05(void){                               
	int a[] = {10, 20, 30, 40, 50};                 
	int *p = &a[sizeof(a)/sizeof(int) - 1], *q = a; 
	return (p - q);                                 
}                                               
int test06(void){                               
	int digits = 0, n = 12345;                      
	do {                                        
	n/= 10;                                     
	digits++;                                   
	} while (n > 0);                            
	return digits;                              
}                            
int test07(void){                           
	int grade = 3, ans;                         
	switch (grade) {                            
	case 4: ans = 4;                            
	case 3: ans = 3;                            
	case 2: ans = 2;                            
	case 1: ans = 1;                            
	default: ans = 0;                           
	}                                           
	return ans;                                 
}                                           
int test08(void){                           
	int n = 0, sum = 0;                         
	while (n < 5) {                             
	n++;                                        
	if (n < 3) continue;                        
	sum += n;                                   
	}                                           
	return sum;                                 
}
                                           
unsigned char test09(void){                 
	unsigned char a[] = {0xFF,0x00,0x01,0x08};                                      
	a[0] &=1;       
	a[1]|=1;                    
	a[2] <<= 3;      
	a[2] >>= 3;                  
	return (a[0] + a[1] + a[2] + a[3]);         
}
                                           
int test10(void) {                        
	int a[][3] = {{6,7,8}, {9,10,11}, {12,13,14}};
	return *&a[1][1];                           
}                                           

int main(){                                      
	printf("%3.1f\n", test01()); /* Problem 2-1 */ 
	printf("%d\n", test02());   /* Problem 2-2 */    
	printf("%d\n", test03());    /* Problem 2-3 */   
	printf("%d\n", test04());   /* Problem 2-4 */    
	printf("%d\n", test05()); /* Problem 2-5 */      
	printf("%d\n", test06());   /* Problem 2-6 */    
	printf("%d\n", test07());   /* Problem 2-7 */    
	printf("%d\n", test08());   /* Problem 2-8 */    
	printf("%u\n", test09());   /* Problem 2-9 */    
	printf("%d\n", test10());   /* Problem 2-10 */  
	return 0;                                        
}                                                
