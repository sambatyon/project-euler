import sys
from functools import reduce

def main(args):
    num = 100
    fact = reduce(lambda x, y: x * y, range(1, num + 1))
    fact = reduce(lambda x, y: x + int(y), str(fact), 0)
    print(fact)

if __name__ == '__main__':
    main(sys.argv)
