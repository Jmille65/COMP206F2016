import sys
import math
import threading
import multiprocessing
import time

start = time.time()

numToFactor = int(sys.argv[1])
factorUntil = numToFactor/2 + 1

class primeSolver(multiprocessing.Process):
    def __init__(self, threadID, toIncrementBy, factorUntil, start, name):
        multiprocessing.Process.__init__(self)
        self.name = name
        self.threadID = threadID
        self.toIncrementBy = toIncrementBy
        self.factorUntil = factorUntil
        self.numToCheck = start
    def run(self):
        while self.numToCheck < self.factorUntil:
            factor(self.numToCheck)
            self.numToCheck += self.toIncrementBy
def factor(intToCheck):
    if numToFactor%intToCheck == 0:
        print (intToCheck)

thread1 = primeSolver(1, 4, factorUntil, 1, "thread1")
thread2 = primeSolver(2, 4, factorUntil, 2, "thread2")
thread3 = primeSolver(3, 4, factorUntil, 3, "thread3")
thread4 = primeSolver(4, 4, factorUntil, 4, "thread4")

thread1.start()
thread2.start()
thread3.start()
thread4.start()

thread1.join()
thread2.join()
thread3.join()
thread4.join()

print (time.time() - start)
