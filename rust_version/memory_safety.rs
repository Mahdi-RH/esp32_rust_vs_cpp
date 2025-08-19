struct Student {
    age: u8,
    name: String,
}

//-----------------used before initialization-----------------------//

fn print_student(student: &Student) {
    println!("Name: {}, Age: {}", student.name, student.age);
}

// pub fn demo_used_before_initialization() {
//     let s: Student; //
//     print_student(&s);
// }

//-----------------------------------------------------------------//

// ---------------------dangling pointer---------------------------//
fn process_data(data: Box<i32>) {
    println!("Processed data:{}", data);
}   

// pub fn demo_dangling_reference() {
//     let a = Box::new(5);
//     process_data(a);
//     println!("Dangling reference: {}", a); // This would cause a compile-time error  
// }   
//-----------------------------------------------------------------//  

// -------------------------raw pointer-----------------------------//
fn demo_raw_pointer() {
    let x = 42;
    let raw: *const i32 = &x;

    unsafe {
        println!("Raw pointer value: {}", *raw);
    }
}
//-----------------------------------------------------------------//