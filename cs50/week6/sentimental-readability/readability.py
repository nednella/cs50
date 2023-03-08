
# program outline

# prompt user for an entry of text
# output the grade level for the text - following Coleman-Liau index
    # count the number of letters
        # can assume a letter is lowercase A to Z, or uppercase A to Z
    # count the number of words
        # any sequence of characters separated by a space dictates the end of a word
    # count the number of sentences
        # can assume any occurence of . ! ? dictates the end of a sentence




def main():
    # obtain user input
    text = user_input()

    # determine properties of input string
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # determine grade via Coleman-Liau index
    index = cl_index(letters, words, sentences)

    #print(f"Letters: {letters}")
    #print(f"Words: {words}")
    #print(f"Sentences: {sentences}")

    # output text grade
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        index = int(round(index))               # round float, then cast to an int
        print(f"Grade {index}")


def user_input():                               # obtain input and return if input is non-blank
    while True:
        try:
            text = input("Text: ")
        except ValueError:
            continue
        else:
            if len(text) > 0:
                return text


def count_letters(text):                        # ASSUMPTION: any alphabetical character a-z or A-Z is a letter
    letters = sum(c.isalpha() for c in text)
    return letters


def count_words(text):                          # ASSUMPTION: any sequence of characters separated by a space is a word
    words = len(text.split())                   # split string into a list of words, count length of list
    return words


def count_sentences(text):                      # ASSUMPTION: any occurrence of . ! ? indicates the end of a sentence
    sentences = 0
    sentences += text.count('.')
    sentences += text.count('?')
    sentences += text.count('!')
    return sentences


def cl_index(letters, words, sentences):        # calculate Coleman-Liau index
    L = float(letters / words) * 100
    S = float(sentences / words) * 100
    index = float(0.0588 * L - 0.296 * S - 15.8)
    return index


main()
