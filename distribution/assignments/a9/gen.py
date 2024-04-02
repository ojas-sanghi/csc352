import random
from typing import Callable
import argparse

generators: list[tuple[int, Callable[[], str]]] = [
    (0, lambda: str(random.randint(1, 100))),
    (2, lambda: "+"),
    (2, lambda: "-"),
    (2, lambda: "-"),
    (2, lambda: "*"),
]


def gen(limit: int):
    arity: int
    f: Callable[[], str]
    if limit <= 1:
        arity, f = generators[0]
    else:
        arity, f = random.choice(generators)
    for _ in range(arity):
        gen(limit - 1)
    print(f())


def main():
    args = parse_args()
    gen(args.maxdepth)


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--maxdepth", type=int, default=3, help="Maximum expression depth"
    )
    return parser.parse_args()


if __name__ == "__main__":
    main()
