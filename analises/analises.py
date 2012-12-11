#!/usr/bin/python
# -*- coding: latin-1 -*-

import sys

fin=open("analise2.txt","r")
analises=fin.readlines()
fin.close()

for i in range(len(analises)):
    #print analises[i].split()
    print i
    #for j in analises[i].split():
    #   print j

