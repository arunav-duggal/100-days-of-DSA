def power(a, b):
    if b == 0:
        return 1
    else:
        return a * power(a, b - 1)
user_input = input().split()
base = int(user_input[0])
exp = int(user_input[1])
print(power(base, exp))
