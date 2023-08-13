#include<stdio.h>
#include<conio.h>
#include <math.h>
#include "nrutil.h"
int polint(float xa[], float ya[], int n, float x, float y, float dy)
/*Given arrays xa[1..n] and ya[1..n], and given a value x, this routine returns a value y, and
an error estimate dy. If P(x) is the polynomial of degree N - 1 such that P(xai) = yai, i =
1,..., n, then the returned value y = P(x).*/
{
    int i,m,ns=1;
    float den,dif,dift,ho,hp,w;
    float c[300],d[300];
    dif=fabs(x-xa[1]);
    for (i=1;i<=n;i++) {                 // Here we find the index ns of the closest table entry,
        if ( (dift=fabs(x-xa[i])) < dif) {            
                        ns=i;
                        dif=dift;
        }
        c[i]=ya[i]; //and initialize the tableau of c’s and d’s.
        d[i]=ya[i];
    }
    y=ya[ns--];                    //This is the initial approximation to y.
    for (m=1;m<n;m++) {             //For each column of the tableau,
        for (i=1;i<=n-m;i++) {          // we loop over the current c’s and d’s and update
            ho=xa[i]-x;                    //                  them.
            hp=xa[i+m]-x;
            w=c[i+1]-d[i];
//This error can occur only if two input xa’s are (to within roundoff) identical.
           den=w/den;
           d[i]=hp*den;// Here the c’s and d’s are updated.
           c[i]=ho*den;
        }
y += (dy=(2*ns < (n-m) ? c[ns+1] : d[ns--]));
/*After each column in the tableau is completed, we decide which correction, c or d,
we want to add to our accumulating value of y, i.e., which path to take through the
tableau—forking up or down. We do this in such a way as to take the most “straight
line” route through the tableau to its apex, updating ns accordingly to keep track of
where we are. This route keeps the partial approximations centered (insofar as possible)
on the target x. The last dy added is thus the error indication.*/

}
 return y;
}


int main(){
    int j,n;  //n is the degree
    float y,dy;
    printf("Enter the number of data-points:\n");
    scanf("%d",&n);  //no. of data-points is n
    //Arrays to store the (n+1) x and y data-points of size n+1
    float xa[n];
    float ya[n];
    //The sine fucntion is sampled at xx data points(I have taken it in the radian) 
    //yy are the corresponding values of function sampled at xx
    printf("Enter the xa data-points:\n");
    for(j=1;j<=(n+1);j++){
        xa[j]= j*0.2;
        int p=2;
       // double zz=pow(xa[j],p);
        ya[j]=sin(xa[j]+pow(xa[j],p)); 
        printf("\n %f",xa[j]);
        printf(" %f",ya[j]);  
    }
     
    float x;  //value of x for which interpolated value is required
    printf("\nValues of x and its interpolated value y(x):\n");
    //Evaluating the function on 100 uniformly spaced values between 0 and 2*pi
    for(j=0;j<=200;j++){
        x=(-0.5)+j*0.01;
    printf("\n %f",x);
    printf(" %f",polint(xa,ya,n,x,y,dy));
    printf("\n");
    }
    
}
