package main

import (
	"fmt"
	//"strings"
	"ojt/config"
	"ojt/cmd"
	"os"

)

func main() {
	cfg := config.ConfigRead("./ojt.ini")
	if cfg == nil {
		fmt.Println("Error happened when reading the config file")
		return
	}
	if !config.ConfigCheck(cfg) {
		fmt.Println("There is error exists in config file, please check it")
		return
	}
	
	var mode string
	var ok bool

	if len(os.Args) > 1 {
		mode = os.Args[1]
	} else {
		mode = "help"
	}

	switch mode {
		case "help":
			ok = cmd.Help()
		case "create":
			ok = cmd.Create(os.Args[1:])
		default:
			ok = cmd.Help()
	}
	if !ok {
		fmt.Println("Error occured!")
	}
}
