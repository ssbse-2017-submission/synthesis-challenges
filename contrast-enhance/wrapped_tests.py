import sys
from subprocess import Popen, PIPE

# sys.argv[1] is the program name
# each test returns a score between 0 and 100

PIXEL_LEVEL_TOLERANCE = 3

def passed(percentage=100):
    return percentage

def failed():
    return 0

## helper functions
def get_output(input_file):
    p = Popen(["limit", sys.argv[1], input_file], 
        stdout=PIPE, stderr=PIPE)
    o, e = p.communicate()
    return o

def get_parsed_output(input_file):
    o = get_output(input_file)
    if len(o) == 0:
        return failed()
    items = o.split()
    if len(items) != 64:
        return failed()
    try:
        items = map(int, items)
        return items
    except ValueError:
        return failed()

def count_out_of_order(l):
    ooo = 0
    for i in xrange(len(l)-1):
        if not (l[i] < l[i+1]):
            ooo += 1
    return ooo

def is_strictly_sorted(l):
    return all(l[i] < l[i+1] for i in xrange(len(l)-1))

def is_sorted(l):
    return all(l[i] <= l[i+1] for i in xrange(len(l)-1))

def equal_within_tolerance(i, j):
    return abs(i-j) <= PIXEL_LEVEL_TOLERANCE

def compare_with_expected(a, b):
    wrong = 0 
    for i in xrange(64):
        if not equal_within_tolerance(a[i], b[i]):
            wrong += 1
    return int(100 - (wrong * 100.0 / 64))

def test_with_expected(a, b):
    for i in xrange(64):
        if not equal_within_tolerance(a[i], b[i]):
            failed()
    passed()

## testing some base formatting and output for input1
def test_1_base_1():
    o = get_output("test_inputs/input1.txt")
    if len(o) == 0:
        return failed()
    else: 
        return passed()

def test_1_base_2():
    o = get_output("test_inputs/input1.txt")
    if len(o) == 0:
        return failed()
    items = o.split()
    if len(items) != 64:
        return failed()
    else: 
        return passed()

def test_1_base_3():
    o = get_output("test_inputs/input1.txt")
    if len(o) == 0:
        return failed()
    items = o.split()
    if len(items) != 64:
        return failed()
    try:
        items = map(int, items)
        return passed()
    except ValueError:
        return failed()

def test_1_base_4():
    o = get_output("test_inputs/input1.txt")
    if len(o) == 0:
        return failed()
    items = o.split()
    if len(items) != 64:
        return failed()
    try:
        items = map(int, items)
        item_set = set(items)
        # typical score = 100 - (wrong pixels * 100/64)
        score = int(100.0 - ((len(item_set) - 1) * 100.0 / 64.0))
        return passed(score)
    except ValueError:
        return failed()

## testing for input2 onwards
def test_2():
    items = get_parsed_output("test_inputs/input2.txt")
    if items == 0:
        return failed()
    item_set = set(items)
    score = int(100.0 - ((len(item_set) - 1) * 100.0 / 64.0))
    return passed(score)

def test_3_v1():
    items = get_parsed_output("test_inputs/input3.txt")
    if items == 0:
        return failed()
    incorrect_pixels = 0
    for i in xrange(0, 8):
        incorrect_pixels += (len(set(items[i*8: (i*8)+8])) - 1)
    return passed(int(100 - (incorrect_pixels * 100.0 / 64.0)))


def test_3_v2():
    items = get_parsed_output("test_inputs/input3.txt")
    if items == 0:
        return failed()
    heads = map(lambda x: items[x*8], range(0, 8))
    wrong = count_out_of_order(heads)
    return passed(int(100 - (wrong * 100.0 / len(heads))))

def test_4_v1():
    items = get_parsed_output("test_inputs/input4.txt")
    if items == 0:
        return failed()
    wrong = 0
    for j in xrange(8):
        for i in xrange(7):
            if not (items[i*8+j] == items[(i+1)*8 +j]):
                wrong += 1
    return passed(int(100 - (wrong * 100.0 / (8*7))))

def test_4_v2():
    items = get_parsed_output("test_inputs/input4.txt")
    if items == 0:
        return failed()
    wrong = count_out_of_order(items[0:8])
    return passed(int(100 - (wrong * 100.0 / 8)))

def test_5_v1():
    items = get_parsed_output("test_inputs/input5.txt")
    if items == 0:
        return failed()
    wrong = 0
    for i in xrange(8):
        wrong += count_out_of_order(items[i*8: (i+1)*8])
    return passed(int(100 - (wrong * 100.0 / 64)))

def test_5_v2():
    items = get_parsed_output("test_inputs/input5.txt")
    if items == 0:
        return failed()
    wrong = 0
    for j in xrange(8):
        wrong += count_out_of_order([items[i*8+j] for i in xrange(8)])
    return passed(int(100 - (wrong * 100.0 / 64)))

