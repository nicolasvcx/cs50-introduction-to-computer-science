from cs50 import get_string


def main():

    text = get_text()
    letters = get_letters(text)
    words = get_words(text)
    sentences = get_sentences(text)
    # We already been gave the formula
    # Since python will store the values as int
    # We have to cast they to floats
    index = 0.0588 * (float(letters) / float(words) * 100) - 0.296 * (float(sentences) / float(words) * 100) - 15.8
    index = round(index)

    if index < 1:
        print("Before Grade 1")
    elif index > 1 and index < 16:
        print("Grade " + str(index))
    elif index > 16:
        print("Grade 16+")


def get_text():

    text = get_string("Text: ")

    return text


def get_letters(text):

    letters = 0
    for i in range(len(text)):
        # Uses the function isalpha to count the words
        if text[i].isalpha():
            letters += 1

    return letters


def get_words(text):

    spaces = 0
    for i in range(len(text)):
        if text[i] == ' ':
            spaces += 1
    # Do direct comparisons to spaces
    # We have to add a +1 to the value because the loops
    # Fail to count the last word
    return spaces + 1


def get_sentences(text):

    sentences = 0
    for i in range(len(text)):
        # Do direct comparissons to . ! and ?
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            sentences += 1

    return sentences


if __name__ == "__main__":
    main()