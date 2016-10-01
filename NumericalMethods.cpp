#include "NumericalMethods.h"
#include <bits/stdc++.h>

using namespace std;



NumericalMethods::NumericalMethods()
{

}

double NumericalMethods::f(double x)
{

    double sum = 0;
    for(int i = 0; i < p ; i++)
        sum = sum + equn[i] * (pow(x , p - i) ) ;
    sum += equn[p];

    return sum ;
}

void NumericalMethods::fin(double p)
{
    for(int i = 0 ; i <= p ; i++)
    {

        if(i == p  )
            cout << "c" << endl;
        else
            cout << "x^" << p-i << endl;
        cin >> equn[i];
        //cout << equn[i] << endl;
    }

}

void NumericalMethods::falseMethod(float xl , float xu , float es)
{
    //float xr = (xl + xu) / 2;
    float xr;
    float xrold, testl , testu,  ea;
    int iter = 1;

    while(1)
    {
        if((f(xl) * f(xu)) > 0)
        {
            cout << "functional values are on same side" << endl;
            return ;
        }
        xr = xu - ( (f(xu) * (xl - xu))/(f(xl) - f(xu)));
        testl = f(xl) * f(xr);
        testu = f(xu) * f(xr);
            ea = abs((xr - xrold)/xr) * 100;
        if(testl > 0 && testu > 0)
        {
            cout << "There is no root " << endl;
            break;
        }

        //cout <<iter++ << " " <<xl << " " <<  xu <<" " <<xr << " " << ea << endl;
        printf("%d    %.2f    %.2f     %.2f    %.2f\n", iter++, xl, xu, xr, ea );
        if(testl < 0)
            xu = xr;
        else if(testl > 0)
            xl = xr;
        else
            {
                //cout <<iter++ << " " << xl << " " <<  xu <<" " <<xr << " " << ea << endl;
                printf("%d    %.2f    %.2f     %.2f    %.2f\n", iter++, xl, xu, xr, ea );
                break;
            }

        xrold = xr;
        //xr = (xl + xu) / 2;
        if(ea <= es)
            break;

    }

}

void NumericalMethods::falseMethodCall()
{
    //int p;
    //NumericalMethods nm;
    cout << "Enter equn power " << endl;
    cin >> p;
    cout << "Enter function coefficients" << endl;
    fin(p);
    float xl , xu , es, imax , xr;
    cout << "enter xl , xu , es , imax " << endl;
    //cin >> xl >> xu >> es >> imax >> xr ;
    //ModFalsePos(xl, xu, es, imax, xr, 1000, 100);

    while(1){
            cin >> xl >> xu >> es ;
            cout << f(xl) << f(xu) <<endl;
        if((f(xl) * f(xu)) > 0)
        {
            cout << "xl and xu are not valid . input correct value" << endl;

        }
        else
            break;
    }


    //bisection(xl, xu, es);
    cout << "false method" << endl;
    falseMethod(xl , xu , es);
}

void NumericalMethods::bisectionMethod(float xl , float xu , float es)
{
    float xr = (xl + xu) / 2;
    float xrold, test, ea;
    int iter = 1;
    if((f(xl) * f(xu)) > 0)
    {
        cout << "functional values are on same side" << endl;
        return ;
    }


    while(1)
    {
        test = f(xl) * f(xr);
            ea = abs((xr - xrold)/xr) * 100;
        //cout << xl << " " <<  xu <<" " <<xr << " " << ea << endl;
            printf("%d    %.2f    %.2f     %.2f    %.2f\n", iter++, xl, xu, xr, ea );
        if(test < 0)
            xu = xr;
        else if(test > 0)
            xl = xr;
        else
            {
                printf("%d    %.2f    %.2f     %.2f    %.2f\n", iter++, xl, xu, xr, ea );
                break;
            }

        xrold = xr;
        xr = (xl + xu) / 2;
        if(ea <= es)
            break;

    }

}

