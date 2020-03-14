import argparse
parser = argparse.ArgumentParser()
parser.add_argument("filename")
args = parser.parse_args()

with open(args.filename) as f:
    lines = f.readlines()
    for line in lines:
        print('"{}",'.format(line.rstrip('\n')))
