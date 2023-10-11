namespace my_code
{
    class complex
    {
        private:
        double a,b;
        public:
        complex(double simple,double complex)
        {
            a = simple;
            b = complex;
        }
    };
    int interface_function();
    int main()
    {
        class my_code::complex* mycomplex = new my_code::complex(1.5,5.8);
        return 1;
    }
}

int my_code :: interface_function()
{
    int a = 10;
    return a;
}

int main()
{
   return my_code::main();
}
