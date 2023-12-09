# TODO
from cs50 import get_float


def get_cents():
    cents = -1
    while cents < 0:
        cents = get_float("Change owed: ")
        cents = cents * 100
    return cents


def calculate_quarters(cents):
    return int(cents / 25)


def calculate_dimes(cents):
    return int(cents / 10)


def calculate_nickels(cents):
    return int(cents / 5)


def calculate_pennies(cents):
    return int(cents)


def main():
    cents = get_cents()
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1
    coins = quarters + dimes + nickels + pennies
    print("\n", coins)


main()
