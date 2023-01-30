use std::{fs::File, io::Write};

pub fn write(mut file: File, name: String, type_name: String) {
    let data = format!(
        r#"
# {name}
> {type_name}
Write a brief decription of algorithm here.

## includes

```cpp
#include <slowmokit/methods/{type_name}/{name}.h>
```

## usage

Give hint of brief usage of FUNCTIONS only. And link to example.

```cpp
// Basic function call here
```

## Applications

List a few applications of algorithm here.
"#
    );
    file.write_all(data.as_bytes())
        .expect("Error writing doc file. Aborted");
    println!("Docs file added!");
}
