def mirror_name(s):
    if len(s) <= 1:
        return s
    return s[-1] + mirror_name(s[:-1])
code_name = input().strip()
print(mirror_name(code_name))
