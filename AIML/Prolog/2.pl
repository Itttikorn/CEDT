minus(X,0,X).
minus(s(X),s(Y),Z) :- minus(X,Y,Z).

plus(0,Y,Y).
plus(s(X),Y,s(Z)) :- plus(X,Y,Z).

times(_,0,0).
times(X,s(Y),Z) :- times(X,Y,W), plus(X,W,Z).

power(_,0,s(0)).
power(X,s(Y),Z) :- power(X,Y,W), times(X,W,Z).