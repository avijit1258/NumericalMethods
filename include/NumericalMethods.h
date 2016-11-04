#ifndef NUMERICALMETHODS_H
#define NUMERICALMETHODS_H


class NumericalMethods
{
    public:
        NumericalMethods();
        virtual ~NumericalMethods();
        void fin(double p);
        double f(double x);
        void falseMethod(float xl , float xu , float es);
        void falseMethodCall();
        void bisectionMethod(float xl , float xu , float es);
        void bisectionMethodCall();
        void secantMethod(float x1, float x2 , float es);
        void secantMethodCall();
        void gauss_siedel_call();
        void gauss_siedel(float es, int row, int column);
        void newtons_divided_difference();
    protected:
    private:
        int p;
		double equn[10];
        double a[100][100], x[100][3], b[100];
};

#endif // NUMERICALMETHODS_H
