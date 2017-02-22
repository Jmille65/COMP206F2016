################################################################################
FINISHED FILE IS ON UBUNTU VM AS OF DEC 4 2016



import sys
import ctypes

if __name__ == '__main__':
    cdll.LoadLibrary("libc.dylib")
    libc = CDLL("libc.dylib")
    libc.printf("Hello World\n")
