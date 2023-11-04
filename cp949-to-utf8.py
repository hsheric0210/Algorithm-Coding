import sys
import glob
import shutil
import traceback

copy_block_size = 1024*8 # 8KiB

file_list = []
file_list += glob('**.c', recursive=True)
file_list += glob('**.cpp', recursive=True)
file_list += glob('**.cxx', recursive=True)
file_list += glob('**.h', recursive=True)
file_list += glob('**.hpp', recursive=True)

for file_name in file_list:
    is_utf8 = True
    is_default = True
    try:
        file = open(file_name, 'r', encoding='utf-8')
        close(file)
    except:
        is_utf8 = False
    
    try:
        file = open(file_name, 'r')
        close(file)
    except:
        is_default = False
    
    if not is_utf8 and not is_default:
        print(f'File {file_name} has neither UTF-8 nor default encoding.')
        continue
    
    if not is_utf8 and is_default:
        print(f'Start converting {file_name} encoding from default to UTF-8')
        to_file_name = file_name + '.to-utf8'
        try:
            with open(file_name, 'r') as from_file:
                with open(to_file_name, 'w', encoding='utf-8') as to_file:
                    while True:
                        buffer = from_file.read(copy_block_size)
                        if not buffer:
                            break
                        to_file.write(buffer)
            shutil.remove(file_name)
            shutil.move(to_file_name, file_name) # overwrite
        except:
            traceback.print_exc()
        
        
