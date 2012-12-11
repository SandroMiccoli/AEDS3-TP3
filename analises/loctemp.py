#!/usr/bin/python

#Calculate temporal locality from access log.

import sys

locality = {}
stack = []
for line in sys.stdin:
    address = int(line)
    if address in stack:
        distance = stack.index(address)
        stack.remove(address)
        stack.insert(0, address)
        locality[distance] = locality.get(distance, 0) + 1
    else:
        stack.insert(0, address)

locality = sorted([(d, a) for d, a in locality.iteritems()])

weight_average = sum(d * a for d, a in locality) / float(sum(a for d, a in locality))

print("# Temporal Locality")
print("# Weighted average %f." % weight_average)
for k, v in locality:
    print("%i \t %i" % (k, v))
