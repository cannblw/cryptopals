package main

import (
	"encoding/hex"
	"fmt"
	"log"
)

func findKey() {
	input, err := hex.DecodeString("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736")
	if err != nil {
		log.Fatalln("Error converting input to bytes")
	}

	for i := range 255 {
		currentByte := byte(i)

		currentResult := make([]byte, len(input))
		for j := range input {
			currentResult[j] = input[j] ^ currentByte
		}

		fmt.Printf("%d => %s\n", currentByte, string(currentResult))
	}
}

func main() {
	// Result: 88 => Cooking MC's like a pound of bacon
	// Can't be bother to do frequency analysis
	findKey()
}
