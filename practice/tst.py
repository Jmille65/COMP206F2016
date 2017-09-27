b = 10
def f( a=5 ):
    b = a - 1
    print b
    print a
    return a + 3
def g( a=7, b=11 ):
    print "a=",a
    print "b=",b
    return (3*f(a)) / (2*b)
a = 2
b = 10
c = g
d = c( b=a )
print a,b,d
