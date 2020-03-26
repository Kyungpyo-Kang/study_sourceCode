#%% (1) inheritance test
class A :
    data = 10
    
    def __init__(self, data=10):
        print("부모 생성자 호출")
        self.data = data
    
    def printData(self) :
        print(self.data)
        
    def show(self) :
        print("부모 메소드")
        
        
class B(A):

    def __init__(self, data, data2) :
        super().__init__(data)
        self.data2 = data2
        print("자식 생성자 호출")
        
    #Overriding    
    def printData(self) :
        print(self.data)
        print(self.data2)
        
        

obj = B(100, 200)
obj.show()
obj.printData()
