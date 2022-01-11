package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fmt.Println("Welcome to out pizza shop")
	fmt.Println("Please rate our pizza between 1 and 10")

	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	fmt.Println("Thanks for your rating,  ", input)
	num_rate, err := strconv.ParseFloat(strings.TrimSpace(input), 64)
	if err != nil {
		fmt.Println("Error: ", err)
	} else {
		fmt.Println("Your rating (1 added) is: ", num_rate + 1)
	}
}
