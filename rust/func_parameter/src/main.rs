fn main() {
    //let mut x = 5;
    //x = plus_one(x);     another way 


    let x = plus_one(5);
    println!("The value of x is:{x}");
}

fn plus_one(x:i32) -> i32 {
    x+1
}