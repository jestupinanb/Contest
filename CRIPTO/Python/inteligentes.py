import sys
import re
import numpy as np


def pos_title(data, col, title):
    pos_target = 0
    for i in range(col):
        if data[0][i] == title:
            pos_target = i
    return pos_target


def parameters_true(data, title, value):
    row = len(data)
    col = len(data[0])

    pos_target = pos_title(data, col, title)

    sol = np.array([data[0]])
    for i in range(1, row):
        if value == data[i][pos_target]:
            sol = np.concatenate((sol, [data[i]]))
    return sol


def possible_values(data, title):
    row = len(data)
    col = len(data[0])
    pos_target = pos_title(data, col, title)
    values = set()
    for i in range(1, row):
        values.add(data[i][pos_target])
    return values


# lines = sys.stdin.readlines()
file1 = open('in.txt', 'r')
lines = file1.readlines()

data = []
columns = 0
row = 0
for line in lines:
    col = [x.lower() for x in line.split()]
    columns = len(col)
    data += col
    row += 1
data = np.array(data)
data = data.reshape(row, columns)

'''print("Queries")'''
# lines = sys.stdin.readlines()
file1 = open('q.txt', 'r')
lines = file1.readlines()
queries = {}
class_query = ""

for line in lines:
    dic_data = line.split()
    if len(dic_data) == 2:
        queries[dic_data[0].lower()] = dic_data[1].lower()
    else:
        class_query = dic_data[0].lower()

pos_values = possible_values(data, class_query)

cases_probability = {}

for value in pos_values:
    solution = 1.0
    b = parameters_true(data, class_query, value)
    b_val = len(b) - 1
    p_b = b_val / (row - 1)  # todo be sure if is always the number of rows
    for key in queries:
        ab = parameters_true(b, key, queries[key])
        ab_val = len(ab) - 1
        solution *= ab_val / b_val
    cases_probability[value] = solution * p_b
    print(f"P(query|{value})={solution}")
    print(f"P(query|{value})*P({value})={cases_probability[value]}\n")

name_case = ""
max_case = -1  # todo: verify possible error, negative are always slower (? I think because it is a probability

for key in cases_probability:
    if cases_probability[key] > max_case:
        name_case = key
        max_case = cases_probability[key]
print("Final result:\nClass=", name_case)
