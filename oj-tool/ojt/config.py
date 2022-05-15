import os

def ConfigRead(cfg_path) :
    if '~' in cfg_path:
        cfg_path = os.path.expanduser(cfg_path)
    if not os.path.exists(cfg_path):
        return None
    file = open(cfg_path, 'r')
    cfg = dict()

    for line in file:
        line = line.strip()
        if len(line) == 0 or line[0] == ';' :
            continue
        eq_symbol_pos = line.index('=')
        if eq_symbol_pos == -1 :
            print("We need k=v format but get ", line)
            return None
        k,v = line[:eq_symbol_pos],line[eq_symbol_pos+1:]
        cfg[k] = v
    return cfg


def print_if_not_exist(cfg,key) :
    if key not in cfg:
        print(f'The key {key} is necessary but ojt cannot find it in the config.')
        return False
    return True

def ConfigCheck(cfg):
    ret = True
    ret = ret and print_if_not_exist(cfg,"username")
    return ret
