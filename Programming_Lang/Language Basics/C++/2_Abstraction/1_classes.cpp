/*
Class Kinds
1. Concrete classes
2. Abstract classes
3. Classes in class hierarchies
*/

/*
Concrete classes
    Behave like built in datatypes
    To increase flexibility, a concrete type can keep major parts of its representation on free store(dynamic memory, heap) and access them through part stored in class object itself.

    1.Container
        Constructor/Destructor
            RAII(Resource Acquisition Is Initialization): Acquiring resource in contructor and releasing them in destructor

        1.1.Initializing Container
                initializer_list<double>

*/
#include <initializer_list>
#include <algorithm>
    //copy()
namespace concrete
{
    class complex
    {
        double re,im;
        public:
            complex(double r,double i): re{r},im{i}{}
            complex(double r): re{r},im{0} {}
            complex(): re{0},im{0}{}

            double real() const{return re;}         //const specifier on functions means function do not modify the object for which they are called
            void real(double d){ re =d;}
            double imag() const{return im;}
            void imag(double d){im = d;}

            complex& operator+=(complex z)
            {
                re+=z.re;
                im+=z.im;
                return *this;
            }
            complex& operator*=(complex);
    };

    class vector1
    {
        private:
            double* elem;
            int sz;
        public:
            vector1(int s):elem{new double[s]}, sz{s}
            {
                for(int i =0; i!=s; ++i)
                {
                    elem[i] = 0;
                }
            }
            vector1(std::initializer_list<double> lst ):elem{ new double[lst.size()]}, sz{lst.size()}
            {
                std::copy(lst.begin(),lst.end(),elem);
            }
            ~vector1()
            {
                delete[] elem;
            }

            double& operator[](int i);
            int size() const;
    }; 
}


/*
Abstract Types
    Since we dont anything about the representation of the abstract type, we must allocate object on the free store and access them through ref and pointer
    virtual
        means may be redefined later in class derived from this one
    Abstract Class
        a class with a pure virtual function
        usually dont have constructor

    Flowchart
        Abstract class1
        function1 (dependent on Abstract class1 + implementation)
        Subclass class1 (inherits Abstract class)

        main function where we use subclass1 with function1(function1 is not specifically defined for subsclass but for abstract class)

        Container ( [],size() )
        use       ( prints container using [] )
        Vector_container  ( [], size() implementation)   and    List_container   (  [], size() implementation )

    Virtual Functions
        the usual implementation technique is for the compiler to convert the name of the virtual function into an index into a table of pointers to functions.
        That table is usually called virtual function table or vtbl. Each class with virtual has its own vtbl.
    
    #Virtual destructor can also overwritten
    BENEFITS
        1.Interface Inheritance (an object of derived class can be used whenever an object of a base class is required. base class acts as an interface for derived class)
        2.Implementation Inheritance (base class provide functions or data that simplify implementation of derived class)

*/
#include <iostream>
namespace Abstract
{
    class Container
    {
        public:
            virtual double& operator[](int) = 0;    //PURE VIRTUAL FUNCTION
            virtual int size() const = 0;           //const member function
            virtual ~Container(){}
    };
    void use(Container& c) //this function does care about implementation of operator[] 
    {
        const int sz = c.size();
        for(int i = 0; i!= sz; i++)
        {
            std::cout << c[i] << "\n";
        }
    }

    class Vector_container : public Container{
        private:
            concrete::vector1 v;
        public:
            Vector_container(int s): v(s) {}
            /* DONT KNOW BUT ERROR
            ------------------------------PROBLEM WITH v(s); WE dont know how member initialiser works for class (user defined)
            Vector_container(int s)
            {
                v(s);
            }
            */
            ~Vector_container(){}

            double& operator[](int i)
            {
                return v[i];
            }
            int size() const{
                return v.size();
            }

    };

    void g()
    {
        Vector_container vc(10);
        use(vc);
    }

}



