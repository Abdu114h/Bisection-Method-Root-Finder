#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double eval(int degree, double *coo, double x)
{
    double result=0;
    int i;
    for(i=0;i<=degree;i++)
    {
        result+=coo[i]*(pow(x,i));
    }
    return result;
}

double root(int degree, double *coo, double left, double right)
{
    double lval,rval,mval,mid;
    int found=0;
    while(found==0)
    {
        lval=eval(degree,coo,left);
        rval=eval(degree,coo,right);
        mid=(right+left)/2;
        mval=eval(degree,coo,mid);
        if(lval*mval<0)
        {
            right=mid;
        }
        if(mval*rval<0)
        {
            left=mid;
        }
        if(fabs(mval)<0.000000000000001)
        {
            found=1;
            return mid;
        }

    }
}

void main()
{
    double left=0, right=1, coo[]={-2,1,-0.5,0.02,4,0.1};
    int degree=5;
    double result=root(5,coo,left,right);
    printf("%lf", result);

return 0;
}


