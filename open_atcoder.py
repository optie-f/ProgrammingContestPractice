import webbrowser as wb
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("contest_name")
parser.add_argument("problems")
args = parser.parse_args()

for suffix in args.problems:
    url = "https://atcoder.jp/contests/{0}/tasks/{0}_{1}".format(args.contest_name, suffix)
    wb.open(url)
