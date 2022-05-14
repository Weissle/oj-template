import os
import shutil
import time

def element_replace(args,cfg,path):
    with open(path,'r') as f:
        strs = f.readlines()
    with open(path,'w') as f:
        cfg['OJT_NOW_TIME'] = time.strftime('%b.%d.%Y %R')
        for s in strs:
            while True:
                left = s.find('{$')
                right = s.find('$}')
                if left == -1 or right == -1:
                    break
                ele_name_ori = s[left+2:right]
                ele_name = ele_name_ori.strip()
                if ele_name not in cfg:
                    print(f'{ele_name} is not define in config file')
                    break
                else:
                    s=s.replace(s[left:right+2],cfg[ele_name])
            f.write(s)


def help():
    pass


def Create(args,cfg):
    # args [create folder [language]]
    folder = './' + args[1]
    if os.path.exists(folder):
        print(f'Folder {folder} exists.')
        return False

    language = cfg['default-language']
    '''
    if len(args) < 2:
        language = cfg['default-language']
    else:
        language = args[2]
    '''
    
    parameters = ['template','src']

    mp = dict()
    for para in parameters:
        lp = f'{language}-{para}'
        if lp not in cfg:
            print(f'{lp} is required.')
            return False
        mp[para] = cfg[lp]

    src_dir = mp['template']
    main_file = src_dir + '/' + mp['src']
    if not os.path.exists(src_dir):
        print(f'{src_dir} does not exist.')
    if not os.path.exists(main_file):
        print(f'{main_file} does not exist.')
        print('%s does not exist.',main_file)

    shutil.copytree(src_dir,folder)
    element_replace(args,cfg,os.path.join(folder,mp['src']))
    return True
