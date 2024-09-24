fn main() {

    let mut i=1;
   
    let something=loop{
        i *= 2;
        if i>100{
            
            break i;
        }println!("the value of i is:{i}");
    };
    println!("the value of i is:{i}");
    
    assert_eq!(something,128);
}
