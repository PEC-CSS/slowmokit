mod write_docs;
mod write_example;
mod write_source;

use std::fs;

pub fn write_files(model_name: String, model_type: String) {
    let methods_folder = "output/slowmokit/methods";
    let examples_folder = "examples";
    let docs_folder = "docs";

    fs::create_dir_all(format!("{methods_folder}/{model_type}/{model_name}"))
        .expect("An Error occured while creating source code folder!");
    fs::create_dir_all(format!("{examples_folder}/{model_type}"))
        .expect("An Error occured while creating examples directory.");
    fs::create_dir_all(format!("{docs_folder}/{model_type}"))
        .expect("An Error occured while creating docs directory.");

    // source code files
    let _easy_import_file = fs::File::create(format!("{methods_folder}/{model_type}/{model_name}.hpp"))
        .expect("Error encountered while creating file!");
    let _header_file = fs::File::create(format!(
        "{methods_folder}/{model_type}/{model_name}/{model_name}.hpp"
    ))
    .expect("Error encountered while creating file!");
    let _imple_file = fs::File::create(format!(
        "{methods_folder}/{model_type}/{model_name}/{model_name}.cpp"
    ))
    .expect("Error encountered while creating file!");

    // docs files
    let _docs_file = fs::File::create(format!("{docs_folder}/{model_type}/{model_name}.md"))
        .expect("Error encountered while creating file!");

    // examples files
    let _examples_file = fs::File::create(format!("{examples_folder}/{model_type}/{model_name}.cpp"))
        .expect("Error encountered while creating file!");

    // time to write files
    write_example::write(_examples_file, model_name.to_owned(), model_type.to_owned());
    write_docs::write(_docs_file, model_name.to_owned(), model_type.to_owned());
    write_source::write_easy_import(_easy_import_file, model_name.to_owned(), model_type.to_owned());
    write_source::write_cpp(_imple_file, model_name.to_owned(), model_type.to_owned());
    write_source::write_hpp(_header_file, model_name.to_owned(), model_type.to_owned());

    println!("File structure created succesfully!");
}
