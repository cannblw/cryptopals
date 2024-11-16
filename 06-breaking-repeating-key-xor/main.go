package main

import (
	"encoding/base64"
	"fmt"
	"log"
	"os"
)

func computeHammingDistance(a, b string) int {
	var count int

	for i := 0; i < len(a); i++ {
		diff := int(a[i]) ^ int(b[i])

		for diff > 0 {
			count += diff & 1
			diff >>= 1
		}
	}

	return count
}

func main() {
	f, err := os.ReadFile("./input.txt")
	if err != nil {
		log.Fatalf("Error reading file: %v\n", err)
	}

	decodedSize := base64.StdEncoding.DecodedLen(len(f))
	input := make([]byte, decodedSize)

	_, err = base64.StdEncoding.Decode(input, f)
	if err != nil {
		log.Fatalf("Error decoding from base64 %v\n", err)
	}

	fmt.Println(string(input))

}
