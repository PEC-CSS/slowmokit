mod create;

use execute::Execute;
use std::process::Command;

use clap::{Args, Parser, Subcommand};

#[derive(Parser)]
#[command(author, version)]
#[command(
    about = "nimble_cli - one in all tool for ml kit",
    long_about = "nible_cli is a command line tool built to assist the development and maintainence of the machine leanring library built by PEC CSS."
)]
struct Cli {
    #[command(subcommand)]
    command: Option<Commands>,
}

#[derive(Subcommand)]
enum Commands {
    /// Install Library
    Install(Install),
    /// Create a new model
    Create(Create),
    /// Upgrade library to latest version
    Upgrade(Upgrade),
}

#[derive(Args)]
struct Install {}

#[derive(Args)]
struct Create {
    /// Name of the model
    #[arg(short = 'm', long = "model")]
    model_name: String,

    /// Type of model
    #[arg(short = 't', long = "type")]
    model_type: String,
}

#[derive(Args)]
struct Upgrade {}

fn main() {
    let cli = Cli::parse();

    match &cli.command {
        Some(Commands::Create(model)) => {
            create::write_files(model.model_name.to_owned(), model.model_type.to_owned());
        }
        Some(Commands::Install(_)) => {
            println!("Install library to device");
            let mut cmd;
            if cfg!(target_os = "windows") {
                // TODO: Windows
                cmd = Command::new("cmd");
                cmd.args(["/C", "echo hello"]);
            } else if cfg!(target_os = "macos") {
                // TODO: MacOs
                cmd = Command::new("python3");
                cmd.arg("hello.py");
            } else {
                // TODO : Linux
                cmd = Command::new("ls");
                cmd.arg("-l");
            }
            let output = cmd.execute_output().unwrap();

            if let Some(exit_code) = output.status.code() {
                if exit_code == 0 {
                    eprintln!("Installed Sucessfully.");
                } else {
                    eprintln!("Installation Failed.");
                }
            } else {
                eprintln!("Interrupted!");
            }
        }
        Some(Commands::Upgrade(_)) => {
            println!("Upgrade library to latest version");
        }
        None => {}
    }
}
