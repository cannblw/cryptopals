package main

import (
	"encoding/hex"
	"fmt"
)

func Encrypt(input, key string) string {
	keyBytes := []byte(key)
	keyLength := len(keyBytes)

	output := make([]byte, len(input))

	for i := range input {
		c := input[i]
		k := keyBytes[i%keyLength]

		output[i] = c ^ k
	}

	return hex.EncodeToString(output)
}

func main() {
	input := `Burning 'em, if you ain't quick and nimble
I go crazy when I hear a cymbal`
	key := "ICE"

	fmt.Println(Encrypt(input, key))
}
