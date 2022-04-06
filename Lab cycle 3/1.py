'''Develop a two-player tic-tac-toe game using pygame'''

import pygame
import sys

pygame.init()

display_surface=pygame.display.set_mode((1000,1000))
pygame.display.set_caption('Tic Tac Toe')

white = (255, 255, 255)
green = (0, 255, 0)
blue = (0, 0, 128)

font = pygame.font.Font('freesansbold.ttf', 32)
text = font.render('Tic Tac Toe', True, green, blue)
textRect = text.get_rect()
textRect.center = (400,400)

width = display_surface.get_width()
height = display_surface.get_height()

smallfont = pygame.font.SysFont('Corbel',35)
newtext = smallfont.render('quit' , True , green)

while True:
    display_surface.fill(white)
    display_surface.blit(text, textRect)
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()
            
        if event.type == pygame.MOUSEBUTTONDOWN:
            if width/2 <= mouse[0] <= width/2+140 and height/2 <= mouse[1] <= height/2+40:
                pygame.quit()
                sys.exit()

        mouse = pygame.mouse.get_pos()

        if width/2 <= mouse[0] <= width/2+140 and height/2 <= mouse[1] <= height/2+40:
            pygame.draw.rect(display_surface,white,[width/2,height/2,140,40])
          
        else:
            pygame.draw.rect(display_surface,blue,[width/2,height/2,140,40])

        display_surface.blit(newtext , (width/2+50,height/2))
        
        pygame.display.update()


'''
import pygame

  
  
# initializing the constructor
pygame.init()
  
# display_surface resolution
res = (720,720)
  
# opens up a window
display_surface = pygame.display.set_mode(res)
  
# white color
color = (255,255,255)
  
# light shade of the button
color_light = (170,170,170)
  
# dark shade of the button
color_dark = (100,100,100)
  
# stores the width of the
# display_surface into a variable
width = display_surface.get_width()
  
# stores the height of the
# display_surface into a variable
height = display_surface.get_height()
  
# defining a font
smallfont = pygame.font.SysFont('Corbel',35)
  
# rendering a text written in
# this font
text = smallfont.render('quit' , True , color)
  
while True:
      
    for ev in pygame.event.get():
          
        if ev.type == pygame.QUIT:
            pygame.quit()
              
        #checks if a mouse is clicked
        if ev.type == pygame.MOUSEBUTTONDOWN:
              
            #if the mouse is clicked on the
            # button the game is terminated
            if width/2 <= mouse[0] <= width/2+140 and height/2 <= mouse[1] <= height/2+40:
                pygame.quit()
                  
    # fills the display_surface with a color
    display_surface.fill((60,25,60))
      
    # stores the (x,y) coordinates into
    # the variable as a tuple
    mouse = pygame.mouse.get_pos()
      
    # if mouse is hovered on a button it
    # changes to lighter shade 
    if width/2 <= mouse[0] <= width/2+140 and height/2 <= mouse[1] <= height/2+40:
        pygame.draw.rect(display_surface,color_light,[width/2,height/2,140,40])
          
    else:
        pygame.draw.rect(display_surface,color_dark,[width/2,height/2,140,40])
      
    # superimposing the text onto our button
    display_surface.blit(text , (width/2+50,height/2))
      
    # updates the frames of the game
    pygame.display.update()

'''
