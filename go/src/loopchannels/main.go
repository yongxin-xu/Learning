package main

import (
	"fmt"
	"sync"
	"time"
)

type Foo struct {
	str string
	ch  chan string
}

var wg sync.WaitGroup
var foos = []Foo{{"a", make(chan string)}, {"b", make(chan string)}, {"c", make(chan string)}}

func rountinue1() {
	defer wg.Done()
	fmt.Println("R1 sleep 6 seconds")
	time.Sleep(time.Second * 6)
	fmt.Println("R1 write to channel 1")
	foos[0].ch <- "R1"
}

func rountinue2() {
	defer wg.Done()
	fmt.Println("R2 sleep 3 seconds")
	time.Sleep(time.Second * 3)
	fmt.Println("R2 write to channel 2")
	foos[1].ch <- "R2"
}

func rountinue3() {
	defer wg.Done()
	fmt.Println("R3 sleep 9 seconds")
	time.Sleep(time.Second * 9)
	fmt.Println("R3 write to channel 3")
	foos[2].ch <- "R3"
}

func main() {
	wg.Add(6)
	go rountinue1()
	go rountinue2()
	go rountinue3()

	for i, foo := range foos {
		go func(index_ int, foo_ Foo) {
			fmt.Println("Here comes the range", index_)
			str := <-foo_.ch
			fmt.Println("str info:", str)
			wg.Done()
		}(i, foo)

	}

	wg.Wait()
}
