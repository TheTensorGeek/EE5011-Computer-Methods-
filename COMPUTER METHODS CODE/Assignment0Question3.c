#include<stdio.h>
#include<conio.h>
#include<math.h>

/*Function to evaluate Li(x)*/
 
float Li(int i, float xx[100], float x){
    int j;
    double product=1;
    for(j=0;j<=99;j++){
        if(j!=i)
            product=product*(x-xx[j])/(xx[i]-xx[j]);
    }
        return product;
}
 
/*Function to evaluate lintp(x) where lintp is the Lagrange interpolating polynomial of degree n*/
 
float lintp( float xx[100], float yy[100], float x){
    double sum=0;
    int i;
    for(i=0;i<=99;i++){
        sum=sum+Li(i,xx,x)*yy[i];
    }
    return sum;
}
main(){
    int i,n;  //n is the degree
    //int pi=3.14159;
    /*printf("Enter the number of data-points:\n");
    scanf("%d",&n);  //no. of data-points is n+1
    n=n-1;*/
    //Arrays to store the (n+1) x and y data-points of size n+1
    float xx[100];
    float yy[100];
    //printf("Enter the x data-points:\n");

    for(i=0;i<100;i++){
        //scanf("%f",&xx[i]);
        xx[i]=(2*M_PI*i)/(99.0);
        //printf(" xx: ");
        printf(" %f", xx[i]);
        //printf(" ,");
        yy[i]=sin(xx[i]); 
        //printf(" yy:");
        printf(" %f", yy[i]);
        printf(" \n");  
    }
     
    /*printf("Enter the y data-points:\n");
    for(i=0;i<n+1;i++){
        scanf("%f",&yy[i]);
    }*/
     
    float x;  //value of x for which interpolated value is required
    //float f=x*M_PI/180;
    printf("Enter the value of x for which you want the interpolated value of y(x):\n");
    scanf("%f",&x);
    printf("The interpolated value is %f",lintp(xx,yy,x));
}