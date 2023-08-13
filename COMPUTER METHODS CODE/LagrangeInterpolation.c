#include<stdio.h>
#include<conio.h>
#include<math.h>

/*Function to evaluate Pi(x)*/
 
float Pi(int i, int n, float xx[n], float x){
    int j;
    double product=1;
    for(j=0;j<=n;j++){
        if(j!=i)
            product=product*(x-xx[j])/(xx[i]-xx[j]);
    }
        return product;
}
 
/*Function to evaluate lintp(x) where lintp is the Lagrange interpolating polynomial of degree n*/
 
float lintp(int n, float xx[n], float yy[n], float x){
    double sum=0;
    int i;
    for(i=0;i<=n;i++){
        sum=sum+Pi(i,n,xx,x)*yy[i];
    }
    return sum;
}
main(){
    int i,n;  //n is the degree
    int pi=3.14159;
    printf("Enter the number of data-points:\n");
    scanf("%d",&n);  //no. of data-points is n
    //Arrays to store the (n+1) x and y data-points of size n+1
    float xx[n];
    float yy[n];
    //The sine fucntion is sampled at xx data points(I have taken it in the radian) 
    //yy are the corresponding values of function sampled at xx
    printf("Enter the xx data-points:\n");
    for(i=0;i<=n;i++){
        xx[i]=i*2*M_PI/n;
        yy[i]=sin(xx[i]); 
        printf("\n %f",yy[i]);  
    }
     
    float x;  //value of x for which interpolated value is required
    printf("\nValues of x and its interpolated value y(x):\n");
    //Evaluating the function on 100 uniformly spaced values between 0 and 2*pi
    for(i=0;i<100;i++){
        x=i*M_PI*2/99;
    printf("\n %f",x);
    printf(" %f",lintp(n,xx,yy,x));
    printf("\n");
    }
}