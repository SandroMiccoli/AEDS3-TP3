#!/usr/bin/python

#Calculate spatial locality from access log.

import sys

locality = {}
prev_address = int(sys.stdin.readline())

for line in sys.stdin:
    address = int(line)
    print prev_address,address
    distance = abs(address - prev_address)
    locality[distance] = locality.get(distance, 0) + 1
    prev_address = address

locality = sorted([(d, a) for d, a in locality.iteritems()])

weight_average = float(sum(d * a for d, a in locality) / float(sum(a for d, a in locality)))

print("# Spatial Locality")
print("# Weighted average %f." % weight_average)
for k, v in locality:
    print("%i\t%i" % (k, v))
