fn main() {
     let say =String::from("Cat");
     print_out(say);                            //this line creates an error as the ownership shld be one function .but hr it is moving its ownership
     println!("again:{}",say);

}

fn print_out(to_print: String){
    println!("{}",to_print);
}
