#include <bits/stdc++.h>
#include "NumericalMethods.h"

using namespace std;

void UI()
{
    char r1, r2, r3 , r4, r5, r6;
    NumericalMethods nm;
    printf("Welcome to Numerical Methods World.\n");
    while(1)
    {

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
	                break;
	            }
	            break;
	        }
	    }
	    char ch;
	    printf("E. For exit and C.For continue\n");
	    cin >> ch ;
	    if(ch == 'E')
	    	break;

    }


}

void mui()
{
    char r1, r2, r3 , r4, r5, r6;
    NumericalMethods nm;
    printf("(:----Welcome to Numerical Methods World-------:)\n");
    while(true)
    {
        printf("1.Roots of equation\n\n2.Solution of multiple equations\n\n3.Interpolation\nE.Exit");
        cin >> r1;
        if(r1 == '1')
        {
            printf("1.Bracketing Method\n2.Opening Method\n\nC.Main Menu\n\nE.Exit\n");
            cin >> r2;
            if(r2 == '1')
            {
                printf("1.False Method\n2.Bisection Method\n\n\nC.Main Menu\n\nE.Exit\n");
                cin >> r3;
                if(r3 == '1')
                {
                    nm.falseMethodCall();
                }else if(r3 == '2')
                {

                    nm.bisectionMethodCall();
                }else if(r3 == 'E' || r3 == 'e')
                {
                    break;
                }else if(r3 == 'C' || r3 == 'c')
                {
                    continue;
                }
            }else if(r2 == '2')
            {
                printf("1.Secant Method\n");
                cin >> r4;
                if(r4 == '1')
                {
                    nm.secantMethodCall();
                }
            }else if(r2 == 'E' || r2 == 'e')
            {
                break;
            }else if(r2 == 'C' || r2 == 'c')
            {
                continue;
            }

        }else if(r1 == '2')
        {
            cout << "1.Gauss Siedel elimination\n\nC.Main Menu\n\nE.Exit\n" << endl;
            cin >> r5;
            if(r5 == '1')
            {
                nm.gauss_siedel_call();
            }else if(r5 == 'E' || r5 == 'e')
            {
                break;
            }else if(r5 == 'C' || r5 == 'c')
            {
                continue;
            }
        }else if(r1 == '3')
        {
            cout << "1.Newtons divide-difference\n\nC.Main Menu\n\nE.Exit\n" << endl;
            cin >> r6;
            if(r6 == '1')
            {
                nm.newtons_divided_difference();
            }else if(r6 == 'E' || r6 == 'e')
            {
                break;
            }else if(r6 == 'C' || r6 == 'c')
            {
                continue;
            }
        }
        else if(r1 == 'e' || r1 == 'E')
        {
            break;
        }

    }
}

int main()
{

    //nm.falseMethodCall();
    //nm.secantMethodCall();
    //nm.bisectionMethodCall();
    //nm.gauss_siedel_call();
    mui();

    return 0;
}
