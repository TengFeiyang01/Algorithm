from collections import deque

class MovingTotal:
    def __init__(self):
        self.a = deque()
        self.st = set()

    def append(self, numbers):
        for x in numbers:
            if len(self.a) == 3:
                self.a.popleft() 
            
            self.a.append(x)
            if len(self.a) == 3:
                self.st.add(sum(self.a))

    def contains(self, x):
        return x in self.st

# Example usage
if __name__ == "__main__":
    movingtotal = MovingTotal()
    
    movingtotal.append([1, 2, 3, 4])
    print(movingtotal.st)
    print(movingtotal.contains(6))  # should return True
    print(movingtotal.contains(9))  # should return True
    print(movingtotal.contains(12)) # should return False
    print(movingtotal.contains(7))  # should return False
    
    movingtotal.append([5])
    print(movingtotal.st)
    print(movingtotal.contains(6))  # should return False
    print(movingtotal.contains(9))  # should return True
    print(movingtotal.contains(12)) # should return True
    print(movingtotal.contains(7))  # should return False