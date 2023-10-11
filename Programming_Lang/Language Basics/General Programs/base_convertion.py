class base_conversion:
    def __init__(self,base,num):
        self.converted_no = []
        while(num != 0):
            self.converted_no.insert(0,num%base)
            num = int(num/base)

    #Operator overload
    
    def print_(self):
        for i in self.converted_no:
            print(i,end=':')
        print()

obj = base_conversion(5,51)
obj.print_()