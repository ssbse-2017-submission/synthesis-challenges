'''
    This script generates different test score for binary search
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
        return items[0]
    except:
        return -1


def check_index_order(bsearch_index, expected_index, list_size):
    """
        check the difference in the index from the expected
        normalize by n, where n is the total elements in the list
    """
    # case where both indicies are negative
    if expected_index == -1 and bsearch_index == -1:
        return 100
    # case where bsearch has not found
    elif expected_index > -1 and bsearch_index < 0:
        return 0
    # case where index is greater than size
    elif bsearch_index >= list_size:
        return 0
    # case where there is difference in index
    diff = 1.0 - float(abs(bsearch_index - expected_index))/float(list_size)
    score = int(diff*100)
    return score

def test_1():
    ''' test '''
    input_list = [10]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = -1
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)


def test_2():
    """ test """
    input_list = [10, 10]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = 0
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)

def test_3():
    """ test """
    input_list = [10, 1, 5, 10]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = 2
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)


def test_4():
    """ test """
    input_list = [10, 4, 10, 50]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = 1
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)


def test_5():
    """ test """
    input_list = [10, 4, 6, 8, 10, 12, 14, 15, 18, 20]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = 3
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)

def test_6():
    """ test """
    input_list = [10, 0, 2, 4, 5, 8, 10, 12, 14, 16]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = 5
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)


def test_7():
    """ test """
    input_list = [10, 0, 1, 2, 3, 4, 5]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = -1
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)


def test_8():
    """ test """
    input_list = [10, 0, 1, 2, 3, 4, 5, 10]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = 6
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)


def test_9():
    """ test """
    input_list = [10, 10, 11, 12, 13, 14, 15]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = 0
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)


def test_10():
    """ test """
    input_list = [10, 0, 1, 2, 3, 4, 5, 6, 10]
    bsearch_index = get_parsed_output([str(item) for item in input_list])
    expected_index = 7
    return check_index_order(bsearch_index, expected_index, len(input_list) - 1)


def main():
    ''' main test driver '''
    tests = [
        test_1,
        test_2,
        test_3,
        test_4,
        test_5,
        test_6,
        test_7,
        test_8,
        test_9,
        test_10
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
