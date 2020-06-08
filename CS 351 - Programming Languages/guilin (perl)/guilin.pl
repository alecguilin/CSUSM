% Alec Guilin
% CS351
% May 9 2019


% NOTE: 
% I used the revised prolog assignment document and none of the students pass the elective requirement
% For testing purposes I made galileo pass physics301 to complete his elective requirement (currently commented out)


department(cs).
department(math).
department(physics).

course(cs111, cs).
course(cs211, cs).
course(cs311, cs).
course(cs315, cs).
course(cs441, cs).
course(cs436, cs).
course(math270, math).
course(math242, math).
course(math372, math).
course(math480, math).
course(phys201, physics).
course(phys301, physics).

student(fermat).
student(turing).
student(galileo).
student(lovelace).

enrolled(fermat, cs311).
enrolled(fermat, cs441).
enrolled(fermat, math372).
enrolled(turing, cs441).
enrolled(turing, math480).
enrolled(turing, physics301).
enrolled(galileo, cs315).
enrolled(galileo, cs441).
enrolled(lovelace, math480).
enrolled(lovelace, math372).

passed(galileo, cs111).
passed(galileo, cs211).
passed(galileo, cs311).
passed(galileo, cs436).
passed(galileo, math270).
passed(galileo, math242).
passed(galileo, physics201).
%passed(galileo, physics301).
passed(turing, cs111).
passed(turing, cs211).
passed(turing, cs311).
passed(turing, math270).
passed(turing, math372).
passed(turing, physics201).
passed(turing, physics301).
passed(fermat, cs111).
passed(fermat, cs211).
passed(lovelace, cs111).
passed(lovelace, cs211).

core(cs111).
core(cs211).
core(cs311).
core(cs441).
core(math270).
core(physics201).

elective(cs315, cs).
elective(cs436, cs).
elective(math242, math).
elective(math372, math).
elective(math480, math).
elective(physics301, physics).

corecompleted(X) :- 
    (passed(X, cs111) ; enrolled(X, cs111)),
    (passed(X, cs211) ; enrolled(X, cs211)),
    (passed(X, cs311) ; enrolled(X, cs311)),
    (passed(X, cs441) ; enrolled(X, cs441)),
    (passed(X, math270) ; enrolled(X, math270)),
    (passed(X, physics201) ; enrolled(X, physics201)).

electivecompleted(X) :-
	((passed(X, Y) ; enrolled(X, Y)), elective(Y, cs)),
	((passed(X, Z) ; enrolled(X, Z)), elective(Z, math)),
	((passed(X, W) ; enrolled(X, W)), elective(W, physics)).

% overloaded - finds completed electives for a given student
% ex. "electivecompleted(galileo, A, B, C)."
electivecompleted(X, Y, Z, W) :-
	((passed(X, Y) ; enrolled(X, Y)), elective(Y, cs)),
	((passed(X, Z) ; enrolled(X, Z)), elective(Z, math)),
	((passed(X, W) ; enrolled(X, W)), elective(W, physics)).

degree(X) :-
	corecompleted(X),
	electivecompleted(X).