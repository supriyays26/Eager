struct Person{                      // struct name shld start with capital letter
    name:String,
    age:u32,
    likes_orange:bool
}




fn main() {
    let person1=Person{                             //creating new instance of struct 
        name:String::from("Adam"),
        age:25,
        likes_orange:true,
    };
    println!("The name of the person is:{}",person1.name);          // using dot notation to access the value of struct
}
