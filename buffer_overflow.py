'''
CS638
Exercise on Buffer Overflow (Part D)

@author Vishnu Sai Rao Suresh Lokhande (lokhande@cs.wisc.edu)

'''


def main():
    a = [0]*10;
    try:
        print(a[1]);
        print(a[1000]); # accessing element out of range
    except:
        print("EXCEPTION");

if __name__ == '__main__':
    main()
