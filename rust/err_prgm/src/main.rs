//EXAMPLE

/*fn main() {
    panic!("Farewell");
}
*/





//EXAMPLE TWO
//use std::fs::File;
fn main(){
    
    let fruits=vec!["banana","apple","coconut"];

    let first=fruits.get(0);
    println!("{:?}",first);

    let third=fruits.get(2);
    println!("{:?}",third);

    let non_existence =fruits.get(99);
    println!("{:?}",non_existence);


//let f=File::open("hello.txt").expect("failed to open hello.txt");
}
