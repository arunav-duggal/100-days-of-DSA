
m, n = map(int, input().split())
matrix_a = []
for _ in range(m):
    matrix_a.append(list(map(int, input().split())))
matrix_b = []
for _ in range(m):
    matrix_b.append(list(map(int, input().split())))
for i in range(m):
    row_sum = []
    for j in range(n):
        element_sum = matrix_a[i][j] + matrix_b[i][j]
        row_sum.append(str(element_sum))
    print(" ".join(row_sum))
