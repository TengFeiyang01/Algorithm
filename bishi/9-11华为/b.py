def simplify_path(path):
    parts = path.split('/')
    stack = []
    for part in parts:
        if part == '' or part == '.':
            continue
        if part == '..':
            if stack:
                stack.pop()
        else:
            stack.append(part)
    return '/' + '/'.join(stack)

def cd_command(current_path, command):
    current_path = simplify_path(current_path)
    if command == "cd /":
        return "/", 0
    
    command_parts = command.split()
    if len(command_parts) != 2 or command_parts[0] != 'cd':
        return current_path, 0

    relative_path = command_parts[1]
    if relative_path.startswith('/'):
        target_path = relative_path
    else:
        target_path = current_path + '/' + relative_path
    
    simplified_target_path = simplify_path(target_path)
    
    
    return simplified_target_path, len(simplified_target_path.split('/')) - 1

current_path = input().strip()
command = input().strip()

final_path, d = cd_command(current_path, command)
print(final_path, d)
