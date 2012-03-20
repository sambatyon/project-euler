# I used python instead of C++ to avoid writing a bigint class
# althoug probably I will have to do it later

m = 2**1000
res = 0
for ch in str(m):
    res += int(ch)

print(res)
