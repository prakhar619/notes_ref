/*
Invariants:
Statement which is assumed to be true for a class is called class invariants or invariant.
Job of constructor to establish the invariant for its class.
*/

int main()
{
    static_assert(10 >= sizeof(int),"size of int too big");
    // static_assert(<condiction>,<statement to print if condiction is false>)
}


/*
IT TAKES ATLEAST TWICE THE EFFORT TO DEBUG THE CODE THAN TO WRITE IT.

Common fallacies:
1. Dont use debugger/print statement on your own code. Learn to debug with text only.
2. Check not only main conditions/flow but also limit and other conditions too.
3. Typo is worst mistake.

For other people code:

Errors
	1. User Error
		User as in who runs the program and input the data)
		i. User can be non-programmer (who plays the game). Player Errors
		ii. User can be tester, developer during building the game. Developer Errors
	2. Programmer Error
		Bug

Player Error:
	Make input for concrete
	Visual and Audio cues for wrong input

Developer Error:
	i. Return Error Codes
		Rather than boolean, return enumerated value to indicate success or failure
	ii. Exceptions
		try-catch-finally blocks
		Inefficient
			If even one function uses exeception handling whole code must use exception handling
			Like goto statement, inefficient
	iii. Assertions
		To check programmer's assumptions 
			After long time when code is reused, assertion provide proper safegaurd

		C++ Assertion Implementation
			#if ASSERTION_ENABLED
				#define debugBreak asm { int 3 }									
				#define ASSERT(expr) \
					if (expr) { } \ 
					else \
					{ \
						reportAssertionFailure(#expr, __FILE__, __LINE__);
						debugBreak(); \
					}
			#else
				#define ASSERT(expr) 
			#endif

			int 3 insert a breakpoint and stop execution for debugger to take charge

		2 types of Assert
			ASSERT() and SLOW_ASSERT() 
*/