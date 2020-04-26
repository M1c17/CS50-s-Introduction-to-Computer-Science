
#Move elements of list[0..i-1], that are
#greater than the current i, to one position ahead 
#of their current position 
def insertion_sort(list):
    n = len(list)

    for i in range(1, n):
        current_index = list[i]
        print("v is", current_index)
        index = i - 1
        print("i is", index)
        while index >= 0:
            #compare current i with left i 
            if current_index < list[index]:
                #swap i right with left i
                list[index + 1] = list[index]
                list[index] = current_index
                print("i+1 is", list[index + 1])
                print("i is", list[index])
                index -= 1
            else:
                break
    return list

list_0 = [6,7,9,0,1,2,3]
print(insertion_sort(list_0))


            

