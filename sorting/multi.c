#include<stdio.h>
int multiply(int a,int b)
{
int n;
if(get_no_digit(a)==1 || get_no_digit(b)==1){

 return a*b;
}else
{
 int a0,a1,b0,b1;
 n=get_maxno_digit(a,b);
 int divisor=get_divisor(a);
 int r=n/2;
 a1=a/divisor;
 a0=a%divisor;
 divisor=get_divisor(b);
 b1=b/divisor;
 b0=b%divisor;
 int c1=multiply(a1,b1);
 int c0=multiply(a0,b0);
 int c2=multiply((a1+a0),(b1+b0))-(c1+c0);
 return c1*pow(10,2*r)+c2*pow(10,r)+c0;
}
}
int get_no_digit(int a)
{
int cnt=0;
while(a!=0)
 {
 a=a/10;
 cnt++;
 }
return cnt;
}
int get_maxno_digit(int a,int b)
{
int cnt1=get_no_digit(a),cnt2=get_no_digit(b);
if(cnt1>cnt2){
 return cnt1;
}else{
return cnt2;
}
}
int get_divisor(int a)
{
 const unsigned int B=10;
 unsigned int divisor=B;
 while(a/divisor>divisor){
 divisor*=B;
}
 return divisor;
}
int main()
{
int a,b;
printf("Enter Two Integers");
scanf("%d%d",&a,&b);
printf("\n%d",multiply(a,b));
}
