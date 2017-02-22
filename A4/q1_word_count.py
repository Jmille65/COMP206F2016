import sys
import string

class Word:
    def __init__(self, newString):
        self.counter = 1
        self.string = newString

def newWord(newString, wordList):
    for w in wordList:
        if w.string == newString:
            w.counter += 1
            break
    else:
        wordList.append(Word(newString))

def getCount(self): #used for sorting
    return self.counter

def populateWordList(wordList, targetFile):
    f = open(targetFile)
    wordString = f.read()
    f.close()
    cleanWordString = ""
    for letter in wordString:
        if letter is '-':
            cleanWordString += ' '
        if letter not in (string.punctuation + '-'): #Ellipsis is a standard punctuation character, but not in ASCII.
            cleanWordString += letter #The West Wing taught me that. Get it together, ANSI.
    cleanWordString = cleanWordString.lower()
    uncountedWordList = cleanWordString.split()
    for w in uncountedWordList:
        newWord(w, wordList)

if __name__ == "__main__":
    wordList = []

    populateWordList(wordList, sys.argv[1])

    wordList = sorted(wordList, key=getCount, reverse=True)
    #newOut = open(sys.argv[1] + ".list", "w") #optional print to file
    for w in wordList:
        sys.stdout.write(w.string + ':' + str(w.counter) + '\n')
        #newOut.write(w.string + ':' + str(w.counter) + '\n')
    #newOut.close()
