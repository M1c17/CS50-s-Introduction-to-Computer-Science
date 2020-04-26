
def buble_sort(list):
    n = len(list)

    for i in range(n):
        for j in range(0, n-i-1):
            if list[j+1] < list[j]:
                temp = list[j]
                list[j] = list[j+1]
                list[j+1] = temp
    return list

list_0 = [8,6,4,2,9,0,3,1]
print(buble_sort(list_0))
