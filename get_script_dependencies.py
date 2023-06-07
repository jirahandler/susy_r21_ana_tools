import os
import re
from graphviz import Digraph
import subprocess

EXCLUDED_DIRS = ['.vscode', 'extensions', '.git','main.dSYM']
EXCLUDED_FILE_TYPES = ['.png', '_png', '.txt', '.sh','.root','.xml','.pdf']
OUTPUT_FILE = "dep_tree.md"

def should_exclude_dir(dir_path):
    for excluded_dir in EXCLUDED_DIRS:
        if excluded_dir in dir_path:
            return True
    return False

def should_exclude_file(file_name):
    for excluded_type in EXCLUDED_FILE_TYPES:
        if file_name.endswith(excluded_type):
            return True
    return False

def get_cpp_header_dependencies(file_path):
    header_dependencies = set()
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            match = re.search(r'#include\s+[<"](.+?)[>"]', line)
            if match:
                header_dependencies.add(match.group(1))
    return header_dependencies

def get_python_import_dependencies(file_path):
    import_dependencies = set()
    if not os.path.isfile(file_path):
        return import_dependencies
    
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            match = re.search(r'import\s+(\w+)', line)
            if match:
                import_dependencies.add(match.group(1))
            match = re.search(r'from\s+(\w+)\s+import', line)
            if match:
                import_dependencies.add(match.group(1))
    return import_dependencies

def get_object_dependencies(file_path):
    object_dependencies = set()
    command = ['otool', '-L', file_path]
    output = subprocess.check_output(command, universal_newlines=True)
    dependencies = re.findall(r'\t([\w/\.]+)', output)
    object_dependencies.update(dependencies)
    
    # Additional otool dependency checks
    command = ['otool', '-l', file_path]
    output = subprocess.check_output(command, universal_newlines=True)
    
    # Check for LC_RPATH
    rpath_dependencies = re.findall(r'LC_RPATH\s+\(.*\)\s+([\w/\.]+)', output)
    object_dependencies.update(rpath_dependencies)
    
    # Check for LC_LOAD_DYLIB
    dylib_dependencies = re.findall(r'LC_LOAD_DYLIB\s+([\w/\.]+)', output)
    object_dependencies.update(dylib_dependencies)
    
    return object_dependencies

def get_header_dependencies(file_path):
    header_dependencies = set()
    with open(file_path, 'r', encoding='latin-1') as file:
        lines = file.readlines()
        for line in lines:
            match = re.search(r'#include\s+[<"](.+?)[>"]', line)
            if match:
                header_dependencies.add(match.group(1))
    return header_dependencies

def get_binary_libraries(file_path):
    libraries = set()
    command = ['otool', '-L', file_path]
    output = subprocess.check_output(command, universal_newlines=True)
    library_paths = re.findall(r'\t(.+?)\s+\(', output)
    libraries.update(library_paths)
    return libraries

def write_to_file(file_path, content):
    with open(file_path, 'a') as file:
        file.write(content)

def process_directory(directory):
    for root, dirs, files in os.walk(directory):
        # Exclude certain directories
        dirs[:] = [d for d in dirs if not should_exclude_dir(d)]
        
        for file in files:
            file_path = os.path.join(root, file)
            
            # Exclude certain file types
            if should_exclude_file(file_path):
                continue
            
            if file.endswith(('.C', '.cpp')):
                cpp_header_dependencies = get_cpp_header_dependencies(file_path)
                write_to_file(OUTPUT_FILE, f'## C++ Header Dependencies for {file_path}\n\n')
                write_to_file(OUTPUT_FILE, '```\n')
                write_to_file(OUTPUT_FILE, '\n'.join(cpp_header_dependencies))
                write_to_file(OUTPUT_FILE, '\n```\n\n')
                
                cpp_libraries = get_binary_libraries(file_path)
                write_to_file(OUTPUT_FILE, f'## Libraries Used by {file_path}\n\n')
                write_to_file(OUTPUT_FILE, '```\n')
                write_to_file(OUTPUT_FILE, '\n'.join(cpp_libraries))
                write_to_file(OUTPUT_FILE, '\n```\n\n')
            
            if file.endswith('.py'):
                python_import_dependencies = get_python_import_dependencies(file_path)
                write_to_file(OUTPUT_FILE, f'## Python Import Dependencies for {file_path}\n\n')
                write_to_file(OUTPUT_FILE, '```\n')
                write_to_file(OUTPUT_FILE, '\n'.join(python_import_dependencies))
                write_to_file(OUTPUT_FILE, '\n```\n\n')
            
            if os.access(file_path, os.X_OK):
                object_dependencies = get_object_dependencies(file_path)
                write_to_file(OUTPUT_FILE, f'## Object Dependencies for {file_path}\n\n')
                write_to_file(OUTPUT_FILE, '```\n')
                write_to_file(OUTPUT_FILE, '\n'.join(object_dependencies))
                write_to_file(OUTPUT_FILE, '\n```\n\n')
                
                binary_libraries = get_binary_libraries(file_path)
                write_to_file(OUTPUT_FILE, f'## Libraries Used by {file_path}\n\n')
                write_to_file(OUTPUT_FILE, '```\n')
                write_to_file(OUTPUT_FILE, '\n'.join(binary_libraries))
                write_to_file(OUTPUT_FILE, '\n```\n\n')
            
            if file.endswith('.h'):
                header_dependencies = get_header_dependencies(file_path)
                write_to_file(OUTPUT_FILE, f'## Header Dependencies for {file_path}\n\n')
                write_to_file(OUTPUT_FILE, '```\n')
                write_to_file(OUTPUT_FILE, '\n'.join(header_dependencies))
                write_to_file(OUTPUT_FILE, '\n```\n\n')

# Generate dependency graph
def generate_dependency_graph(directory):
    dot = Digraph(comment='Dependency Graph')
    
    for root, dirs, files in os.walk(directory):
        # Exclude certain directories
        dirs[:] = [d for d in dirs if not should_exclude_dir(d)]
        
        for file in files:
            file_path = os.path.join(root, file)
            
            # Exclude certain file types
            if should_exclude_file(file_path):
                continue
            
            if file.endswith(('.C', '.cpp')):
                cpp_header_dependencies = get_cpp_header_dependencies(file_path)
                for dependency in cpp_header_dependencies:
                    dot.edge(file, dependency)
            
            if file.endswith('.py'):
                python_import_dependencies = get_python_import_dependencies(file_path)
                for dependency in python_import_dependencies:
                    dot.edge(file, dependency)
            
            if os.access(file_path, os.X_OK):
                object_dependencies = get_object_dependencies(file_path)
                for dependency in object_dependencies:
                    dot.edge(file, dependency)
            
            if file.endswith('.h'):
                header_dependencies = get_header_dependencies(file_path)
                for dependency in header_dependencies:
                    dot.edge(file, dependency)
    
    dot.render('dependency_graph', format='png')
    print("Dependency graph generated: dependency_graph.png")

# Usage
directory_path = '.'
if os.path.exists(OUTPUT_FILE):
    os.remove(OUTPUT_FILE)

process_directory(directory_path)
generate_dependency_graph(directory_path)
