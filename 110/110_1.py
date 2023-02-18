# 二分搜索函數。參數包括：
# data：要搜索的已排序列表。
# left：數據的最小索引。
# right：數據的最大索引。
# key：搜索目標。
# 如果函數能在列表中找到目標值，則返回該值的索引。如果列表中沒有目標值，返回 "-1"。

def search(data, left, right, key):
    # 計算列表的中點索引。
    mid = (left + right) // 2

    # 如果中點的值等於目標值，返回中點的索引。
    if data[mid] == key:
        return mid

    # 如果左右索引相等，則目標值不在列表中。
    if left == right:
        return -1

    # 如果中點的值大於目標值，搜索列表的左半部分。
    if data[mid] > key:
        return search(data, left, mid-1, key)
        # return search(data, left, mid, key)

    # 如果中點的值小於目標值，搜索列表的右半部分。
    else:
        return search(data, mid+1, right, key)
        # return search(data, mid, right, key)


def f(x):
    # 調用search函數，並打印結果。
    print(search([1, 5, 9, 14, 23, 26], 0, 5, x))


# 使用一些示例輸入來測試函數。
f(5)   # 預期輸出：1
f(14)  # 預期輸出：3
f(26)  # 預期輸出：5
f(2)   # 預期輸出：-1
