
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
    text = input("Text: ")


    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)


    print(f"Letters: {letters}")
    print(f"Words: {words}")
    print(f"Sentences: {sentences}")



    #spaces = sum(c.isspace() for c in text)
    #numbers = sum(c.isdigit() for c in text)
    #print(f"Spaces: {spaces}")
    #print(f"Numbers: {numbers}")


#def user_input():
    #text = input("Text: ")





# any alphabetical character a-z or A-Z is a letter
def count_letters(text):
    letters = sum(c.isalpha() for c in text)
    return letters


# any sequence of characters separated by a space is a word
def count_words(text):
    words = len(text.split())               # split string into a list of words, count length of list
    return words





# any occurrence of . ! ? indicates the end of a sentence
def count_sentences(text):
    sentences = 0
    return sentences


def grade(text):
    grade = 0
    return grade


main()
