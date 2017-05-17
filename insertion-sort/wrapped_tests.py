'''
    This script generates different test score for insertion sort
'''
import sys
from subprocess import Popen, PIPE

# sys.argv[1] is the program name
# each test returns a score between 0 and 100


## helper functions
def get_output(input_val):
    ''' call the shell '''
    cmd = ["limit", sys.argv[1]] + input_val
    proc = Popen(cmd,
                 stdout=PIPE,
                 stderr=PIPE)
    stdout, _ = proc.communicate()
    return stdout

def get_parsed_output(input_list):
    ''' maps output string to ints '''
    stdout = get_output(input_list)
    items = stdout.split()
    try:
        items = map(int, items)
        return items
    except ValueError:
        return 0


def linear_scan_score(sort_output):
    """
        count the numbers that are out of order
    """
    wrong_order = 0
    total_elem = len(sort_output)
    for i in range(1, total_elem - 1):
        if sort_output[i] > sort_output[i+1]:
            wrong_order += 1

    score = int((total_elem - wrong_order) * 100 / total_elem)
    return score


def get_order_score(sort_output, expected_output):
    """
        @sort_output : the output from sort
        @expected_output : sorted input using python sort routine
        check each pair whether it meets the sort criteria
    """
    # check if its same as ground truth
    if sort_output == expected_output:
        return 100
    # if the length dont match return
    if len(sort_output) != len(expected_output):
        return 0
    # all the elements are retained
    if sorted(sort_output) != expected_output:
        return 0

    # return 100 for set size less than 2
    if len(sort_output) < 2:
        return 100
    wrong_place = 0
    total_elem = len(sort_output)
    total_checks = (total_elem * (total_elem-1))/2
    for i in range(0, total_elem):
        for j in range(i+1, total_elem):
            # i < j then elem_i <= elem_j
            if sort_output[i] > sort_output[j]:
                wrong_place += 1
    return int((total_checks - wrong_place)*100/total_checks)


def test_small():
    ''' test for small list '''
    input_list = [1, 11, 3]
    items = get_parsed_output([str(item) for item in input_list])
    expected_output = sorted(input_list)
    return get_order_score(items, expected_output)


def test_empty():
    ''' test for empty list '''
    input_list = []
    items = get_parsed_output([str(item) for item in input_list])
    expected_output = sorted(input_list)
    return get_order_score(items, expected_output)


def test_negative():
    ''' test on negative random values '''
    input_list = [-2, -4, -1, -10, -5]
    items = get_parsed_output([str(item) for item in input_list])
    expected_output = sorted(input_list)
    return get_order_score(items, expected_output)

def test_mixed():
    ''' use a mixed integers set '''
    input_list = [-28103, -200, -184, -42, -4, 18, 234, 431, 1999, 5355, 6423]
    items = get_parsed_output([str(item) for item in input_list])
    expected_output = sorted(input_list)
    return get_order_score(items, expected_output)


def corner_test_1():
    ''' same numbers '''
    input_list = [1, 1, 1]
    items = get_parsed_output([str(item) for item in input_list])
    expected_output = sorted(input_list)
    return get_order_score(items, expected_output)

def corner_test_2():
    ''' only one number out of range '''
    input_list = [0, 0, 0, 1, 0]
    items = get_parsed_output([str(item) for item in input_list])
    expected_output = sorted(input_list)
    return get_order_score(items, expected_output)

def corner_test_3():
    ''' already sorted number '''
    input_list = [1, 2, 3, 4, 5]
    items = get_parsed_output([str(item) for item in input_list])
    expected_output = sorted(input_list)
    return get_order_score(items, expected_output)

def reverse_sorted_test():
    ''' list sorted in reverse '''
    input_list = [5, 4, 3, 2, 1]
    items = get_parsed_output([str(item) for item in input_list])
    expected_output = sorted(input_list)
    return get_order_score(items, expected_output)


def main():
    ''' main test driver '''
    tests = [
        test_small,
        test_empty,
        test_negative,
        test_mixed,
        corner_test_1,
        corner_test_2,
        corner_test_3,
        reverse_sorted_test,
    ]

    scores = []
    if len(sys.argv) >= 1:
        for test in tests:
            scores.append(test())
        print "({})".format(" ".join(map(str, scores)))
    else:
        print ""

if __name__ == '__main__':
    main()
