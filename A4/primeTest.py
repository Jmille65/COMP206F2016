import sys
import math

def primeTest(n):
    for i in range(2, ((int(math.sqrt(n))+1))):
        if n%i == 0:
            return False
    else:
        return True

if __name__ == '__main__':
    if primeTest(int(sys.argv[1])) == True:
        print "Prime"
    else:
        print "Not a prime"
