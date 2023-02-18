def search(data, left, right, key):
    # 計算中間索引位置
    mid = (left + right) // 2
    # 判斷中間值是否等於目標值，若等於則回傳中間索引
    if data[mid] == key:
        return mid
    # 判斷左右邊界是否相等，若相等則表示找不到目標值，回傳-1
    if left == right:
        return -1
    # 判斷中間值是否大於目標值，若大於則在左半邊繼續搜尋
    if data[mid] > key:
        return search(data, left, mid - 1, key)
    # 否則在右半邊繼續搜尋
    else:
        return search(data, mid + 1, right, key)

def f():
    data = [1, 5, 9, 14, 23, 26]
    my_dict = {}
    # 將搜尋目標與回傳值存入字典
    my_dict[9] = search(data, 0, 5, 9)
    my_dict[1] = search(data, 0, 5, 1)
    my_dict[4] = search(data, 0, 5, 14)
    # 印出字典
    print(my_dict)
    # 印出索引為1到5，間隔為2的元素
    print(data[1:5:2])

# 執行函式f()
f()
# f(5)
# f(26)
