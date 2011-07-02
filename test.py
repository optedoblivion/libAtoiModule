""" Test """
#!/usr/bin/env python

import libAtoiModule


test_list = [
                "123", 
                "123908318",
                "2343243242",
                "234@324#4",
                "123#2$#223$13413433jffjklsdfjldsjf04jr43j0efj093jf34"
            ]

if __name__=="__main__":
    for item in test_list:
        print (libAtoiModule.stringToInteger(item))
