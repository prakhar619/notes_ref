import my_package.*;
public class accessing_interfacedClass_7
{
    public static void main(String[] args) {
    interface_7 obj_interface = new client_7_5();
    interface_7 obj2_interface = new client_7_5();
    //obj_interface is object of class client but data type interface;
    //same way superclass can refer to subclass

    System.out.println(obj_interface.sum(10,12,13));
    obj_interface = obj2_interface;
    System.out.println(obj_interface.sum(10,13,110));


    //interface_nested nestObj = new client_7_nestedInterface();



    }
}
