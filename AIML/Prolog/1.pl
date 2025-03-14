rev(Xs,Ys) :- reverse(Xs,[],Ys).
reverse([],A,A).
reverse([H|T],A,Ys) :- reverse(T,[H|A],Ys).

lastmem([X],X).
lastmem([_|T],X) :- lastmem(T,X).