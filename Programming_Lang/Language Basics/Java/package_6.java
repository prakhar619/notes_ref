import my_package.*;
// import my_package.my_package_1;
// import my_package.*;

//import static my_package.my_package_1.functi;
//static import used to use static function by using directly its name without using class name
// Math.pow() becomes pow() by using import static java.lang.Math.pow;
//use * instead of functi to import all static function of that class

//either import statement(import my_package.*) or in extend mention package(my_package.my_package_1)
// i have done both simulanteously just to show
class package_inherit extends my_package.my_package_1
{
    public package_inherit()
    {
        super();
        System.out.println("At start this class will not be executed. ONLY WHEN CLASS OBJECT CREATED THEN ONLY CONSTRUCTOR INITIALISED");
    }
    public static void main(String args[])
    {
    
	functi(10);//another package static function

    package_inherit obj = new package_inherit();
    obj.opera(10);
    }
	
}
