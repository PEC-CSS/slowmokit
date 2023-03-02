use std::{fs::File, io::Write};

pub fn write(mut file: File, name: String, type_name: String) {
    let data = format!(
        r#"
#include<slowmokit/{type_name}/{name}.hpp>

int main()
{{
    
    // add example usage here
    return 0;
}}
"#
    );
    file.write_all(data.as_bytes())
        .expect("Error writing example file. Aborted");

    println!("Example file added!")
}