def test_6():
    items = get_parsed_output("test_inputs/input6.txt")
    if items == 0:
        return failed()
    wrong = count_out_of_order(items)
    return passed(int(100 - (wrong * 100.0 / 64)))

def test_7():
    items = get_parsed_output("test_inputs/input7.txt")
    if items == 0:
        return failed()
    wrong = count_out_of_order(items)
    return passed(int(100 - (wrong * 100.0 / 64)))

def test_8_v1():
    items = get_parsed_output("test_inputs/input8.txt")
    if items == 0:
        return failed()
    wrong = 0
    for i in xrange(7):
        if not (items[i*8+i] == items[(i+1)*8+i+1]): 
            wrong += 1
    return passed(int(100 - (wrong * 100.0 / 64)))    

def test_8_v2():
    items = get_parsed_output("test_inputs/input8.txt")
    if items == 0:
        return failed()
    items = filter(lambda a: a != items[0], items)
    if len(items) != 56:
        return failed()
    return passed()

def test_8_v3():
    items = get_parsed_output("test_inputs/input8.txt")
    if items == 0:
        return failed()
    items = filter(lambda a: a != items[0], items)
    item_set = set(items)
    if len(item_set) == 0:
        return failed()
    score = int(100.0 - ((len(item_set) - 1) * 100.0 / 64.0))
    return passed(score)

def test_8_v4():
    items = get_parsed_output("test_inputs/input8.txt")
    if items == 0:
        return failed()
    if items[0] < items[1]:
        return passed()
    else:
        return failed()

def test_9_v1():
    items = get_parsed_output("test_inputs/input9.txt")
    if items == 0:
        return failed()
    wrong = 0
    for i in xrange(7):
        if not (items[i*8+i] == items[(i+1)*8+i+1]): 
            wrong += 1
    return passed(int(100 - (wrong * 100.0 / 64))) 

def test_9_v2():
    items = get_parsed_output("test_inputs/input9.txt")
    if items == 0:
        return failed()
    items = filter(lambda a: a != items[0], items)
    if len(items) != 56:
        return failed()
    return passed()

def test_9_v3():
    items = get_parsed_output("test_inputs/input9.txt")
    if items == 0:
        return failed()
    items = filter(lambda a: a != items[0], items)
    item_set = set(items)
    if len(item_set) == 0:
        return failed()
    score = int(100.0 - ((len(item_set) - 1) * 100.0 / 64.0))
    return passed(score)

def test_9_v4():
    items = get_parsed_output("test_inputs/input9.txt")
    if items == 0:
        return failed()
    if items[0] > items[1]:
        return passed()
    else:
        return failed()

def test_10():
    items = get_parsed_output("test_inputs/input10.txt")
    if items == 0:
        return failed()
    expected_output = [243,223,223,223,223,223,223,223,223,255,223,223,223,
        223,223,223,223,223,231,223,223,223,223,223,223,223,223,227,223,223,
        223,223,223,223,223,223,235,223,223,223,223,223,223,223,223,247,223,
        223,223,223,223,223,223,223,239,223,223,223,223,223,223,223,223,251]
    return compare_with_expected(items, expected_output)

def test_11():
    items = get_parsed_output("test_inputs/input11.txt")
    if items == 0:
        return failed()
    expected_output = [31,67,59,91,143,187,223,71,119,31,199,207,87,235,179,
        195,243,107,31,147,223,75,247,167,127,135,51,31,203,171,215,63,99,
        163,243,43,31,39,39,155,255,111,51,211,79,31,123,151,187,191,95,139,
        131,107,31,175,227,235,83,159,115,59,251,31]
    return compare_with_expected(items, expected_output)

def test_12():
    items = get_parsed_output("test_inputs/input12.txt")
    if items == 0:
        return failed()
    expected_output = [3,15,55,95,147,55,75,167,67,35,15,215,235,203,131,159,
        59,35,119,239,251,227,95,167,67,23,155,243,255,231,147,131,99,55,119,
        227,247,211,119,147,191,87,39,147,179,119,23,171,203,155,75,35,15,55,
        87,195,207,191,131,119,87,175,183,219]
    return compare_with_expected(items, expected_output)

def main():
    tests = [test_1_base_1, 
             test_1_base_2, 
             test_1_base_3, 
             test_1_base_4,
             test_2, 
             test_3_v1, 
             test_3_v2, 
             test_4_v1, 
             test_4_v2, 
             test_5_v1, 
             test_5_v2, 
             test_6, 
             test_7, 
             test_8_v1, 
             test_8_v2, 
             test_8_v3, 
             test_8_v4,
             test_9_v1, 
             test_9_v2, 
             test_9_v3, 
             test_9_v4,
             test_10, 
             test_11, 
             test_12]

    scores = [] 
    if len(sys.argv) >= 1:
        for t in tests:
            scores.append(t())
        print "({})".format(" ".join(map(str, scores)))
    else:
        print ""

if __name__ == '__main__':
    main()
