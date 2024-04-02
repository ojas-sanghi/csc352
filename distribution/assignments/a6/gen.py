import random


def frame() -> tuple[int, int]:
    firsts = [random.randint(0, 10) for _ in range(3)]
    first = max(firsts)
    print(first)
    total = first
    if first < 10:
        seconds = [random.randint(0, 10 - first) for _ in range(3)]
        second = max(seconds)
        print(second)
        total += second
    return first, total


def gen():
    first: int = 0
    total: int = 0
    for _ in range(10):
        first, total = frame()
    if first == 10:
        ball = random.randint(0, 10)
        print(ball)
        if ball == 10:
            ball = 0
        ball = random.randint(0, 10 - ball)
        print(ball)
    elif total == 10:
        ball = random.randint(0, 10)
        print(ball)


def main():
    gen()


if __name__ == "__main__":
    main()
