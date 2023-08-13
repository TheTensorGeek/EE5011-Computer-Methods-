#script to test the polint module
from scipy import *
from matplotlib.pyplot import *
import os
import re 
import scipy.integrate as intg
import scipy.special as sp
import polint as p
#test 
tests="polint"

if re.search('polint',tests):
   #interpolate on a table of sin(x) as test
   def locate(xx,n,i,j,m):
        jl=0
        ju=n
        #ascnd=(xx[n]>= xx[0])
        while(ju-jl > 1):
            jm=ju+jl >> 1
            if  (i >= xx[jm] ):
                jl=jm 
            else :
                ju=jm 
        if (i == xx[0]):
            j=0
        elif (i==xx[n-1]) :
            j=n-1 
        else:
            j=jl            
        return min(max(j-(m-1)//2,0),n-m)           
        
       
   
   
   n=int(input("Enter the number:"))
   m=int(input("Enter The Order:"))
   y=zeros(200)
   dy=zeros(200)
   xx=linspace(0,1,n)
   yy=sin(xx + xx**2)
   x=linspace(-0.5,1.5,200)
   j=0
   k=0
   for i in x:
       l=where(x==i)
       k=locate(xx,n,i,j,m)
       xn = xx[k:k+m+1]
       yn = yy[k:k+m+1]
       y[l]=[p.polint(xn,yn,i)[0]]
       dy[l]=[p.polint(xn,yn,i)[1]]
   
   #plot the outputs
   #figure(1)
   #plot(xx,yy,'ro',x,y,'r',x,sin(x + x**2),'g')
   #title("Interpolated sin(x + x^2)")
   #legend(["Table values","Interpolated values","True function"])
   
   figure(2)
   semilogy(x,abs(array(dy)),'r',x,abs(array(sin(x + x**2)-y)),'g')
   title("Estimated and True Error")
   legend(["Estimated Error","True Error"])
   savefig("PolintQuestionOne.png")
#end if   
   