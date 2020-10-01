import sys
import random

MAX_VALUE = 1000
TEST_AMOUNT = 1000

output = open("output.t", "w")

def main():
    for num in range(TEST_AMOUNT):
        output.write("{}\t{}\t{}\t{}\n".format(random.randint(-MAX_VALUE,MAX_VALUE),random.randint(0,MAX_VALUE),random.randint(-MAX_VALUE,MAX_VALUE), random.randint(0,MAX_VALUE)))

    output.close

main()