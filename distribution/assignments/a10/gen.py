import random
import argparse


def main():
    args = parse_args()
    for _ in range(args.numints):
        print(random.randint(0, 10**args.size))


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--size", type=int, help="Integer size")
    parser.add_argument("--numints", type=int, help="Number of integers")
    return parser.parse_args()


if __name__ == "__main__":
    main()
