cmake_minimum_required (VERSION 2.6)
project (A3)

add_library(decryptLib SHARED q1a_decrypt.c)

add_executable(decrypt q1a_decrypt.c)

add_executable(crack q1b_crack.c)

add_executable(q2_text_chat q2_text_chat.c)

add_executable(q3_encrypted_chat q3_encrypted_chat.c)
target_link_libraries(q3_encrypted_chat decryptLib)
