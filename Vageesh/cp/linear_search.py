def linear_search(list, target):
    for i in range(len(list)):
        if list[i] == target:
            return i


list = [1, 4, 5, 2, 4, 7, 6, 10]
n = 7
print(f"Location of {n} is", linear_search(list, n))
