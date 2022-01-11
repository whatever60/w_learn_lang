package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println("Welcome to tutorial of slices")
	// Without specifying the size of the array, you get a slice, but you need to initialize it.
	// Slice uses array under the hood.
	var fruit_list = []string{} // an empty slice
	fmt.Printf("Type of fruit_list: %T\n", fruit_list)

	// you can add as many elements to the slice, the memory is automatically expanded.
	fruit_list = append(fruit_list, "Apple", "Orange", "Banana")
	fmt.Println(fruit_list)
	fmt.Println(fruit_list[1:])
	fruit_list = append(fruit_list[1:], "Kiwi")
	fmt.Println(fruit_list)

	high_scores := make([]int, 4)
	high_scores[0] = 100
	high_scores[1] = 90
	high_scores[2] = 80
	high_scores[3] = 70
	fmt.Println(high_scores)

	// high_scores[4] = 777 // panic: runtime error: index out of range [4] with length 4
	high_scores = append(high_scores, 60, 50)
	fmt.Println(high_scores)

	sort.Ints(high_scores)
	fmt.Println(high_scores)
	fmt.Println(sort.IntsAreSorted(high_scores))

	var courses = []string{"Go", "Python", "Java"}
	fmt.Println(courses)
	var index int = 2
	// append can also be used to remove elements
	courses = append(courses[:index], courses[index+1:]...)
	fmt.Println(courses)
}
