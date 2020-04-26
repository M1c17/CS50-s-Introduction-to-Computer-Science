
def selection_sort(list):
    for i in range(len(list)):
        min_i = i
        for j in range(i, len(list)):
            if list[j] < list[min_i]:
                min_i = j
        if i == min_i:
            continue
        temp = list[i]
        list[i] = list[min_i]
        list[min_i] = temp
    return list

#list_0 = [9,8,7,5,4,0,1] 
#print(selection_sort(list_0))


def selection_sort1(list):
    n = len(list)
    min_index = i
    for i in range(n):
        if list[i] < list[min_index]:
            #swap
            temp = list[i]
            list[i] = list[min_index]
            list[min_index] = temp
    return list 


