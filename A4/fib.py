import sys

def fib(n):
    a = 0
    b = 1
    for i in range(1,n):
        c = a + b
        a = b
        b = c
    return c

if __name__ == '__main__':
    print fib(int(sys.argv[1]))
