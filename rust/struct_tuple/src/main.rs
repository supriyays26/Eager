struct Person{                      // struct name shld start with capital letter
    name:String,
    age:u32,
    likes_orange:bool
}


struct Point2D(u32,u32);                            //tuple type struct

fn main() {
    let person1=Person{                             //creating new instance of struct 
        name:String::from("Adam"),
        age:25,
        likes_orange:true,
    };
    println!("The name of the person is:{}",person1.name);          // using dot notation to access the value of struct
    let origin = Point2D(100,200);

    println!("point contains {} and {}",origin.0,origin.1);

    let Point2D(x,y) = origin;

    println!("point contains {} and {}",x,y);

}