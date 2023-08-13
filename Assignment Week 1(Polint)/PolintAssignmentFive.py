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
   y=zeros(1000)
   dy=zeros(1000)
   xx=linspace(0.1,0.9,n)
   yy=sin(pi*xx)/((1-xx**2)**0.5)
   x=linspace(0.1,0.9,1000)
   j=0
   k=0
   for i in x:
       l=where(x==i)
       k=locate(xx,n,i,j,m)
       xn = xx[k:k+m+1]
       yn = yy[k:k+m+1]
       y[l]=[p.polint(xn,yn,i)[0]]
       dy[l]=[p.polint(xn,yn,i)[1]]
   max=dy[0]
   #for b in range(0, 199):     
    #    if(abs(dy[b]) > max):    
    #         max = abs(dy[b])
   #print(max)
   max(abs(array(sin(pi*x)/((1-x**2)**0.5)-y)))
   #plot the outputs
   #figure(1)
   #plot(xx,yy,'ro',x,y,'r',x,sin(x + x**2),'g')
   #title("Interpolated sin(x + x^2)")
   #legend(["Table values","Interpolated values","True function"])
   
   #figure(2)
   #semilogy(x,abs(array(dy)),'r',x,abs(array(sin(pi*x)/((1-x**2)**0.5)-y)),'g')
   #title("Estimated and True Error")
   #legend(["Estimated Error","True Error"])
   #savefig("PolintQuestionOne.png")
#end if   
   