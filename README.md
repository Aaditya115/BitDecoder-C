This project focuses on creating a bit stream cipher decoder in C. The program starts by prompting the user for a 4-bit binary key, which is then expanded into an 8-bit key using bitwise operations. The main task is to decode an encrypted message using XOR operations, rotating the bits of the encrypted characters alternately to the left and right.

The project is divided into two key sections:

Key Generation – This part of the program prompts the user for a 4-digit binary key, processes it bit by bit using C code, and generates an 8-bit key by duplicating the 4-bit input pattern. This key will later be used for decoding.

Message Decryption – The program reads in encrypted hexadecimal values, rotates them alternately to the left or right, and uses the generated 8-bit key to decrypt the message using a bitwise XOR operation.

The goal of this lab is to practice fundamental C programming concepts such as bitwise operations, standard input/output functions (like getchar, scanf, and putchar), and creating reusable functions. Additionally, this project introduces debugging techniques and reinforces understanding of low-level data manipulation through bitwise operations.




