import argparse
parser = argparse.ArgumentParser()
parser.add_argument("contest_name")
parser.add_argument("problems")
args = parser.parse_args()

temp = './boilerplate.cpp'

with open(temp, mode='r') as tf:
    template = tf.read()
    for suffix in args.problems:
        path = './{0}_{1}.cpp'.format(args.contest_name, suffix)
        with open(path, mode='w') as f:
            f.write(template)