void NumericalMethods::bisectionMethodCall()
{
    //int p;
    //NumericalMethods nm;
    cout << "Enter equn power " << endl;
    cin >> p;
    cout << "Enter function coefficients" << endl;
    fin(p);
    float xl , xu , es, imax , xr;
    cout << "enter xl , xu , es , imax " << endl;
    //cin >> xl >> xu >> es >> imax >> xr ;
    //ModFalsePos(xl, xu, es, imax, xr, 1000, 100);

    while(1){
            cin >> xl >> xu >> es ;
            cout << f(xl) << f(xu) <<endl;
        if((f(xl) * f(xu)) > 0)
        {
            cout << "xl and xu are not valid . input correct value" << endl;

        }
        else
            break;
    }


    //bisection(xl, xu, es);
    cout << "Bisection method" << endl;
    cout << "iter-----xl-----xu------xr-------ea " << endl;
    bisectionMethod(xl , xu , es);
}

void NumericalMethods::secantMethod(float x1, float x2 , float es)
{
    float ea, x3;
    int iter = 1;
    while(1)
    {

        x3 = x2 - (f(x2) * (x1 - x2)) / (f(x1) - f(x2));
        ea = abs((x3 - x2)/x3) * 100;
        cout << iter++ << " " << x1 << " " << x2 << " " << x3 << " " << ea << endl;
        if(ea <= es)
            break;
        x1 = x2;
        x2 = x3;

    }

}

void NumericalMethods::secantMethodCall()
{
    float a, b, c;
    cout << "Enter equn power " << endl;
    cin >> p;
    cout << "Enter function coefficients" << endl;
    fin(p);
    cout << "Enter x-1 ,  x0 and es:" ;
    cin >> a >> b >> c;
    cout << "iter-----x1-----x2------x3-------ea " << endl;
    secantMethod(a, b, c);

}


void NumericalMethods::gauss_siedel_call()
{
    int row , column;
    float  e, es;
    cout << "Enter (row x coulm)  " << endl;
    cout << "Do not enter o as diagonal value" << endl;
    cin >> row >> column ;
    for(int i = 1; i <= column+1 ; i++)
        printf("x%d  ", i);
    cout << endl;
    for(int i = 1; i <= row ; i++)
        for(int j = 1; j <= column+1; j++ )
        {
            cin >> e ;
            if(j == column+1)
                b[i] = e ;
            a[i][j] = e; 

        }
        cout << "Enter Threshold erro :" << endl;
        cin >> es;
        gauss_siedel(es, row, column);

}

void NumericalMethods::gauss_siedel(float es, int row, int column)
{
    float sum = 0,  error , ea ;
    int maxError, maxErrorIndex = 1000;
    for(int i = 1; i <= row ; i++)
    {
        x[i][1] = 1;
        x[i][2] = 0;
    }

    while(1)
    {
        for(int i = 1 ; i <= row ; i++)
        {
            sum = b[i];
            for(int j = 1 ; j <= column ; j++)
            {

                if(i != j)
                    sum -= a[i][j]*x[j][1];
                //cout << sum << endl; 
            }
            x[i][2] = (sum / a[i][i] );
            

        }
        maxError = -111;
            for(int i = 1; i <= row ; i++)
            {

                error = abs(x[i][2] - x[i][1]);
                if(error > maxError)
                {
                    maxErrorIndex = i;
                    maxError = error;
                }
                

            }
            ea = abs((x[maxErrorIndex][2] - x[maxErrorIndex][1]) / x[maxErrorIndex][2]);
            for(int i = 1; i <= row ; i++)
            {
                x[i][1] = x[i][2];
            }
            if(ea < es)
            {
                for(int i = 1; i <= row ; i++)
                {
                    cout<< x[i][1] <<endl;
                    //printf("%d", x[i][1]);

                }
                break;


            }
            

    }

}
