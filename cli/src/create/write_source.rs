use std::{fs::File, io::Write};

pub fn write_easy_import(mut file: File, name: String, type_name: String) {
    let uppercase_name = name.to_uppercase();
    let data = format!(
        r#"
/**
 * @file {type_name}/{name}.hpp
 * 
 * Convenience include for {name} algorithm.
 */

#ifndef SLOWMOKIT_{uppercase_name}_HPP
#define SLOWMOKIT_{uppercase_name}_HPP

#include "{name}/{name}.hpp"

#endif // SLOWMOKIT_{uppercase_name}_HPP
"#
    );
    file.write_all(data.as_bytes())
        .expect("Error creating files.");

    println!("Easy import file added!");
}

fn pascal_case(name: String) -> String {
    let mut result = "".to_owned();
    let mut prev_char = '_';

    for i in 0..name.len() {
        if name.chars().nth(i).unwrap() == '_' {
            prev_char = name.chars().nth(i).unwrap();
            continue;
        }
        if prev_char == '_' {
            result.push(name.chars().nth(i).unwrap().to_ascii_uppercase());
        } else {
            result.push(name.chars().nth(i).unwrap());
        }
        prev_char = name.chars().nth(i).unwrap();
    }
    return result.to_owned();
}

pub fn write_hpp(mut file: File, name: String, type_name: String) {
    let uppercase_name = name.to_uppercase();
    let pascal_name = pascal_case(name.to_owned());
    let data = format!(
        r#"
/**
 * @file {type_name}/{name}/{name}.hpp
 * 
 * Header file including {name} algorithm.
 */

#ifndef SLOWMOKIT_{uppercase_name}_HEADER_HPP
#define SLOWMOKIT_{uppercase_name}_HEADER_HPP

#include <slowmokit/core.hpp>

namespace slkt {{
template<class T>
class {pascal_name} 
{{
    // declare all functions here
}}

}} // namespace slkt

// Include implementation.
#include "{name}_impl.hpp"

#endif // SLOWMOKIT_{uppercase_name}_HEADER_HPP
"#
    );
    file.write_all(data.as_bytes())
        .expect("Error creating files.");

    println!("Model header file added!");
}

pub fn write_impl(mut file: File, name: String, type_name: String) {
    let uppercase_name = name.to_uppercase();
    let data = format!(
        r#"
/**
 * @file {type_name}/{name}/{name}_impl.hpp
 * 
 * Implementation of {name} algorithm.
 */

 #ifndef SLOWMOKIT_{uppercase_name}_IMPL_HPP
 #define SLOWMOKIT_{uppercase_name}_IMPL_HPP

#include "{name}.hpp"

namespace slkt {{
// Implement/define all function using the resolution operator `::`

}}

#endif // SLOWMOKIT_{uppercase_name}_IMPL_HPP
"#
    );
    file.write_all(data.as_bytes())
        .expect("Error creating files.");
    println!("Model implementation file added!");
}