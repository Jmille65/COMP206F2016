import sys
import string

class Word:
    def __init__(self, newString, stopWordTest):
        self.string = newString
        if stopWordTest is True:
            self.stopWord = True
        else:
            self.stopWord = False

def getCount(self): #used for sorting
    return self.counter

class WordPair:
    def __init__(self, firstWordObj, secondWordObj):
        self.counter = 1
        self.firstWord = firstWordObj.string
        self.secondWord = secondWordObj.string
        if secondWordObj.stopWord is True:
            self.stopPair = True
        else:
            self.stopPair = False

def populateWordList(wordList, targetFile):
    f = open(targetFile)
    wordString = f.read()
    f.close()
    cleanWordString = ""
    wordString = wordString.lower()
    for letter in wordString:
        if letter in string.ascii_letters or letter in string.digits:
            cleanWordString += letter
        if letter is ' ' and cleanWordString is "" or letter is '\n' and cleanWordString is "":
            pass
        elif letter is ' ' or letter is '-' or letter is '\n':
            trueVar = False
            wordList.append(Word(cleanWordString, trueVar))
            cleanWordString = ''
        elif letter is '!' or letter is '.' or letter is '?':
            trueVar = True
            wordList.append(Word(cleanWordString, trueVar))
            cleanWordString = ''
        else:
            pass

def generatePairList(wordList):
    pairList = []
    for i in range(1,len(wordList)):
        for p in pairList:
            if p.firstWord == wordList[i-1].string and p.secondWord == wordList[i].string:
                p.counter += 1
                if wordList[i].stopWord is True:
                    p.stopPair = True
                break
        else:
            pairList.append(WordPair(wordList[i-1], wordList[i]))
    return pairList

if __name__ == "__main__":
    wordList = []
    print "Generating word list... "
    populateWordList(wordList, sys.argv[1])
    print "Generating list of pairs... "
    pairList = generatePairList(wordList)
    print "Sorting pair list... "
    pairList = sorted(pairList, key=getCount, reverse=True)
    #newOut = open(sys.argv[1] + ".list", "w") #optional print to file
    for w in pairList:
        sys.stdout.write(w.firstWord + '-' + w.secondWord + ':' + str(w.counter) + '\n')
        #newOut.write(w.firstWord + '-' + w.secondWord + ':' + str(w.counter) + '\n')
    #newOut.close()
