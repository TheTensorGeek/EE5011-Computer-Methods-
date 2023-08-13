#include<stdio.h>
#include<conio.h>
#include <math.h>
int polint(float *xa,float *ya,float *x,float *y, float *dy,int n){
  int i,j,n1,m,ns,ns0;
  double den,dift,ho,hp,w;
  //double *xa,*ya,*x,*y,*dy; // window to use by polint
  c[0]=d[0]=0.0;
  xa=xarr;ya=yarr; // initialize pointers
  for(j=0,n1=0;j<N;j++){ // loop over xarr points
    x=&xx[j];y=&yy[j];dy=&dyy[j];
    for(i=n1,ns=M-1;i<M;i++){ // loop over x points
      if(x<=xarr[i]){ // found crossover
        ns=i;
        break;
      }
    } // i loop
    if( i==n1 ){
      for(ns=n/2;i>=0;i--){ // loop over x points
        if(x>xarr[i]){ // found crossover
          ns=i;
          break;
        }
      } // i loop
    }
    n1=ns-n/2;
    n1=(n1<0?0:n1); // eliminate -ve n1
    n1=(n1+n>=M?M-n-1:n1); // eliminate +v overflow
    xa=&xarr[n1];ya=&yarr[n1];
    ns-=n1;ns=(ns<n/2?n/2:ns);
    ns0=ns;
    // from here it is basically the NR code
    for(i=0;i<=n;i++){ // initialize c and d
      c[i]=ya[i];
      d[i]=ya[i];
    }
    y=ya[ns--];
    for(m=1;m<=n;m++){
      for(i=0;i<=n-m;i++){
        ho=xa[i]-x;
        hp=xa[i+m]-x;
        w=c[i+1]-d[i];
        if((den=(ho-hp))==0.0)
          exit(1);
        den=w/den;
        d[i]=hp*den;
        c[i]=ho*den;
      } // i loop
      y+=(dy=(2*ns<(n-m)?c[ns+1]:d[ns--]));
    } // m loop
  } // j loop

}
int main(){
    int j,n;  //n is the degree
    float y,dy;
    printf("Enter the number of data-points:\n");
    scanf("%d",&n);  //no. of data-points is n
    //Arrays to store the (n+1) x and y data-points of size n+1
    float *xx[n];
    float *yy[n];
    //The sine fucntion is sampled at xx data points(I have taken it in the radian) 
    //yy are the corresponding values of function sampled at xx
    printf("Enter the xa data-points:\n");
    for(j=1;j<=(n+1);j++){
        xx[j]= j*0.2;
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
    //printf(" %f",polint(xx,yy,n,a,b,dyy));
    printf("\n");
    }
    
}