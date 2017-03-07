import ctypes
import sys
import pickle
import os.path

def load(input_image_path):
    file_to_read = open(input_image_path, 'rb')
    file_input = file_to_read.read()
    file_to_read.close()
    pkl_file = open('history.pickle', 'wb')
    pkl_list = [1, file_input]
    pickle.dump(pkl_list, pkl_file)
    pkl_file.close()

def filter(filter_width, filter_weights):
    if os.path.isfile('history.pickle'):
        pass
    else:
        print "No file loaded"
        return 0

    filter = ctypes.cdll.LoadLibrary("libfast_filter.so")
    filter.doFiltering.argtypes = (ctypes.c_char_p, ctypes.POINTER(ctypes.c_float), ctypes.c_int, ctypes.c_char_p)

    #preparing inputs
    pkl_file = open('history.pickle', 'rb')
    pkl_list = pickle.load(pkl_file)
    pkl_file.close()
    current_index = int(pkl_list[0])
    file_input = pkl_list[current_index]
    out_img_data = ' ' * len(file_input)
    cfloat_array_instance = ( ctypes.c_float * len(filter_weights))( *filter_weights )

    filter.doFiltering(file_input, cfloat_array_instance, filter_width, out_img_data)

    #pickling
    for i in range(current_index + 1, len(pkl_list)):
        pkl_list.pop()
    current_index += 1
    pkl_list.append(out_img_data)
    pkl_list[0] = current_index
    pkl_file = open('history.pickle', 'wb')
    pickle.dump(pkl_list, pkl_file)
    pkl_file.close()

    #updating image
    result = open('result.bmp', 'wb')
    result.write(out_img_data)
    result.close()

def undo():
    if os.path.isfile('history.pickle'):
        pass
    else:
        print "No file loaded"
        return 0

    pkl_file = open('history.pickle', 'rb')
    pkl_list = pickle.load(pkl_file)
    pkl_file.close()
    current_index = pkl_list[0]
    if current_index < 2:
        print "Cannot undo"
    else:
        current_index -= 1
        result = open('result.bmp', 'wb')
        result.write(pkl_list[current_index])
        result.close()
    pkl_file = open('history.pickle', 'wb')
    pkl_list[0] = current_index
    pickle.dump(pkl_list, pkl_file)
    pkl_file.close()

def redo():
    if os.path.isfile('history.pickle'):
        pass
    else:
        print "No file loaded"
        return 0

    pkl_file = open('history.pickle', 'rb')
    pkl_list = pickle.load(pkl_file)
    pkl_file.close()
    current_index = pkl_list[0]
    if current_index == len(pkl_list) - 1:
        print "Cannot redo"
    else:
        current_index += 1
        result = open('result.bmp', 'wb')
        result.write(pkl_list[current_index])
        result.close()
    pkl_file = open('history.pickle', 'wb')
    pkl_list[0] = current_index
    pickle.dump(pkl_list, pkl_file)
    pkl_file.close()

if __name__=='__main__':
    if sys.argv[1] == 'load':
        load(sys.argv[2])
    elif sys.argv[1] == 'filter':
        filter_width = int(sys.argv[2])
        filter_weights = []
        i = 0
        for i in range(3, len(sys.argv)):
            filter_weights.append(float(sys.argv[i]))
        filter(filter_width, filter_weights)
    elif sys.argv[1] == 'undo':
        undo()
    elif sys.argv[1] == 'redo':
        redo()
    else:
        print "Invalid command"
