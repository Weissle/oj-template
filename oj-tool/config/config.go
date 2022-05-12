package config

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func ConfigRead(cfg_path string) map[string]string{
	var file, err = os.Open(cfg_path)
	if err != nil {
		fmt.Println(err.Error())
		return nil
	}
	defer file.Close()

	var cfg = make(map[string]string)

	var scanner = bufio.NewScanner(file)
	for scanner.Scan() {
		var line = scanner.Text()
		line = strings.TrimSpace(line)
		if len(line) == 0 || line[0] == ';' {
			continue
		}
		var eq_symbol_pos = strings.Index(line,"=")
		if eq_symbol_pos == -1 {
			fmt.Println("We need k=v format but get ", line)
			return nil
		}
		var k,v = line[:eq_symbol_pos],line[eq_symbol_pos+1:]
		cfg[k] = v
	}
	return cfg
}


func print_if_not_exist(cfg map[string]string, key string) bool{
	if _,ok := cfg[key]; !ok {
		fmt.Println("The key ",key," is necessary but ojt cannot find it in the config.")
		return false
	}
	return true
}

func ConfigCheck(cfg map[string]string) bool{
	ret := true
	ret = ret && print_if_not_exist(cfg,"username")
	return ret
}
