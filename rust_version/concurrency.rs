use std::thread;
use std::sync::{Arc, Mutex};
use std::time::Duration;

pub fn demo_thread_safe() {
 let workers_threads_num = 10;
    
    let shared_data = Arc::new(Mutex::new(String::new()));
    let mut thread_handles = vec![];

    for i in 1..workers_threads_num {
        let shared_data_clone = Arc::clone(&shared_data);
        let handle = thread::spawn(move || {
            let mut data= shared_data_clone.lock().unwrap();
            data.push_str(&format!("Thread {} ran\n", i));
            print!("{}", data);
            thread::sleep(Duration::from_millis(100));
        });
        thread_handles.push(handle);
    }
    for handle in thread_handles {
        handle.join().unwrap()
    }
}

// pub fn demo_rece_condition() {
//  let workers_threads_num = 10;
    
//     let shared_data = Rc::new(Mutex::new(String::new()));
//     let mut thread_handles = vec![];

//     for i in 1..workers_threads_num {
//         let shared_data_clone = Arc::clone(&shared_data);
//         let handle = thread::spawn(move || {
//             let mut data= shared_data_clone.lock().unwrap();
//             data.push_str(&format!("Thread {} ran\n", i));
//             print!("{}", data);
//             thread::sleep(Duration::from_millis(100));
//         });
//         thread_handles.push(handle);
//     }
//     for handle in thread_handles {
//         handle.join().unwrap()
//     }
// }

pub fn demo_deadlock() {
    println!("Starting deadlock demo");

    let mtx1 = Arc::new(Mutex::new(()));
    let mtx2 = Arc::new(Mutex::new(()));

    let m1 = Arc::clone(&mtx1);
    let m2 = Arc::clone(&mtx2);
    let t1 = thread::spawn(move || {
        let _lock1 = m1.lock().unwrap();
        thread::sleep(Duration::from_millis(100));
        let _lock2 = m2.lock().unwrap();
    });

    let m1 = Arc::clone(&mtx1);
    let m2 = Arc::clone(&mtx2);
    let t2 = thread::spawn(move || {
        let _lock2 = m2.lock().unwrap();
        thread::sleep(Duration::from_millis(100));
        let _lock1 = m1.lock().unwrap();
    });

    t1.join().unwrap();
    t2.join().unwrap();
}

fn main() {
   demo_thread_safe();
}