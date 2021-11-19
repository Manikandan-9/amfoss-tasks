L=[]
dict = {}
N = int(input())
for x in input().split():
    x = int(x)
    L.append(x)
for i in L:
    dict[i] = L.count(i)
towers = len(dict)
all_values = dict.values()
tallest_tower = max(all_values)

print(tallest_tower,towers)