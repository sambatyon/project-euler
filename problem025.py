import sys

def main(args):
    prev = 1
    cur = 1
    i = 2
    while len(str(cur)) < 1000:
        tmp = cur
        cur += prev
        prev = tmp
        i += 1
    print(i)

if __name__ == '__main__':
    main(sys.argv)
