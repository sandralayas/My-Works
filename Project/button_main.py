from json import load
import pygame
import button

pygame.init()

#create game window
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600



def draw_text(screen,text, font, text_col, x, y):
  img = font.render(text, True, text_col)
  screen.blit(img, (x, y))

#game loop

# while run:
def menu(screen):
  #game variables
  game_paused = True
  menu_state = "main"
  pygame.display.set_caption("Main Menu")



  #define fonts
  font = pygame.font.SysFont("arialblack", 40)

  #define colours
  TEXT_COL = (255, 255, 255)

  #load button images
  save_game_img=pygame.image.load("images/save_game.png").convert_alpha()
  new_game_img=pygame.image.load("images/new_game.png").convert_alpha()
  load_game_img=pygame.image.load("images/load_game.png").convert_alpha()
  resume_img = pygame.image.load("images/button_resume.png").convert_alpha()
  options_img = pygame.image.load("images/button_options.png").convert_alpha()
  quit_img = pygame.image.load("images/button_quit.png").convert_alpha()
  video_img = pygame.image.load('images/button_video.png').convert_alpha()
  audio_img = pygame.image.load('images/button_audio.png').convert_alpha()
  keys_img = pygame.image.load('images/button_keys.png').convert_alpha()
  back_img = pygame.image.load('images/button_back.png').convert_alpha()
  dark_mode_img = pygame.image.load('images/dark_mode.png').convert_alpha()
  credits_img=pygame.image.load('images/credits.png').convert_alpha()
  #create button instances
  resume_button = button.Button(190, 15, resume_img,1)
  new_game_button=button.Button(165,120, new_game_img,0.6)
  load_game_button=button.Button(130, 210, load_game_img,0.7)
  save_game_button=button.Button(165, 300, save_game_img,0.6)
  options_button = button.Button(175, 380, options_img, 1)
  quit_button = button.Button(200, 490, quit_img, 1)
  credits_button=button.Button(50, 50, credits_img, 0.5)
  dark_mode_button = button.Button(126, 75, video_img, 1)
  # video_button = button.Button(126, 75, video_img, 1)
  # audio_button = button.Button(125, 200, audio_img, 1)
  # keys_button = button.Button(146, 325, keys_img, 1)
  back_button = button.Button(100, 50, back_img, 0.5)
  run = True
  while True:

    screen.fill((52, 78, 91))

    #check if game is paused
    if game_paused == True:
      #check menu state
      if menu_state == "main":

        if new_game_button.draw(screen):
          return 'new'
        
        if save_game_button.draw(screen):
            return 'save'
        #draw pause screen buttons
        if resume_button.draw(screen):
          game_paused = False
        if load_game_button.draw(screen):
          return 'load'
        if options_button.draw(screen):
          menu_state = "options"
        if quit_button.draw(screen):
          return 'quit'
      #check if the options menu is open
      if menu_state == "options":
        if credits_button.draw(screen):
          print(credits)
        #draw the different options buttons
        # if video_button.draw(screen):
        #   print("Video Settings")
        # if audio_button.draw(screen):
        #   print("Audio Settings")
        # if keys_button.draw(screen):
        #   print("Change Key Bindings")
        if back_button.draw(screen):
          menu_state = "main"
        
    else:
      return

    #event handler
    for event in pygame.event.get():
      if event.type == pygame.KEYDOWN:
        if event.key == pygame.K_SPACE:
          game_paused = True
      if event.type == pygame.QUIT:
        run = False

    pygame.display.update()

# Screen = pygame.display.set_mode((540, 590))

# menu(Screen)