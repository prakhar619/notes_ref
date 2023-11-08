bigger(elephant,horse).
bigger(horse,donkey).
bigger(donkey,dog).
bigger(donkey,monkey).
/*Facts only*/

/*Try the following query (facts alike syntax)
bigger(donkey,dog).                     True.
bigger(monkey,elephant).                False.
bigger(elephant,monkey).                False.
*/

% To add transitive relation of bigger  (X > Y, Y > Z) => X > Z

is_bigger(X,Y):- bigger(X,Y).
is_bigger(X,Y):- bigger(X,Z), is_bigger(Z,Y).
/*Rules only*/
/*Variables*/

/*More than just true & false.
Try the following query.
is_bigger(X,donkey). then press ; or enter
*/


