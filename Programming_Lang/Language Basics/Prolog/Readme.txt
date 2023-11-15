Prolog
    Language that is useful for doing symbolic and logic based computation
    Declarative
        meaning implementingg the solution to problem to a problem, instead of specifying how to achieve the goal
    swipl compiler
    .pl or .pro extension   
        .pl conflicts with perl file extension.

Components:
    Terms
        Constant
            Identifiers (starting char = lowercase char & != _)
            Numbers     (1100 )
            String      ('Hello')
        Variables   (starting char = uppercase or _)
            can take any Component as value (const or predicate or anything else)
        Structures  ( <identifier>(<term1>,<term2>,<term3>)  )                       ( date(1,may, 1900+83-1) )
            List
    Predicate   ( <identifier>(<term1>,<term2>,<term3>)  )                          syntactically similar to structure
    Facts       ( <identifier>(<term1>,<term2>,<term3>). )
    Rules       ( predicateH:- predicate1,predicate2,predicate3. )
    Query       ( predicate1,predicate2,predicate3. )                                sequence of predicates


swipl   
    [filenameWithoutextension]
        use ' ' to use with extension
    consult(<filenameWithoutextension).
        use' ' to use with extension 
    pwd
    chdir('<path>')
    make.
        to reload file.
    ["filename.pro"]
        to load file.
    ["filename"]
        to load .pl file


Operating/Solving Queries
    Queries replace or delete(replace with empty) -> No query left=>(original query binding or true) else Query left=>false

    Match 1st predicate of query with Fact or RuleHead
        Then Replace
            for Fact-> empty Query
            for RuleHead-> RuleBody
    if No Match then Backtract or Return false

Matching Conditions(Unification):
    same Predicate name
    same arity of Predicate
    argument matching:
        if all constant => identical => matching                                                            (elephant(a)        elephant(a))
        if one or more bound variable => bound variable value identical => matching                         (X=a,elephant(X)    elephant(a))
        if one or more unbound variable =>bind the unbound variable 

        _ is an unbound variable which cannot be bounded (exception)
        can be binded with any term.

    Example:        (try these by directly giving these query to swipl).
        p(X,2,2) = p(1,Y,X).
            false.
        f(a,g(X,Y)) = f(X,Z), Z=g(W,h(X)).
            true.
        

Replacing:
    When unified
        Rule body is put in front of remaining query.
        then recursive solve again:
            if SOlved rturn true
            else Backtrack (undo all changes to variable binding that you did earlier)
        return false;

Representation
    predicate01/1   (this predicate takes 1 argument as input)

Style:
blond(X):-
 father(Father,X),
 blond(Father),
 mother(Mother,X),
 blond(Mother).

 Operator Precedence:
    Precedence No (0-1200)
    Lower precedence no => stronger binding.
    precedence of term is 0
        
        
SWIPL may not print full list when list is more than 9-10 element
    use the following cmd to print all list element.
        set_prolog_flag(answer_write_options,[max_depth(0)]).

Always while writing prolog code (on pen and paper) run one iterater at least.