package tchannels_test

import (
	"fmt"
	"sync"
	"testing"
)

var wg sync.WaitGroup

func sender(ch chan int) {
	fmt.Println("sender start...")
	ch <- 5
	ch <- 4 // stuck here
	wg.Done()
}

func receiver(ch chan int) {
	fmt.Println("receiver starts...")
	i := <-ch
	fmt.Println("receiver receives ", i)
	fmt.Println("receiver ends...")
	wg.Done()
}

func TestChannel(t *testing.T) {
	ch := make(chan int)
	wg.Add(2)
	go sender(ch)
	go receiver(ch)
	wg.Wait()
}
