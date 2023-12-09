# TODO
from cs50 import get_int


def main():
    number = -1
    while number < 0:
        number = get_int("Number: ")
    _number = number
    position = 0
    total = 0
    while number:
        position += 1
        if int(position % 2) == 0:
            mod = int(number % 10)
            if int(mod * 2 / 10) > 0:
                total += int(mod * 2 / 10) + int(mod * 2 % 10)
            else:
                total += int(number % 10) * 2
        else:
            total += int(number % 10)
        number = int(number / 10)
    if position < 13 or position > 16 or total % 10 != 0:
        print("INVALID")
    else:
        _count = 1
        for j in range(position - 2):
            _count *= 10
        if position == 15 and (
            int(_number / _count) == 34 or int(_number / _count) == 37
        ):
            print("AMEX")
        elif (position == 13 or position == 16) and (
            int(int(_number / _count) / 10) == 4
        ):
            print("VISA")
        elif position == 16 and (
            int(_number / _count) == 51
            or int(_number / _count) == 52
            or int(_number / _count) == 53
            or int(_number / _count) == 54
            or int(_number / _count) == 55
        ):
            print("MASTERCARD")
        else:
            print("INVALID")


main()
