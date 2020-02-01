contest_name = input("contest name:")
suffices = input("problem(s):")
temp = './template.cpp'

with open(temp, mode='r') as tf:
    template = tf.read()
    for suffix in suffices:
        path = './{0}_{1}.cpp'.format(contest_name, suffix)
        with open(path, mode='w') as f:
            f.write(template)
