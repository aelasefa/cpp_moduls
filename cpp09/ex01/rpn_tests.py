import subprocess

tests = [
    "8 9 * 9 - 9 - 9 - 4 - 1 +",
    "1 2 + 3 4 + *",
    "9 1 - 2 * 3 +",
    "7 2 3 * -",
    "4 2 / 3 - 5 *",
    "5 8 + 6 3 - *",
    "9 5 2 + * 8 /",
    "3 3 * 3 * 3 *",
    "2 3 + 4 5 + *",
    "9 8 - 7 6 - *",
    "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +",
    "+",
    "4 +",
    "3 *",
    "9 8 - -",
    "4 5",
    "1 2 3 +",
    "7 8 9 *",
    "2 3 4 +",
    "4 0 /",
    "9 3 - 3 /",
    "8 2 2 - /",
    "a b +",
    "4 x +",
    "hello",
    "4 2 &",
    "@ #",
    "   8     9   *   9 -   9   -   9 - 4   -   1   +",
    "1     2      +      3 4      +      *",
    "",
    "9 9 * 8 8 * + 7 7 * + 6 6 * + 5 5 * + 4 4 * + 3 3 * + 2 2 * + 1 1 * +"
]

def run_test(expr):
    if expr == "":
        expr = "\"\""  # handle empty input gracefully for display
    print(f"Test: {expr}")
    try:
        # Run ./RPN "expr"
        completed = subprocess.run(
            ['./RPN', expr],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            timeout=5
        )
        output = completed.stdout.strip()
        error = completed.stderr.strip()
        if output:
            print(f"Output: {output}")
        if error:
            print(f"Error: {error}")
        if completed.returncode != 0 and not error:
            print("Error: Non-zero exit code with no stderr")
    except Exception as e:
        print(f"Exception: {e}")
    print("-" * 40)

def main():
    for test in tests:
        run_test(test)

if __name__ == "__main__":
    main()

