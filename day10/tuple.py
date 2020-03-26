#%% (1) mutable
dataList1 = [1,2,3]
dataList2 = dataList1
print(id(dataList1))
print(id(dataList2))
dataList2.append(4)

print(dataList1)
#%% (2) immutable
#dataTuple1 = (1,2,3)
dataTuple1 = 1,2,3
print(type(dataTuple1))
dataTuple2 = dataTuple1
dataTuple2 += 4,5
print(dataTuple2)
print(dataTuple1)
