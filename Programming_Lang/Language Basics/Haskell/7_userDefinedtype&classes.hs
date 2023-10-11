--user defined types and classes and data types

-- value  -> (set of value) => types -> (set of types & overloaded operators) => classes
-- Value (user defined need to be in 1st letter caps), same of type

--TYPE DECLARATION
--1. Combining or reusing old types
type UserIntList = [Int]
type UserPair =  (Int , Char)
type functionType = UserPair->UserPair
--recursive declaration not allowed: type userPair = (Int, userPair)

--type declaration can b parameterized by other types
type Pairr a = (a,a)
type Assocc k v = [(k,v)]


--2. New data types
-- data type = value1 | value2			
data UserBin = Bin_1 | Bin_0
data UserDir = North | South | East | West	--new values are called constructor
						--constructor 1st letter CAPS
						--same constructor should not be used more than one type

data Shape = Circle Float | Rect Float Float
	--Constructor in data can also have arguments
	--Constructor are kind of like function when used with argument;
	-- :type Circle 
	--Value of Shape Circle 10.01 or Rect 10.2 1.2
myarea :: Shape -> Float
myarea (Circle r) = pi * r ^ 2
myarea (Rect x y) = x*y


-- :type Circle		gives: Circle::Float->Shape
			-- Circle 1.0 is already evaluated and most simplified
			-- Diff b/w constructor and function: function evaluates, whereas constructor is already in simplified form.

--Recursive is allowed in data 
data Recur = ZERO | ONE Recur
	--values
		--ZERO
		--ONE ZERO
		--ONE(ONE ZERO)
		--ONE(ONE(ONE ZERO)) and so on...
		
--Recursive data best suited for recursive functions
			
--3. If new type has single constructor with single argument then also use newtype

newtype Shapz = Square Int
			--Square is a single constructor with single argument
-- data Shapz = Square Int





--CLASS DECLARATION

class MyEq a where
instance MyEq Bool where
False === False = True
True === True = True
_ === _ = False

	--each class has operator instance.(instance of class)
	
class MyEq a => MyOrd a where
 (<),(>),(<=),(>=) :: a -> a -> Bool
 min, max	   :: a -> a -> a
 instance MyOrd Bool where
  False < True = True
  _ < _ = False
 min x y | x <= y = x
         | otherwise = y
 max x y | x <= y = y
         | otherwise = x
  

	







