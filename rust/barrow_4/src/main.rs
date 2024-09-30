
fn main() {
    let mut my_vec=vec![1,2,3];
    println!("{:?}",my_vec);
    add_to_vec(&mut my_vec);
    println!("{:?}",my_vec);
}

fn add_to_vec(a_vec:&mut Vec<i32>){
    a_vec.push(4);
}
