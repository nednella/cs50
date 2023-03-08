
def main():
    # obtain user input
    text = user_input()

    # determine properties of input string
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # determine grade of string via Coleman-Liau index
    index = cl_index(letters, words, sentences)

    # output grade of string
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        index = int(round(index))                   # round float, then cast to an int
        print(f"Grade {index}")


def user_input():                                   # obtain user input and return if input is non-blank
    while True:
        try:
            text = input("Text: ")
        except ValueError:
            continue
        else:
            if len(text) > 0:
                return text


def count_letters(text):                            # ASSUMPTION: any alphabetical character a-z or A-Z is a letter
    letters = sum(c.isalpha() for c in text)
    return letters


def count_words(text):                              # ASSUMPTION: any sequence of characters separated by a space is a word
    words = len(text.split())                           # split string into a list of words, count length of list
    return words


def count_sentences(text):                          # ASSUMPTION: any occurrence of . ! ? indicates the end of a sentence
    sentences = 0
    sentences += text.count('.')
    sentences += text.count('?')
    sentences += text.count('!')
    return sentences


def cl_index(letters, words, sentences):            # calculate Coleman-Liau index
    L = float(letters / words) * 100                    # L - average no. of letters per 100 words
    S = float(sentences / words) * 100                  # S - average no. of sentences per 100 words
    index = float(0.0588 * L - 0.296 * S - 15.8)        # Coleman-Liau index formula
    return index


main()
