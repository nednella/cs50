
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

    letters = sum(c.isalpha() for c in text)
    spaces = sum(c.isspace() for c in text)
    numbers = sum(c.isdigit() for c in text)

    print(f"Letters: {letters}")
    print(f"Spaces: {spaces}")
    print(f"Numbers: {numbers}")


#def user_input():
    #text = input("Text: ")



def count_letters():
    return


def count_words():
    return



def count_sentences():
    return


def grade():
    return


main()
