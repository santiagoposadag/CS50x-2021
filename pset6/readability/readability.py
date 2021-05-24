
text = input("Text: ")

letters = 0
words = 1
sentences = 0

for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    elif text[i] == " ":
        words += 1
    elif text[i] in [".", "?", "!"]:
        sentences += 1


l = (letters / words) * 100
s = (sentences / words) * 100

readability = 0.0588 * l - 0.296 * s - 15.8

readability = round(readability)

if readability < 1:
    print("Before Grade 1")
elif readability > 16:
    print("Grade 16+")
else:
    print("Grade " + str(readability))
