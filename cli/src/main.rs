mod create;
mod install;

use clap::{Args, Parser, Subcommand};

#[derive(Parser)]
#[command(author, version)]
#[command(
    about = "nimble_cli - one in all tool for ml kit",
    long_about = "nimble_cli is a command line tool built to assist the development and maintainence of the machine leanring library built by PEC CSS."
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
            install::install_lib();
        }
        Some(Commands::Upgrade(_)) => {
            println!("Upgrade library to latest version");
        }
        None => {
            println!("nim is installed, Run nim --help for options.");
        }
    }
}
