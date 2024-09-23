fn main() {
    let say=String::from("cat");
    print_out(say);

    println!("again: {}",say);//TRYING TO ACCESS A VALUE WHOSE OWNERSHIP IS TRANSFERED TO SOMEONE ELSE
    // HENCE THIS WILL PRINT ERROR

    fn print_out(to_print:String){
        println!("{}",to_print);
    }
}
