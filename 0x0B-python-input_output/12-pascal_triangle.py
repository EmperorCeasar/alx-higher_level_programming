#!/usr/bin/python3

def pascal_triangle(n):
    if n <= 0:
        return []

    triangle = [[1]]  # First row

    for i in range(1, n):
        prev_row = triangle[-1]
        row = [1]  # First element is always 1

        # Generate the middle elements
        for j in range(1, i):
            row.append(prev_row[j-1] + prev_row[j])

        row.append(1)  # Last element is always 1
        triangle.append(row)

    return triangle
