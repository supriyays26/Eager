use std::io;
fn main() {

    let x=1;
    

    match x{                                   //only difference btw if and match is if return boolean type but match can return any type
        1 => println!("one"),
        2 => println!("two"),
        3 => println!("three"),
        4 => println!("four"),
        5 => println!("five"),
        _ => println!("something else"),
    }
}  


/*taking input from user
 println!("enter the value of x:");
    let mut x=String::new();
    io::stdin()
        .read_line(&mut x)
        .expect("failed to read line");

    let x:i32 = x.trim().parse().unwrap();
*/