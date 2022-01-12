import pandas as pd

operators = []
operands = []
output = {}
precedence = {'$':0, '=':1, '-':2, '+':2, '*':3, '/':3}
op = ['=', '+', '-', '*', '/']
temp_var = ['t0', 't1', 't2', 't3', 't4', 't5', 't6', 't7', 't8', 't9']
k = 0
expression = input("Enter the expression: ")
operators.append('$')
for i in expression:
    if i not in op:
        operands.append(i)
    elif precedence[operators[-1]] <= precedence[i]:
        operators.append(i)
    else:
        if operators[-1] != '=':
            output[temp_var[k]] = {}
            output[temp_var[k]]['op'] = operators.pop()
            operators.append(i)
            temp = operands.pop()
            output[temp_var[k]]['arg1'] = operands.pop()
            output[temp_var[k]]['arg2'] = temp
            operands.append(temp_var[k])
            k += 1
        else:
            temp = operands.pop()
            output[operands.pop()] = {'op':operators.pop(), 'arg1':temp, 'arg2':''}
while operators[-1] != '$':
    if operators[-1] != '=':
        output[temp_var[k]] = {}
        output[temp_var[k]]['op'] = operators.pop()
        temp = operands.pop()
        output[temp_var[k]]['arg1'] = operands.pop()
        output[temp_var[k]]['arg2'] = temp
        operands.append(temp_var[k])
        k += 1
    else:
        temp = operands.pop()
        output[operands.pop()] = {'op':operators.pop(), 'arg1':temp, 'arg2':''}

print("Intermediate code generated")
output_table = pd.DataFrame(output)
print(output_table.transpose())
