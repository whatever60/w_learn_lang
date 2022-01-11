package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/gorilla/mux"
)

func main() {
	fmt.Println("Hello mod in Go")
	greeter()
	r := mux.NewRouter()
	r.HandleFunc("/", serve_home).Methods("GET")
	log.Fatal(http.ListenAndServe(":4004", r))
}

func greeter() {
	fmt.Println("Hi there")
}

func serve_home(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("<h1>Welcome to my website</h1>"))
}
