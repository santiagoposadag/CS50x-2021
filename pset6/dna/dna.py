import sys
import csv


def main():

    if len(sys.argv) != 3:
        print("Unapropiate use of the program, input the complete comand line arguments")
        sys.exit(1)

    # here we load into memory the people that we have registered
    people = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            people.append(row)

    # here te proteins that we are going to be looking for
    tmpProteins = []
    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        tmpProteins = next(reader)
    tmpProteins.remove("name")

    proteins = {}
    for i in range(len(tmpProteins)):
        proteins[tmpProteins[i]] = 0

    # And here we load the sequence of DNA that we are going to check.
    sequence = ""
    with open(sys.argv[2], "r") as file:
        reader = csv.reader(file)
        table = next(reader)

    sequence = table[0]

    for i in range(len(tmpProteins)):
        currentSTR = tmpProteins[i]

        counter = 0
        counting = False
        m = 0
        for j in range(m, (len(sequence))):
            k = m + len(currentSTR)
            s = sequence[m:k]
            if s == currentSTR:
                counter += 1
                m = k
                counting = True
            elif counting == True:
                counting = False
                if counter > proteins[currentSTR]:
                    proteins[currentSTR] = counter
                    counter = 0
                    m += 1
            else:
                m += 1
                counter = 0

    # print(people)
    # print(proteins)

    for i in range(len(people)):
        indicator = False

        for j in range(len(tmpProteins)):
            x = people[i][tmpProteins[j]]
            y = proteins[tmpProteins[j]]
            if int(people[i][tmpProteins[j]]) == proteins[tmpProteins[j]]:
                indicator = True

            elif int(people[i][tmpProteins[j]]) != proteins[tmpProteins[j]]:
                indicator = False
                break

        if indicator == True:
            print(people[i]["name"])
            sys.exit(0)

    print("No match")


main()