# python implementatuion of bubble sort
def bubble_sort(arr_raw):
    """
    args:
        arr_raw: list to be sorted
    return:
        arr_sort: list sorted
    """
    for i in range(1, len(arr_raw)):
        for ii in range(0, len(arr_raw) - i):
            if arr_raw[ii] > arr_raw[ii + 1]:
                arr_raw[ii], arr_raw[ii + 1] = arr_raw[ii + 1], arr_raw[ii]
            else:
                pass
    
    return arr_raw

# python implementation of quick sort
def quick_sort(arr_raw, low, high):
    """
    args:
        arr_raw: list to be sorted
    return:
        arr_sort: list sorted
    """    
    def helper(arr, low, high):
        # recurrent helper
        pivtol = arr[high] # center for partition
        pivtol_pos = high # record the psotion
        high -= 1 # shift pointer to left
        while True:
            while arr[low] < pivtol:
                low += 1
            while arr[high] > pivtol:
                high -= 1
            if low >= high :
                break
            else:
                arr[low], arr[high] = arr[high], arr[low]
            
        arr[low], arr[pivtol_pos] = arr[pivtol_pos], arr[low]
        return low
         
    if high - low <= 0:
        return None
    pi = helper(arr_raw, low, high)
    quick_sort(arr_raw, low, pi - 1)
    quick_sort(arr_raw, pi + 1, high)


a = [9, 4, 5, 2, 4]
quick_sort(a, 0, len(a) - 1)
print(a)