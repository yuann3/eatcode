impl Solution {
    pub fn is_circular_sentence(sentence: String) -> bool {
       let words: Vec<&str> = sentence.split_whitespace().collect();
        
        if words.len() == 1 {
            let chars: Vec<char> = words[0].chars().collect();
            return chars.first() == chars.last();
        }
        
        words.windows(2).all(|w| {
            w[0].chars().last() == w[1].chars().next()
        }) && words.last().unwrap().chars().last() == words[0].chars().next()

    }
}