import subprocess
import sys
import os
import shutil

EXIT_FAILURE = 1

BUILD_DIRECTORY = "build"

def usage():
    print("Usage: python build.py <command> <argument(s)>")
    print("\t1. clean: Cleans and removes build directory")
    print("\t2. gen: Geneates build files")
    print("\t\t2.1 msvc: Geneates MSVC files")
    print("\t3. build: Builds using the generated build files")
    print("\t4. run: Runs the executable")
    print("\t5. ninja: Cleans, gens and runs the executable built by Ninja")
    print("\t6. open: Opens the MSVC sln")
    print("\t7. msvc: Cleans, gens and opens the MSVC sln")
    
def clean():
    if directory_exists(BUILD_DIRECTORY):
        try:
            shutil.rmtree(BUILD_DIRECTORY)
            print(f"Successfully cleaned '{BUILD_DIRECTORY}' directory.")
        except Exception as e:
            print(f"Error cleaning '{BUILD_DIRECTORY}' directory. {e}")
            sys.exit(EXIT_FAILURE)

def gen():
    if "msvc" in sys.argv:
        execute_command('cmake -G "Visual Studio 18 2026" -B build')
    else:
        execute_command("cmake -G Ninja -B build")
        
    if directory_exists(BUILD_DIRECTORY):
        copy_file("lib/raylib/raylib.dll", "build/")
        
def build():
    execute_command("cmake --build build")

def run():
    if directory_exists(BUILD_DIRECTORY):
        execute_command(".\\build\\MazeGame.exe")

def open():
    if directory_exists(BUILD_DIRECTORY):
        os.startfile("build\\MazeGame.slnx")

def execute_command(cmd):
    try:
        print(f"Running '{cmd}'.")
        subprocess.run(cmd, shell=True)
    except Exception as e:
        print(f"Error running '{cmd}'. {e}")
        sys.exit(EXIT_FAILURE)
    print(f"Ran '{cmd}' successfully.")

def directory_exists(directory):
    print(f"Checking if directory '{directory}' exists.")
    if os.path.exists(directory):
        print(f"Directory '{directory}' exists.")
        return True
    print(f"Error: Directory '{directory}' does not exist.")
    return False

def copy_file(src, dest):
    try:
        shutil.copy(src, dest)
    except Exception as e:
        print(f"Error copying '{src}' to '{dest}'. {e}")
        sys.exit(EXIT_FAILURE)
    print(f"Copied '{src}' to '{dest}' successfully.")
        
def main():
    MIN_ARGS = 2
    if (len(sys.argv) < MIN_ARGS):
        print("Error. Please specify an argument.")
        usage()
        sys.exit(EXIT_FAILURE)
    if "clean" in sys.argv:
        clean()
    elif "gen" in sys.argv:
        gen()
    elif "build" in sys.argv:
        build()
    elif "run" in sys.argv:
        run()
    elif "ninja" in sys.argv:
        clean()
        gen()
        build()
        run()
    elif "open" in sys.argv:
        open()
    elif "msvc" in sys.argv:
        clean()
        gen()
        open()
    else:
        print("Unknown command.")
        usage()
        sys.exit(EXIT_FAILURE)

main()
