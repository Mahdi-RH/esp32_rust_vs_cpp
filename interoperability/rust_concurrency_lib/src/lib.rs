use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

#[unsafe(no_mangle)]
pub extern "C" fn run_concurrent_threads() {
    let workers_threads_num = 10;
    let shared_data = Arc::new(Mutex::new(String::new()));
    let mut thread_handles = vec![];

    for i in 1..workers_threads_num {
        let shared_data_clone = Arc::clone(&shared_data);
        let handle = thread::spawn(move || {
            let mut data = shared_data_clone.lock().unwrap();
            data.push_str(&format!("Thread {} ran\n", i));
            println!("{}", data);
            thread::sleep(Duration::from_millis(100));
        });
        thread_handles.push(handle);
    }

    for handle in thread_handles {
        handle.join().unwrap();
    }
}
