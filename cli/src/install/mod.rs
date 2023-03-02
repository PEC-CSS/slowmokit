use std::process::Command;

pub fn install_lib() {
    println!("Install library to device");
    if cfg!(target_os = "windows") {
        // TODO: Windows
    } else {
        Command::new("mkdir")
            .arg("build")
            .spawn()
            .expect("Failed to create a build folder");
        let build_setup = Command::new("cmake")
            .args(["-S", "./", "-B", "build/"])
            .output()
            .expect("cmake command failed.");
        print!("{}", String::from_utf8_lossy(&build_setup.stdout));
        Command::new("cmake")
            .args(["--build", "./build"])
            .spawn()
            .expect("cmake build failed");
        Command::new("sudo")
            .arg("cmake")
            .args(["--install", "./build"])
            .spawn()
            .expect("installation failed");
    }
}
