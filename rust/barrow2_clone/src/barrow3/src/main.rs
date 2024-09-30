fn main() {
    let say =String::from("Cat");
    print_out(&say);
    println!("again:{}",say);

}

fn print_out(to_print: &String){
   println!("{}",to_print);
}
