#!/usr/bin/python3
import sys

def print_stats(total_size, status_codes):
    """
    Prints the total file size and the count of status codes.
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))

total_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()

        try:
            # File size is the last part
            file_size = int(parts[-1])
            total_size += file_size

            # Status code is the second-to-last part
            status_code = int(parts[-2])

            if status_code in status_codes:
                status_codes[status_code] += 1
        except (IndexError, ValueError):
            # Skip line if it doesn't match the expected format
            continue

        if line_count % 10 == 0:
            print_stats(total_size, status_codes)

except KeyboardInterrupt:
    print_stats(total_size, status_codes)
    raise

print_stats(total_size, status_codes)
