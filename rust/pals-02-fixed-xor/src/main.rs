
fn fixed_xor(a: Vec<u8>, b: Vec<u8>) -> String {
    assert_eq!(a.len(), b.len(), "Inputs must have the same length");

    a
        .iter()
        .zip(b.iter())
        .map(|(&a, &b)| a ^ b)
        .map(|byte| char::from(byte))
        .collect()
}

fn main() {
    let a = hex::decode("1c0111001f010100061a024b53535009181c").unwrap();
    let b = hex::decode("686974207468652062756c6c277320657965").unwrap();

    let result = fixed_xor(a, b);

    println!("{result}");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_fixed_xor() {
        let a = hex::decode("1c0111001f010100061a024b53535009181c").unwrap();
        let b = hex::decode("686974207468652062756c6c277320657965").unwrap();

        let expected: String = hex::decode("746865206b696420646f6e277420706c6179")
            .unwrap()
            .iter()
            .map(|&byte| char::from(byte))
            .collect();

        let result = fixed_xor(a, b);

        assert_eq!(expected, result);
    }
}