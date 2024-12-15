use std::collections::BinaryHeap;

impl Solution {
    pub fn max_average_ratio(classes: Vec<Vec<i32>>, extra_students: i32) -> f64 {
        let mut heap = BinaryHeap::new();
        
        for class in classes.iter() {
            let pass = class[0] as f64;
            let total = class[1] as f64;
            heap.push(Improvement {
                pass,
                total,
                delta: (pass + 1.0) / (total + 1.0) - pass / total,
            });
        }
        
        for _ in 0..extra_students {
            if let Some(mut best) = heap.pop() {
                best.pass += 1.0;
                best.total += 1.0;
                best.delta = (best.pass + 1.0) / (best.total + 1.0) - best.pass / best.total;
                heap.push(best);
            }
        }
        
        let mut sum = 0.0;
        let len = heap.len() as f64;
        
        while let Some(class) = heap.pop() {
            sum += class.pass / class.total;
        }
        
        sum / len
    }
}

#[derive(Copy, Clone)]
struct Improvement {
    pass: f64,
    total: f64,
    delta: f64,
}

impl PartialEq for Improvement {
    fn eq(&self, other: &Self) -> bool {
        self.delta.eq(&other.delta)
    }
}

impl Eq for Improvement {}

impl PartialOrd for Improvement {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        self.delta.partial_cmp(&other.delta)
    }
}

impl Ord for Improvement {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.delta.partial_cmp(&other.delta).unwrap()
    }
}
