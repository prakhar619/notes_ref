--user defined types and classes and data types

-- value  -> (set of value) => types -> (set of types & overloaded operators) => classes
-- Value (user defined need to be in 1st letter caps), same of type

--TYPE DECLARATION
--1. Combining or reusing old types
	--type synonyms
type UserIntList =  [Int]
type UserPair =  (Int , Char)
--recursive declaration not allowed: type userPair = (Int, userPair)

--type declaration can be parameterized by other types
--type constructor (here Pairr is the construtor that takes the type a)
type Pairr a = (a,a)
type Assocc k v = [(k,v)]


--2. New data types
-- data type = value1 | value2			
data UserBin = Bin_1 | Bin_0
data UserDir = North | South | East | West	--new values are called constructor
						--constructor 1st letter CAPS
						--These contructor takes no args and returns UserDir datatype
						--same constructor should not be used more than one type

data Shape = Circle Float | Rect Float Float deriving (Show)
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


--Record Syntax
data Person = Person String String Int Float String String deriving (Show)
	--usually data Constructor have same as type
	--example: Person "Revai" "Ackreman" 12 1.4 "94949222432" "choco"

data Person_1 = Person_1 { firstName::String, lastName::String,
							age::Int, height::Float,phone::String, flavor::String} deriving (Show,Read,Eq)
	--example: Person_1 {firstName="Revai", lastName="Ackreman" ....}
	-- :t firstName:: Person->String (haskell automatically creates these functions)

data List a = Empty | Cons a (List a) deriving (Show)
data List_1 a = Empty_1 | Con_1 {listHead::a, listTail:: List_1 a} deriving (Show)

--Never add typeclass constraint in data declaration: data (Ord k) = ...


--Deriving Instance
	--A type can be made an instance of a typeclass if it supports that behaviour.
	--typeclasses are more like interfaces.
	--Haskell automatically make our type an instance of any of the following type when used deriving:
		--Eq
		--Ord
		--Enum
		--Bounded
		--Show
		--Read




--Concrete Type
	--Int, Bool etc
--Non Concrete Type
	--Maybe a, 



--CLASS DECLARATION
--class is a group of types(datatypes) and operators. Its constructor will a take type.
-- a plays a role of whichever type will be made an instance later
-- a is a concrete type; like this more non concrete types (class MyEq (Maybe a) where ) 
class MyEq a where
	(===)::a->a->Bool
	(==/)::a->a->Bool
	x==/y = not(x===y)
		--defining basic definition

--add space before False === False = True
--also align everything (very imp) with space (not tab) --else different types of parse error
--instance are defining interface for each datatype (type)
instance MyEq Bool where
 False === False = True
 True === True = True
 _ === _ = False


	--each class has operator instance.(instance of class)

class MyEq a => MyOrd a where
 (=<),(=<>),(=<=),(=<>=) :: a -> a -> Bool
 min, max	   :: a -> a -> a

instance MyOrd Bool where
   False =< True = True
   _  =<  _  = False
   min x y | x =<= y = x
			| otherwise = y
   max x y | x =<= y = y
			| otherwise = x


data Traffic = Blue | Red | Green | Error 
instance Show Traffic where 
 show Red = "red Light"
 show Green = "Green Light"
 show Blue = "blue Light"
 show Error = "COde 69"

	
--Functor TypeClass




