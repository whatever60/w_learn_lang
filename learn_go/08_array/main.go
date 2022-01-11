package main

import "fmt"

func main() {
	fmt.Println("Welcome to array in golang")
	var fruit_list [4]string
	fruit_list[0] = "Apple"
	fruit_list[1] = "Orange"
	fruit_list[3] = "Banana"
	fmt.Println("Fruit list is: ", fruit_list)
	fmt.Println("Number of fruits: ", len(fruit_list))

	var veg_list = [5]string{"Carrot", "Potato", "Tomato"}
	fmt.Println("Vegy list is: ", veg_list)
}
