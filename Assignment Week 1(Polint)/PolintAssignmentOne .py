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
   #interpolate on a table of sin(x + x**2) as test
   xx=linspace(0,1,5)
   yy=sin(xx + xx**2)
   x=linspace(-0.5,1.5,200)
   y=[p.polint(xx,yy,w)[0] for w in x ]
   dy=[p.polint(xx,yy,w)[1] for w in x]
   
   #plot the outputs
   figure(1)
   plot(xx,yy,'ro',x,y,'r',x,sin(x + x**2),'g')
   title("Interpolated sin(x + x^2)")
   legend(["Table values","Interpolated values","True function"])
   
   figure(2)
   semilogy(x,abs(array(dy)),'r',x,abs(array(sin(x + x**2)-y)),'g')
   title("Estimated and True Error")
   legend(["Estimated Error","True Error"])
   savefig("PolintQuestionOne.png")
#end if   
   