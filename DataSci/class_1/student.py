class Complex:
    def __init__(self, a, b):
        # Constructor to initialize real (a) and imaginary (b) parts
        self.r = a
        self.i = b
    def __str__(self):
        ret = ""
        if (self.r != 0):
            ret = str(self.r)
            if (self.i > 0):
                ret += "+"
        if (self.i < -1 or self.i > 1):
            ret += str(self.i)
        if (self.i != 0):
            ret += "i"
        if (self.r == 0 and self.i == 0):
            ret = "0"
        return ret
    def __add__(self, rhs):
        # Method to add two complex numbers
        return Complex(self.r + rhs.r, self.i + rhs.i)
    def __mul__(self, rhs):
        # Method to multiply two complex numbers
        return Complex(self.r * rhs.r - self.i * rhs.i, self.r * rhs.i + self.i * rhs.r)
    def __truediv__(self, rhs):
        # Method to divide two complex numbers
        return Complex(((self.r * rhs.r) + (self.i * rhs.i))/(rhs.r**2 + rhs.i**2),((-self.r * rhs.i) + (self.i * rhs.r))/(rhs.r**2 + rhs.i**2))

#**Copy and paste your class with modified functions when submitting to the grader.

t, a, b, c, d = [int(x) for x in input().split()]
c1 = Complex(a,b)
c2 = Complex(c,d)
if t == 1 : print(c1)
elif t == 2 : print(c2)
elif t == 3 : print(c1+c2)
elif t == 4 : print(c1*c2)
else : print(c1/c2)