
print("This is encryption for caesar cipher")
print("Enter the path(absolute)/location of the text file which you want to encrypt")
in_path = input()
print("Enter the key")
key = int(input())

#path contain "\" instead of "/" therefore and also removing starting and ending ""
def path_correction(incorr_path):
    corr_path = ""
    for c in incorr_path:
        if(c == "\\"):
            corr_path+="/"
        elif(c == "\""):
            continue
        else:
            corr_path+= c
    return corr_path


fobj_out = open("./Encrypted.txt","w")
fobj_in = open(path_correction(in_path),"r")



for in_line in fobj_in:
    out_line = ""
    for c in in_line:
        if( ord(c) >= 96 and ord(c) <=122 ):
            out_line += chr(((ord(c)-97+key)%26)+97)
        else:
            out_line+=c
    fobj_out.write(out_line)

fobj_out.close()
fobj_in.close()

    





