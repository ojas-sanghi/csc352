import random
import argparse


def main():
    args = parse_args()
    lines = args.lines
    for _ in range(lines):
        s = ""
        words = random.randint(0, args.words)
        for _ in range(words):
            n = random.randint(0, args.max)
            print(n, end=" ")
        print()


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--seed", type=int, default=0, help="Random seed")
    parser.add_argument("--max", type=int, default=40, help="max")
    parser.add_argument("--lines", type=int, default=40, help="Number of lines")
    parser.add_argument("--words", type=int, default=20, help="Number of words")
    parser.add_argument("--length", type=int, default=8, help="Length of words")
    parser.add_argument("--spaces", type=int, default=4, help="Number of spaces")
    parser.add_argument(
        "--newlines", type=int, default=0, help="Number of extra newlines"
    )
    parser.add_argument(
        "--alphabet", type=str, default="abcdefghijklmnopqrstuvwxyz", help="Alphabet"
    )
    parser.add_argument("--tabs", type=int, default=0, help="Number of tabs")
    return parser.parse_args()


if __name__ == "__main__":
    main()
