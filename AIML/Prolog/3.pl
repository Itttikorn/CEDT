% Facts
man(marcus).
pompeian(marcus).
ruler(caesar).

% Rules
roman(X) :- pompeian(X).

loyal_to(X, caesar) :- roman(X), \+ hates(X, caesar).

% Assassination implies disloyalty
hates(X, Y) :- man(X), ruler(Y), try_assassinate(X, Y).

% Additional fact
try_assassinate(marcus, caesar).
