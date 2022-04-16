class Game():
    def __init__(self, name):
        print(f'나는 초기화 함수입니다 {3+5}')
        self.name = name
    
    def print_me(self):
        print(f'제 이름은 {self.name} 입니다')

game = Game("스타크래프트")

game.print_me()
