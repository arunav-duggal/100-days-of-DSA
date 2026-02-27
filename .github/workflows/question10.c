def is_palindrome(s):
    left = 0
    right = len(s) - 1
    while left < right:
        if s[left] != s[right]:
            return "NO"
        left += 1
        right -= 1
    return "YES"
s = input().strip()
print(is_palindrome(s))
