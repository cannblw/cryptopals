package main

import (
	"encoding/hex"
	"fmt"
	"log"
)

func main() {
	inputA := "1c0111001f010100061a024b53535009181c"
	a, err := hex.DecodeString(inputA)
	if err != nil {
		log.Fatalln("Error converting input to bytes")
	}

	inputB := "686974207468652062756c6c277320657965"
	b, err := hex.DecodeString(inputB)
	if err != nil {
		log.Fatalln("Error converting input to bytes")
	}

	// a and b have the same length
	length := len(a)

	outputBytes := make([]byte, length)

	for i := range length {
		outputBytes[i] = a[i] ^ b[i]
	}

	fmt.Println(hex.EncodeToString(outputBytes))
}
