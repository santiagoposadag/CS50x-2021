import random
participants = []

while True:
    answer = input("Do you want to store data in your list? if YES just type the name, \nif not just answer NO in capital letters ")

    if answer.upper() != "NO":
        participants.append(answer)
    elif answer.upper() == "NO":
        break

print(participants)



while True:
    if len(participants) > 0:
        answer_1 = input("Do you want to get a random name? ")

        if "Y" in answer_1.upper() or "N" in answer_1.upper():
            if "Y" in answer_1.upper():
                n = random.randint(0, (len(participants) - 1))
                print(n)
                print(participants[n])
                participants.pop(n)
            else:
                break
        else:
            print("Only yes or no answer")
    else:
        break


