# I used python instead of C++ to avoid writing a bigint class
# althoug probably I will have to do it later
import sys
from functools import reduce

def main(args):
    print(reduce(lambda x, y : x + int(y), str(2**1000), 0))

if __name__ == '__main__':
    main(sys.argv)
