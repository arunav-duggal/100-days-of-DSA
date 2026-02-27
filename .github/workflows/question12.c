
m, n = map(int, input().split())

matrix = []
for _ in range(m):
    matrix.append(list(map(int, input().split())))

def is_symmetric(mat, rows, cols):
    if rows != cols:
        return False
    for i in range(rows):
        for j in range(i + 1, cols): 
            if mat[i][j] != mat[j][i]:
                return False
    return True

if is_symmetric(matrix, m, n):
    print("Symmetric Matrix")
else:
    print("Not a Symmetric Matrix")
