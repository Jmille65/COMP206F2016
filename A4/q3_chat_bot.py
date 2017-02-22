import sys
import string
import random

class Word:
    def __init__(self, newString, stopWordTest):
        self.string = newString
        if stopWordTest is True:
            self.stopWord = True
        else:
            self.stopWord = False

class WordPair:
    def __init__(self, firstWordObj, secondWordObj):
        self.firstWord = firstWordObj.string
        self.secondWord = secondWordObj.string
        self.stopPair = False
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
        elif letter in string.whitespace and cleanWordString is "":
            pass
        elif letter is '-' or letter in string.whitespace:
            trueVar = False
            wordList.append(Word(cleanWordString, trueVar))
            cleanWordString = ''
        elif letter is '!' or letter is '.' or letter is '?' or letter in string.whitespace:
            trueVar = True
            wordList.append(Word(cleanWordString, trueVar))
            cleanWordString = ''
        else:
            pass

def generatePairList(wordList):
    pairList = []
    for i in range(1,len(wordList)):
        pairList.append(WordPair(wordList[i-1], wordList[i]))
    return pairList

def formulateResponse(prev_word, pairList):
    string_builder = ''
    break_time = False
    for i in range(0,20):
        if i%4 == 0:
            random.shuffle(pairList)
        if break_time is True:
            break
        for p in pairList:
            if prev_word == p.firstWord:
                if i == 0 and p.stopPair == True:
                    continue
                string_builder += p.secondWord + ' '
                prev_word = p.secondWord
                if p.stopPair == True and i > 0:
                    break_time = True
                break
        else:
            if i == 0:
                string_builder += pairList[0].firstWord + ' '
                prev_word = pairList[0].firstWord
            else:
                break_time = True
    string_builder = string_builder.rstrip() + '. '
    string_builder = string_builder.capitalize()
    return string_builder

def chat(pairList):
    #The best text to use is a combo of Salome and Paradise Lost
    while 1:
        clean_user_text = ''
        while clean_user_text == '':
            init_user_text = raw_input('Send:    ')
            init_user_text = init_user_text.lower()
            for c in init_user_text:
                if c not in (string.punctuation + '-'):
                    clean_user_text += c
            if clean_user_text.isspace():
                clean_user_text = ''
        user_text_list = clean_user_text.split()
        print 'Receive: ' + formulateResponse(user_text_list[-1], pairList)


if __name__ == "__main__":
    wordList = []
    for i in range(1,len(sys.argv)):
        populateWordList(wordList, sys.argv[i])
    #in this question, pairList can have duplicates
    #this speeds up reading and makes no changes to the result, but takes up more space
    pairList = generatePairList(wordList)
    chat(pairList)
