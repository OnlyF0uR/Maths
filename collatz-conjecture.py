def main():
    n = int(input("Enter a positive number: "))
    if n < 1:
        print("Negative numbers and nul are not allowed.")
    else:
        s = 0
        while n != 1:
            if n % 2 == 0:
                n /= 2
            else:
                n = n * 3 + 1
            s += 1
        print("Finished in " + str(s) + " steps.")


if __name__ == '__main__':
    main()
