card = input("Number: ")

spotMultiplied = len(card) - 2
spotNonMultiplied = len(card) - 1


sumMultiplied = 0
sumNonMultiplied = 0

while spotMultiplied >= 0:
    number = int(card[spotMultiplied]) * 2
    if number > 9:
        number = str(number)
        number_1 = int(number[0])
        number_2 = int(number[1])
        sumMultiplied = sumMultiplied + number_1 + number_2
    else:
        sumMultiplied = sumMultiplied + number
    spotMultiplied -= 2

while spotNonMultiplied >= 0:
    number = int(card[spotNonMultiplied])
    sumNonMultiplied = sumNonMultiplied + number
    spotNonMultiplied -= 2

result = sumMultiplied + sumNonMultiplied

if (result % 10) == 0:
    if len(card) == 15:
        start = card[0] + card[1]
        start = int(start)
        if start == 34 or start == 37:
            print("AMEX")
    elif len(card) == 16:
        start = card[0] + card[1]
        start = int(start)
        if start in [51, 52, 53, 54, 55]:
            print("MASTERCARD")
        elif int(card[0]) == 4:
            print("VISA")
    elif len(card) == 13:
        if card[0] == 4:
            print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")

