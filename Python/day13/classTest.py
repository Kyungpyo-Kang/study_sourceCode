#%% (1) class test
class A :
    data = 10
    
    def printData(self) :
        print(self.data)


obj1 = A()
obj2 = A()

obj1.data = 20
obj1.printData()
#%% (2) class test2

class Car :
    brand = ""
    color = ""
    price = 0
    
    
    def __init__ (self, color='미지정', price=0, brand='미지정') :
        self.brand = brand
        self.color = color
        self.price = price
    
    def engineStart(self) :
        print(self.brand + "시동 켬")

    def engineStop(self) :
        print(self.brand + "시동 끔")
        
        

mom = Car()
dad = Car()
mine = Car()











