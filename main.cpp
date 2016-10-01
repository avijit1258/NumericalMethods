#include <bits/stdc++.h>
#include "NumericalMethods.h"

using namespace std;

void UI()
{
    char r1, r2, r3 , r4, r5;
    NumericalMethods nm;
    while(1)
    {
	    printf("Welcome to Numerical Methods World.\n");
	    printf("1.Roots of equation\n2.Solution of multiple equations\n");
	    cin >> r1;
	    switch(r1)
	    {
	    case '1' :
	        {
	            printf("1.Bracketing Method\n2.Opening Method\n");
	            cin >> r2;
	            switch(r2)
	            {
	            case '1':
	                {
	                   printf("1.False Method\n2.Bisection Method\n");
	                   cin >> r3;
	                   switch(r3)
	                   {
	                       case '1' : nm.falseMethodCall();
	                       case '2' : nm.bisectionMethodCall();
	                   }
	                   break;
	                }
	            case '2':
	                {
	                   printf("1.Secant Method\n");
	                   cin >> r4;
	                   switch(r4)
	                   {
	                       case '1' : nm.secantMethodCall();
	                        break;
	                   }
	                   break;
	                }
	            }
	            break;
	        }
	    case '2' :
	        {
	            cout << "1.Gauss Siedel elimination\n" << endl;
	            cin >> r5;
	            switch(r5)
	            {
	                case '1': nm.gauss_siedel_call();
	            }
	        }
	    }
	    char ch;
	    printf("E. For exit and C.For continue\n");
	    cin >> ch ;
	    if(ch == 'E')
	    	break;

    }
    

}

int main()
{
    
    //nm.falseMethodCall();
    //nm.secantMethodCall();
    //nm.bisectionMethodCall();
    //nm.gauss_siedel_call();
    UI();

    return 0;
}
