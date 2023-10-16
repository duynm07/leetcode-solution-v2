a = [[1]]
for numRows in range(29):
    new = [1] + [a[-1][i - 1] + a[-1][i] for i in range(1, len(a[-1]))] + [1]
    a.append(new)
    print(f"else if (numRows == {numRows + 2}) return {a};".replace("[", "{").replace("]", "}"))
