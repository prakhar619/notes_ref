//try;catch;throw;throws;finally


/*
	try
	{  
		throw
	}
	catch(exception1 e)
	{
		
	}
	catch(exception2 e)
	{
		
	}
	finally
	{
	
	}
*/

/*All exception types are subclass of THROWABLE. 

 		Throwable
		/	 		\
	Exception		Error
	(catchable)    		(error of runtime env;Stack overflow)
	(divide by zero, invalid array)
		|
	RuntimeException
*/

//Cannot use try on single statement
//each catch associated with a try; therefore wont catch error of another nested try

//	catch (ArithmeticException e)
//  catch (ArrayIndexOutOfBoundsException e)
//  catch (NullPointerException e)
//  catch (IllegalAccessException e)

/* 
When you call in try block and called function return error 
int void function(int x) throws exception_name
{
}	
*/

/*throw to make error ourself without java runtime system making error */
// throw obj_or_x;
// obj_or_x must be object of type throwable or subclass of throwabe
// int,char,String,Object cannot be used as exception
// catch (obj_type e)



/*throws is used to declare the error that function can show*/
// public static void err_func() throw ArithmeticException,ArrayIndexOutOfBoundsException
//Runtime exception need not to be in function declaration.
//These are unchecked exceptions


/*BUILT IN EXCEPTIONS
 * java.lang contains both checked and unchecked exceptions
 * 
 */