import sys
import random

MAX_VALUE = 200
TEST_AMOUNT = 200

output = open("output.t", "w")

def main():
    for num in range(TEST_AMOUNT):
        output.write("{}\t{}\t{}\t{}\n".format(random.randint(0,MAX_VALUE),random.randint(0,MAX_VALUE),random.randint(0,MAX_VALUE), random.randint(0,MAX_VALUE)))

    output.close

main()