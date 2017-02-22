# This simple ctypes example shows passing a char* data buffer
# Remember to compile the library first and set your 
# LD_LIBRARY_PATH environment variable

import ctypes

clib = ctypes.cdll.LoadLibrary("./libweek12_ctypes_sample.so")

q = "Hello World"
clib.modString(q)
print q

