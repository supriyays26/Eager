

//OPTION ENUM PROGRAM


enum Webevent{
    Pageload,
    Pageunload,
    Keypress(char),
    Paste(String),
    Click{x:i64,y:i64},
}

enum Option<T>{
    Some(T),
    None,
}






fn main() {
    let quit= Webevent::Keypress('q');
    let something =Some(1);
    
}
