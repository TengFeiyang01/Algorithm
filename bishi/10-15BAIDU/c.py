def init_board():
    return [[0 for _ in range(4)] for _ in range(4)]

def move_up(board):
    for col in range(4):
        merged = [False] * 4
        for row in range(1, 4):
            if board[row][col] != 0:
                if r > 0 and board[r-1][col] == board[r][col] and not merged[r-1]:
                    board[r-1][col] *= 2
                    board[r][col] = 0
                    merged[r-1] = True

def move_down(board):
    for col in range(4):
        merged = [False] * 4
        for row in range(2, -1, -1):
            if board[row][col] != 0:
                if r < 3 and board[r+1][col] == board[r][col] and not merged[r+1]:
                    board[r+1][col] *= 2
                    board[r][col] = 0
                    merged[r+1] = True

def move_left(board):
    for row in range(4):
        merged = [False] * 4
        for col in range(1, 4):
            if board[row][col] != 0:
                if c > 0 and board[row][c-1] == board[row][c] and not merged[c-1]:
                    board[row][c-1] *= 2
                    board[row][c] = 0
                    merged[c-1] = True


def move_right(board):
    for row in range(4):
        merged = [False] * 4
        for col in range(2, -1, -1):
            if board[row][col] != 0:
                if c < 3 and board[row][c+1] == board[row][c] and not merged[c+1]:
                    board[row][c+1] *= 2
                    board[row][c] = 0
                    merged[c+1] = True

def add_value(board, position, value):
    row, col = int(position[0]), int(position[1])
    if board[row][col] != 0:
        return "Error"
    board[row][col] = value
    return None
def format_board(board):
    result = []
    for row in board:
        result.append(",".join(str(cell) if cell != 0 else '.' for cell in row))
    return "\\n".join(result) 
def simulate_2048(commands):
    board = init_board()
    for command in commands:
        move = command[0]
        command = command.split(" ")
        position = command[1:3]
        value = int(command[3])
        add_value(board, position, value)
        if move == 'U':
            move_up(board)
        elif move == 'D':
            move_down(board)
        elif move == 'L':
            move_left(board)
        elif move == 'R':
            move_right(board)
    return format_board(board)

def Solution(moves):
    print(simulate_2048(moves))
