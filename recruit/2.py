import sys

import requests

dp: dict[int, int] = {}


def f(n: int, seed: str, END_POINT: str) -> int:
    if n in dp:
        return dp[n]

    if n == 0:
        dp[n] = 1
    elif n == 2:
        dp[n] = 2
    elif n % 2 == 0:
        # not seen
        dp[n] = (
            f(n - 1, seed, END_POINT)
            + f(n - 2, seed, END_POINT)
            + f(n - 3, seed, END_POINT)
            + f(n - 4, seed, END_POINT)
        )
    else:
        # ask-Sever
        dp[n] = ask_server(seed, n, END_POINT)

    return dp[n]


def ask_server(seed: str, n: int, END_POINT: str):
    params: dict = {"seed": seed, "n": n}
    response: requests.Response = requests.get(END_POINT, params=params, headers={"Content-Type": "application/json"})
    return response.json()["result"]


def main(argv: list):
    if len(argv) != 2:
        print("Usage: python3 2.py <seed> <endpoint>")
        sys.exit(1)

    if argv[0] == "" or argv[1] == "":
        print("argv[0] and argv[1] must not be empty")
        sys.exit(1)

    if type(argv[0]) != str or not argv[1].isdecimal():
        print("argv[0] is str, argv[1] is int is required")
        print(type(argv[0]), argv[1])
        sys.exit(1)

    seed: str = argv[0]
    n: int = int(argv[1])

    END_POINT: str = "https://challenge-server.code-check.io/api/recursive/ask"

    print(f(n, seed, END_POINT))


if __name__ == "__main__":
    main(sys.argv[1:])
