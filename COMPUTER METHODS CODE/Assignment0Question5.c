#include<stdio.h>
#include<conio.h>
#include<math.h>

/*Function to evaluate Pi(x)*/
 
float Pi(int i, int n, float XX[n+1], float x){
    int j;
    double product=1;
    for(j=0;j<=n;j++){
        if(j!=i)
            product=product*(x-XX[j])/(XX[i]-XX[j]);
    }
        return product;
}
 
/*Function to evaluate lintp(x) where lintp is the Lagrange interpolating polynomial of degree n*/
 
float lintp(int n, float XX[n+1], float YY[n+1], float x){
    double sum=0;
    int i;
    for(i=0;i<=n;i++){
        sum=sum+Pi(i,n,XX,x)*YY[i];
    }
    return sum;
}
main(){
    int i,n=3,N;  //n is the number of neighbouring point using which we have to interpolate the function 
    float pi=3.14159;
    
    printf("Enter the number of data-points:\n");
    scanf("%d",&N);  //no. of data-points is N
    //Arrays to store the (N+1) x and y data-points of size N+1
    //XX are the array of 4 i.e n+1 nearest point for a point x at which we want the interpolated value 
    // xx are the array of the N+1 points 
    float XX[n];
    float YY[n];
    float xx[N];
    float yy[N];
    //printf("Enter the x data-points:\n");

    //printf("The xx data-points:\n");

    for(i=0;i<=N;i++){
        //scanf("%f",&xx[i]);
        xx[i]=i*2*pi/N;
        yy[i]=sin(xx[i]); 
       // printf("\n %f",xx[i]); 
        //printf(" %f",yy[i]);
       // printf("\n");
    }
     
    float x;  //value of x for which interpolated value is required
    //printf("\nValues of x and its interpolated value y(x):\n");
    for(int k=0;k<100;k++){
        x=k*pi*2/99;
        printf("\n %f",x);

        //Logic for Searching of the point x
        unsigned long ju,jm,jl,j;
        int ascnd;
        int t;
        jl=0; 
        ju=N; 
        ascnd=(xx[N] >= xx[1]);
        while (ju-jl > 1) {
              jm=(ju+jl) >> 1; 
              if (x >= xx[jm] == ascnd){
                    jl=jm; 
              }
              else{
                    ju=jm; 
              }
        } 
        if (x == xx[0]) j=0; 
        else if(x == xx[N]) j=N;
        else if(x >= xx[N]) j=N;
        else if(x <= xx[0]) j=0;
        else j=jl;

        //Logic for the Generating the 4 neighbouring Points of x
         if(j==0){
              for(i=0;i<=3;i++){
                   XX[i]=xx[j];
                   YY[i]=yy[j];
                   j=j+1;
              }
        }
        
        else if(j==(N-1)){
                  t=j+1;
                  for(i=0;i<=3;i++){
                      XX[i]=xx[t];
                      YY[i]=yy[t];
                      t=t-1;
                  }
        }
              
        else if(j==N) {
              for(i=0;i<=3;i++){
                 XX[i]=xx[j];
                 YY[i]=yy[j];
                 j=j-1;
              }
        }
        else {
                  t=j-1;
                  for(i=0;i<=3;i++){
                      XX[i]=xx[t];
                      YY[i]=yy[t];
                      t=t+1;
                  }
        }    
        //printf("\nThe nearest 4 Values of x are: ");
        //for(i=0;i<=3;i++){
             //printf("\n %f",XX[i]);
              //printf("\n");
        //}
        
        printf(" %f",lintp(n,XX,YY,x)); // Calling lintp function and generating the interpolated value 
        printf("\n");
    }
    
}
