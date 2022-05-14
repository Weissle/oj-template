import os
import sys
from config import ConfigRead,ConfigCheck
from cmd import Create,Help

if __name__ == '__main__':

    cfg = ConfigRead('./ojt.ini')
    if cfg == None :
        print('Error happened when reading the config file')
        exit(1)
    if ConfigCheck(cfg) == False:
        print('There is error exists in config file, please check it')
        exit(1)
    
    mode = 'help' if len(sys.argv) < 2 else sys.argv[1]

    enter = dict({
        'create': Create,
        'help': Help
    })
    
    mode = mode if mode in enter else 'help'

    ok = enter[mode](sys.argv[1:],cfg)
    
    if not ok:
        print('Error occured!')
