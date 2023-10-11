import numpy as np 

print("This is DES encrypter")
print("Enter plain text in hexadecimal form (16 character)(64 bits)")
plain_text = input()
print("Enter key in hexadecimal form(16 character)(64 bits)")
key = input()

ip_table = np.array([ 
                [58,50,42,34,26,18,10,2],
                [60,52,44,36,28,20,12,4],
                [62,54,46,38,30,22,14,6],
                [64,56,48,40,32,24,16,8],
                [57,49,41,33,25,17,9,1],
                [59,51,43,35,27,19,11,3],
                [61,53,45,37,29,21,13,5],
                [63,55,47,39,31,23,15,7]])

fp_table = np.array([ 
                [40,8,48,16,56,24,64,32],
                [39,7,47,15,55,23,63,31],
                [38,6,46,14,54,22,62,30],
                [37,5,45,13,53,21,61,29],
                [36,4,44,12,52,20,60,28],
                [35,3,43,11,51,19,59,27],
                [34,2,42,10,50,18,58,26],
                [33,1,41,9,49,17,57,25]])

s_boxes = np.array([
        [   [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
            [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
            [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
            [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]],
 
        [   [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
            [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
            [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
            [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9]],
 
        [   [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
           [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
            [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
            [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12]],
 
        [   [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
            [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
            [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
            [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]],
 
        [   [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
            [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
            [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
            [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3]],
 
        [   [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
            [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
            [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
            [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13]],
 
        [   [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
            [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
            [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
            [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]],
 
        [   [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
            [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
            [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
            [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]]])

p_table = np.array([[16,7,20,21,29,12,28,17],
                    [1,15,23,26,5,18,31,10],
                    [2,8,24,14,32,27,3,9],
                    [19,13,30,6,22,11,4,25]])

pc1_table = np.array([[57,49,41,33,25,17,9],
                    [1,58,50,42,34,26,18],
                    [10,2,59,51,43,35,27],
                    [19,11,3,60,52,44,36],
                    [63,55,47,39,31,23,15],
                    [7,62,54,46,38,30,22],
                    [14,6,61,53,45,37,29],
                    [21,13,5,28,20,12,4]])

pc2_table = np.array([
            [14, 17, 11, 24, 1, 5,3, 28],
            [15, 6, 21, 10,23, 19, 12, 4],
            [26, 8,16, 7, 27, 20, 13, 2],
            [41, 52, 31, 37, 47, 55,30, 40],
            [51, 45, 33, 48,44, 49, 39, 56],
            [34, 53,46, 42, 50, 36, 29, 32]])

shift_schedule = np.array([1, 1 ,2 ,2 ,2 ,2 ,2 ,2 ,1 ,2 ,2 ,2 ,2, 2 ,2, 1])

def hex2bin(plain_text):
    mp = {'0': "0000",
          '1': "0001",
          '2': "0010",
          '3': "0011",
          '4': "0100",
          '5': "0101",
          '6': "0110",
          '7': "0111",
          '8': "1000",
          '9': "1001",
          'A': "1010",
          'B': "1011",
          'C': "1100",
          'D': "1101",
          'E': "1110",
          'F': "1111"}
    bin = ""
    for i in range(len(plain_text)):
        bin = bin + mp[plain_text[i]]
    return bin
 
def bin2hex(n):
    mp = {"0000": '0',
          "0001": '1',
          "0010": '2',
          "0011": '3',
          "0100": '4',
          "0101": '5',
          "0110": '6',
          "0111": '7',
          "1000": '8',
          "1001": '9',
          "1010": 'A',
          "1011": 'B',
          "1100": 'C',
          "1101": 'D',
          "1110": 'E',
          "1111": 'F'}
    hex = ""
    for i in range(0, len(n), 4):
        ch = ""
        ch = ch + n[i]
        ch = ch + n[i + 1]
        ch = ch + n[i + 2]
        ch = ch + n[i + 3]
        hex = hex + mp[ch]
 
    return hex 

def ip(plain_binary):       #binary string-> permuated array
    binary_array = np.zeros(64,dtype = np.int64)
    for i in range(0,8,1):
        for j in range(0,8,1):
            binary_array[(i*8) + j] = int(plain_binary[ip_table[i][j] -1 ])
    L,R = np.split(binary_array,2)
    return L,R


def pc_1(key_binary):
    key_binary_array = np.zeros(56,dtype = np.int64)   
    for i in range(0,8,1):
        for j in range(0,7,1):
            key_binary_array[(i*7)+j] = int(key_binary[pc1_table[i][j] -1])
    key_L,key_R = np.split(key_binary_array,2)
    return key_L,key_R

key_L,key_R = pc_1(hex2bin(key))

def subkey_left_shifter(round_no):
    shift = shift_schedule[round_no]
    if (shift  == 1):
        key_L1, key_R1 = key_L[0],key_R[0]
        for i in range(1,28,1):
            key_L[i-1],key_R[i-1] = key_L[i],key_R[i]
        key_L[27],key_R[27] = key_L1,key_R1
    else:
        key_L1, key_R1 = key_L[0],key_R[0]
        key_L2, key_R2 = key_L[1],key_R[1]
        for i in range(2,28,1):
            key_L[i-2],key_R[i-2] = key_L[i],key_R[i]
        key_L[26],key_R[26] = key_L1,key_R1
        key_L[27],key_R[27] = key_L2,key_R2

def pc_2():
    subkey = np.zeros((48),dtype=np.int64)
    L_R = np.concatenate((key_L,key_R))
    for i in range(0,6,1):
        for j in range(0,8,1):
            subkey[(i*8)+j] = L_R[pc2_table[i][j] -1]
    return subkey  

def subkey_gen(round_no):
    subkey_left_shifter(round_no)
    return pc_2()

def expansion():
    expanded_R = np.zeros(48,dtype=np.int64)
    j = 0
    expanded_R[j] = R[31]
    j+=1
    for i in range(0,32,1):
        if(i%4!=0 or i == 0):
            expanded_R[j] = R[i]
            j+=1
        elif (i % 4 == 0):
            expanded_R[j] = R[i]
            j+=1
            expanded_R[j] = R[i-1]
            j+=1
            expanded_R[j] = R[i]
            j+=1
            
    expanded_R[j] = R[0]
    return expanded_R  

def xor( expanded_R_48,subkey_48):
    xor_48 = np.bitwise_xor(expanded_R_48,subkey_48)
    return xor_48  

getbinary = lambda x, n: format(x, 'b').zfill(n)

def s_box_substitution(xor_48):
    substituted_ar_32 = np.zeros(32,dtype=np.int64)
    for i in range(0,8,1):
        s0 = xor_48[i*6 + 0]
        s1 = xor_48[i*6 + 1]
        s2 = xor_48[i*6 + 2]
        s3 = xor_48[i*6 + 3]
        s4 = xor_48[i*6 + 4]
        s5 = xor_48[i*6 + 5]
        row = int(str(s0) + str(s5),2)
        column = int(str(s1)+str(s2)+str(s3)+str(s4),2)
        bits_4_string = str(getbinary(s_boxes[i][row][column],4))
        for j in range(0,4,1):
            substituted_ar_32[i*4+j] = bits_4_string[j]
    return substituted_ar_32

def p_box_permutation(substituted_ar_32):
    permutated_ar_32 = np.zeros(32,dtype=np.int64)
    for i in range(0,4,1):
        for j in range(0,8,1):
            permutated_ar_32[(i*8)+j] = substituted_ar_32[p_table[i][j] -1]
    return permutated_ar_32

def friestal_func(round_no):
    P = p_box_permutation(s_box_substitution(xor(expansion(),subkey_gen(round_no) )))
    return P

def print_hex_LR(Arr):
    str_L = ""
    for i in range(0,32,1):
        str_L += str(Arr[i])
    str_L = bin2hex(str_L)
    print(str_L)

def fp(final_L_R):
    bin_str= ""
    cipher_binary = np.zeros(64,dtype= np.int64)
    for i in range(0,8,1):
        for j in range(0,8,1):
            cipher_binary[(i*8) + j] = final_L_R[fp_table[i][j] -1 ]
    for i in range(0,64,1):
        bin_str += str(cipher_binary[i])
    bin_num = int(bin_str)
    return bin_str

L,R = ip(hex2bin(plain_text))

for i in range(0,16,1):
    R_dup = R
    R = np.bitwise_xor(friestal_func(i),L)
    L = R_dup
L,R = R,L
final_combined_LR= np.concatenate((L,R))
print(bin2hex(fp(final_combined_LR)))