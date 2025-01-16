use base64::{Engine, prelude::BASE64_STANDARD};

fn convert_hex_to_base64(hex: &str) -> String {
    let hex = hex::decode(hex)
        .expect("Failed to decode hex input");

    BASE64_STANDARD.encode(hex)
}

fn main() {
    let input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    let result = convert_hex_to_base64(input);

    println!("{result}");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_convert_hex_to_base64() {
        let input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
        let expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

        let result = convert_hex_to_base64(input);

        assert_eq!(expected, result);
    }
}