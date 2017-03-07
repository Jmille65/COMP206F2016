import ctypes
import sys

if __name__=='__main__':
    filter = ctypes.cdll.LoadLibrary("libfast_filter.so")
    filter.doFiltering.argtypes = (ctypes.c_char_p, ctypes.POINTER(ctypes.c_float), ctypes.c_int, ctypes.c_char_p)

    #input preparation
    file_to_read = open(sys.argv[1], 'rb')
    file_input = file_to_read.read()
    file_to_read.close()
    filter_width = int(sys.argv[3])
    out_img_data = ' ' * len(file_input)
    weight_array = []
    filter_width_squared = int(filter_width) * int(filter_width)
    for i in range(4,filter_width_squared + 4):
        weight_array.append(float(sys.argv[i]))
    cfloat_array_instance = ( ctypes.c_float * len(weight_array))( *weight_array )

    #calling and cleanup
    file_to_write = open(sys.argv[2], 'wb')
    filter.doFiltering(file_input, cfloat_array_instance, filter_width, out_img_data)
    file_to_write.write(out_img_data)
    file_to_write.close()
