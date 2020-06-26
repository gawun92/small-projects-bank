#!/usr/bin/python

import random, sys
import argparse
from optparse import OptionParser

class randline:
    def __init__(self, filename):
        f = open(filename, 'r')
        self.lines = f.readlines()
        f.close()
    def chooseline(self):
        return random.choice(self.lines)
    def listranline(self):
         arr=[]
         numlines = len(self.lines)
         if numlines < 0:
            parser.error("negative count: {0}".
                     format(numlines))
         lines = self.lines[:]
         for index in range(numlines):
            if index <= len(self.lines):
              tempLine=random.choice(range(len(lines)))
              arr.append(lines[tempLine])
              del lines[tempLine]
         return arr

def main():
    version_msg = "%prog 2.0"
    usage_msg = """%prog [OPTION]... FILE

Output randomly selected lines from FILE."""

    parser = OptionParser(version=version_msg,
                          usage=usage_msg)

    parser.add_option("-n", "--head-count",
                      action="store", dest="numlines",
                      help="output at most COUNT lines")
    parser.add_option("-r", "--repeat",
                      action="store_true", dest="rpt",
                      help="output lines can be repeated")
    parser.add_option("-i", "--input-range",
                      action="store", dest="ipr",
                      help="treat each number LO through HI as an input line")
    options, args = parser.parse_args(sys.argv[1:])

################################################################################################################
    if len(args) > 0:         ##  if do process with file

            if options.numlines:                    #  " -n  + number "  command 
                  try:                                #   print numbers of random lines from the file
                      numlines = int(options.numlines)
                  except:                             # catch invalid input : if it is not number
                      parser.error("invalid input : {0}".
                                   format(options.numlines))
                  if numlines < 0:                    # catch invalid input : if it is not positive number
                      parser.error("negative count : {0}".
                                   format(numlines))
                  if len(args) != 1:                  # catch invalid input : if input value is more than one
                      parser.error("wrong number of operands")
                  input_file = args[0]               
                  try:
                      generator = randline(input_file)
                      num = generator.listranline()

                      if len(num) < numlines:           ## if user inserts bigger number than the lines in file
                          for line in num:              ## it is improper
                              sys.stdout.write(line)             
                      else:                             ## if user inserts less number than the lines in file
                          for index in range(numlines): ## it is proper
                              sys.stdout.write(generator.chooseline())
                  except IOError:
                      parser.error("IOError")
                  except:
                      parser.error("Error")

            elif options.rpt:                         ## -r  : keep repeating data from the file (infinite) 
                  try:
                      if len(args) != 1:                    ## there is no number or other command added after -r
                          parser.error("wrong number of operands")
                      generator = randline(args[0])         
                      lineout = generator.listranline()
                      var = int(0)
                      while var != 1:                       ## this is for infinite loop to print recursively
                        ran_num = random.choice(lineout)
                        sys.stdout.write(ran_num)
                  except KeyboardInterrupt:                 ## when C-c to stop working infinite while loop
                      print("")                             ## it helps not to sort error
                  except IOError:
                      parser.error("IOError")
                  except:
                      parser.error("Error")

            elif args[0] == '-':                            ##   "./shuf -"  Enter  is also shoudl work
                  try:
                    lines = sys.stdin.read().splitlines()
                    var = random.shuffle(lines)
                    x=0
                    while x < len(lines):
                      print(lines[x])
                      x+=1
                  except:
                    parser.error("Error")
            elif not options.ipr:
                  try:
                        if len(args) != 1:
                           parser.exceptrror("wrong operands : no other additonal input required")
                        generator = randline(args[0])
                        lineout = generator.listranline()
                        for line in lineout:
                            sys.stdout.write(line)
                  except IOError:
                       parser.error("Error")
            else:
                  parser.error("Error")
################################################################################################################3
    else:       # if do process without file
        if options.ipr and not options.numlines:
              try:
                  if len(args) != 0:                    ## when user inserts data more than "-i LOW-HIGH""
                      parser.error("wrong number of operands")


                  InvalidCheck = (options.ipr.count('-')) ## -  <- this should be only 1 in a string
                  if (InvalidCheck) != 1:
                      parser.error("The format should be  Small number - Big number(or equal)")

                  if (InvalidCheck) == 1:
                    data = (options.ipr).split("-")
                  else:
                    parser.error("should input num-num format")

                  first  = data[0]
                  second = data[1]

                  if len(data) != 2:
                      parser.error("Invalid input format : should be two data")
                  if not first.isdigit(): 
                      parser.error("Invalid input format : first is not digit")
                  if not second.isdigit():
                      parser.error("Invalid input format : second is not digit")
                  if first > second:
                      parser.error("The first number should be bigger or equal")  

                  first = int(first)
                  second = int(second) 

                  temp = list(range(first,second+1))
                  random.shuffle(temp)
                  for line in temp:
                      print(line)
              except:
                  parser.error("Error")
        elif options.numlines:

              if len(args) != 0:                    ## when user inserts data more than "-i LOW-HIGH""
                  parser.error("wrong number of operands")
              if not options.ipr:
                 parser.error("Invalid format")
              InvalidCheck = (options.ipr.count('-')) ## -  <- this should be only 1 in a string
              if (InvalidCheck) != 1:
                  parser.error("The format should be  Small number - Big number(or equal)")

              if (InvalidCheck) == 1:
                data = (options.ipr).split("-")
              else:
                parser.error("should input num-num format")

              first  = data[0]
              second = data[1]

              if len(data) != 2:
                  parser.error("Invalid input format : should be two data")
              if not first.isdigit(): 
                  parser.error("Invalid input format : first is not digit")
              if not second.isdigit():
                  parser.error("Invalid input format : second is not digit")
              if first > second:
                  parser.error("The first number should be bigger or equal")  

              first = int(first)
              second = int(second) 

              temp = list(range(first,second+1))
              #for line in temp:
              var = int(options.numlines)
              x = 0
              while x < var:
                  line = random.choice(temp)
                  print(line)
                  x += 1
        elif len(args) == 0:
            try:
              lines = sys.stdin.read().splitlines()
              var = random.shuffle(lines)
              x=0
              while x < len(lines):
                print(lines[x])
                x+=1
            except:
              parser.error("Error")
        else:
              parser.error("Error")

if __name__ == "__main__":
    main()
