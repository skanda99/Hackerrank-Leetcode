
# problem: "https://www.hackerrank.com/challenges/two-strings/problem"

n = int(input())

for i in range(n):
    s1=set(input())
    s2=set(input())

    if s1.intersection(s2):
        print('YES')
    else:
        print('NO')
