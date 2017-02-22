import sys

def fact(iterations):
    if iterations > 1:
        return long(iterations) * fact(long(iterations)-1)
    else:
        return 1

if __name__ == '__main__':
    iterations = sys.argv[1]
    print fact(iterations)
