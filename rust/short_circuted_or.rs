fn main(){
    let a = true;
    let b = false;
    let c= (a^b) || (a&b);
    println!("c is {}",c);

    let c = (a^b) | panic!();
    println!("c is {}",c);
             }
    
