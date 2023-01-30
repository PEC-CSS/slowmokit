mod write_example;
mod write_docs;
mod write_source;

use std::fs::create_dir_all;
use std::fs::File;
use std::io::stdin;
use std::io::stdout;
use std::io::Write;

fn main() {
    let stdin = stdin();
    let mut stdout = stdout();
    
    let mut name_buffer = String::new();
    println!("You need to enter the name of model in snake case. For example if you want to write \"Linear Regression\", write \"linear_regression\"");
    print!("Enter the Name of model: ");
    stdout.flush().unwrap();
    stdin.read_line(&mut name_buffer).expect("An error occured!");
    let model_name = name_buffer.trim();

    let mut type_buffer = String::new();
    print!("Enter the type of model. \n Supported types are: \n 1. linear_model \n 2. cluster \n 3. neighbors \n 4. svm \n");
    print!("Select one from above (you need to write full name.) \n");
    stdout.flush().unwrap();
    stdin.read_line(&mut type_buffer).expect("An error occured!");
    let model_type = type_buffer.trim();

    if model_type!="linear_model" && model_type!="cluster" && model_type!="neighbors" && model_type!="svm" {
        panic!("Please use the supported types only");
    }


    let methods_folder = "src/slowmokit/methods";
    let examples_folder = "examples";
    let docs_folder = "docs";

    create_dir_all(format!("{methods_folder}/{model_type}/{model_name}"))
        .expect("An Error occured while creating source code folder!");
    create_dir_all(format!("{examples_folder}/{model_type}"))
        .expect("An Error occured while creating examples directory.");
    create_dir_all(format!("{docs_folder}/{model_type}"))
        .expect("An Error occured while creating docs directory.");

    // source code files
    let _easy_import_file = File::create(format!("{methods_folder}/{model_type}/{model_name}.hpp"))
        .expect("Error encountered while creating file!");
    let _header_file = File::create(format!(
        "{methods_folder}/{model_type}/{model_name}/{model_name}.hpp"
    ))
    .expect("Error encountered while creating file!");
    let _imple_file = File::create(format!(
        "{methods_folder}/{model_type}/{model_name}/{model_name}.cpp"
    ))
    .expect("Error encountered while creating file!");

    // main file


    // docs files
    let _docs_file = File::create(format!("{docs_folder}/{model_type}/{model_name}.md"))
        .expect("Error encountered while creating file!");

    // examples files
    let _examples_file = File::create(format!("{examples_folder}/{model_type}/{model_name}.cpp"))
        .expect("Error encountered while creating file!");

    // time to write files
    write_example::write(_examples_file, model_name.to_owned(), model_type.to_owned());
    write_docs::write(_docs_file, model_name.to_owned(), model_type.to_owned());
    write_source::write_easy_import(_easy_import_file, model_name.to_owned(), model_type.to_owned());
    write_source::write_cpp(_imple_file, model_name.to_owned(), model_type.to_owned());
    write_source::write_hpp(_header_file, model_name.to_owned(), model_type.to_owned());

    println!("File structure created succesfully!");
    println!("{}", format!("Note: You need to add #include \"slowmokit/methods/{model_type}/{model_name}.hpp\" in slowmokit/slowmokit.hpp"));
}
