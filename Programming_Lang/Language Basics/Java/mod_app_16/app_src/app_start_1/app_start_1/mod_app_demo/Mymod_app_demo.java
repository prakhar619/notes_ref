package app_start_1.mod_app_demo;

import app_func_2.simple_func.simpleMathFunc;
public class Mymod_app_demo {
    public static void main(String args[])
    {
        if(simpleMathFunc.isFactor(2,10))
        System.out.println("2 is a factor of 10");

        System.out.println("Smallest factor common to both 35 and 105 is "+simpleMathFunc.lcf(35,105));
        System.out.println("Largest Factor common to both 35 and 105 is "+simpleMathFunc.gcf(35,105));
    }
}
