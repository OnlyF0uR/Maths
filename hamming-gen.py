# 16-bit block hamming code generator
# Based off of: https://www.youtube.com/watch?v=X8jsijhllIA
# Example input: 00110001110

def main():
    print("Enter a 11-bit chunk")
    ipt = input()
    if len(ipt) != 11:
        print("Invalid input")
        return

    arr = [[0, 0, 0], [0], [0], []]
    fdim = 0
    for s in ipt:
        arr[fdim].append(int(s))
        if len(arr[fdim]) == 4:
            fdim += 1

    # First parity check
    par1 = arr[0][3] + arr[1][1] + arr[1][3] + arr[2][1] + arr[2][3] + arr[3][1] + arr[3][3]
    if par1 % 2 == 1:
        arr[0][1] = 1

    # Second parity check
    par2 = arr[0][3] + arr[1][2] + arr[1][3] + arr[2][2] + arr[2][3] + arr[3][2] + arr[3][3]
    if par2 % 2 == 1:
        arr[0][2] = 1

    # Third parity check
    par3 = arr[1][1] + arr[1][2] + arr[1][3] + arr[3][0] + arr[3][1] + arr[3][2] + arr[3][3]
    if par3 % 2 == 1:
        arr[1][0] = 1

    # Fourth parity check
    par4 = arr[2][1] + arr[2][2] + arr[2][3] + arr[3][0] + arr[3][1] + arr[3][2] + arr[3][3]
    if par4 % 2 == 1:
        arr[2][0] = 1

    # Set the latest/global parity bit
    tot = 0
    for i1 in arr:
        for i2 in i1:
            tot += i2

    if tot % 2 == 1:
        arr[0][0] = 1

    for x in arr:
        print(x)


if __name__ == '__main__':
    main()
