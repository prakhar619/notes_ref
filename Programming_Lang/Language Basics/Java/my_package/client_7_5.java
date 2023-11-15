package my_package;

//add abstract if Incomplete implementation of interface
// abstract class client implements interface_7
// public class client implements interface_class.interface_7
public class client_7_5 implements interface_7  // interface_7,interface_8  (multiple interface implementation)
{
    public int sum(int x,int y,int z)       //we can define addition properties like access during implementation
    {
        return x+y+z;
    }
    public int mult(int x,int y,int z)
    {
        return x*y*z;
    }
    public int div(int x,int y)
    {
        return x/y;
    }

    public void class_fun()
    {
        System.out.println("Class can also have their own methods");
    }
}
abstract class client_7_nestedInterface implements nested_interface.interface_nested,var_interface
{
    public boolean corr_incorr(int x,int y)
    {
        return x>y;
    }

    public void var_usage(){
        System.out.println(prime);
        System.out.println(pi);
    }

}



