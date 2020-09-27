import sys
import random

<<<<<<< HEAD
MAX_VALUE = 1000
TEST_AMOUNT = 1000
=======
MAX_VALUE = 200
TEST_AMOUNT = 200
>>>>>>> 6a0941ffbb77d719fd701141f046f087b07463a2

output = open("output.t", "w")

def main():
    for num in range(TEST_AMOUNT):
<<<<<<< HEAD
        output.write("{}\t{}\t{}\t{}\n".format(random.randint(-MAX_VALUE,MAX_VALUE),random.randint(0,MAX_VALUE),random.randint(-MAX_VALUE,MAX_VALUE), random.randint(0,MAX_VALUE)))
=======
        output.write("{}\t{}\t{}\t{}\n".format(random.randint(0,MAX_VALUE),random.randint(0,MAX_VALUE),random.randint(0,MAX_VALUE), random.randint(0,MAX_VALUE)))
>>>>>>> 6a0941ffbb77d719fd701141f046f087b07463a2

    output.close

main()