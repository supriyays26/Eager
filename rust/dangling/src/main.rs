fn main() {
    let mut say = String::from("CA");
    say.push_str("T");
    let say2 = say;
   
    
   println!("{}",say);//here the value of say is move dto say2,hence printing say is invalid
   //if u try to print say2 we wll get the output
}
