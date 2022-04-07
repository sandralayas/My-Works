'''Develop a two-player tic-tac-toe game using pygame'''

import pygame
import sys
#import numpy

pygame.init()

display_surface=pygame.display.set_mode((800,800))
pygame.display.set_caption('Tic Tac Toe Game')

red=(255,0,0)
white=(255,255,255)
green=(0,255,0)
blue=(0,0,128)
black=(0,0,0)

# delaring name of the game
font = pygame.font.Font('freesansbold.ttf', 32)
game_name = font.render('Tic Tac Toe',True,white,black)
textRect = game_name.get_rect()
textRect.center = (400,770)
#

smallfont = pygame.font.SysFont('Corbel',35)
newtext = smallfont.render('Q U I T',True,red)

x=335
y=690

'''  M A I N      P R O G R A M  '''
while True:

    # declaring the mouse
    mouse = pygame.mouse.get_pos()
    x_cursor=mouse[0]
    y_cursor=mouse[1]

    # the back groung colour
    display_surface.fill(white)

    # the assigning of the game name below
    display_surface.blit(game_name, textRect)

    
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()

        # if mouse is hovered
            '1. delaring the exit botton'
            '2. when the mouse is clicked'

# quit botton begin  
        if event.type == pygame.MOUSEBUTTONDOWN:
            if x <= x_cursor <= x+140 and y <= y_cursor <= y+40:
                pygame.quit()
                sys.exit()

        if x <= x_cursor <= x+140 and y <= y_cursor <= y+40:
            pygame.draw.rect(display_surface,white,[x,y,140,40])
          
        else:
            pygame.draw.rect(display_surface,black,[x,y,140,40])
# quit botton end

        display_surface.blit(newtext,(365,695))

        #
        a=150
        b=650
        
        pygame.draw.line(display_surface,black,(a,a),(a,b),5)
        pygame.draw.line(display_surface,black,(a,b),(b,b),5)
        pygame.draw.line(display_surface,black,(b,b),(b,a),5)
        pygame.draw.line(display_surface,black,(b,a),(a,a),5)
        #

        c=316.666666666666666666666666666666666666
        d=483.333333333333333333333333333333333333

        pygame.draw.line(display_surface,black,(c,a),(c,b),5)
        pygame.draw.line(display_surface,black,(d,a),(d,b),5)
        pygame.draw.line(display_surface,black,(a,c),(b,c),5)
        pygame.draw.line(display_surface,black,(a,d),(b,d),5)

        temp1=0.5*(a+c)
        temp2=0.5*(c+d)
        temp3=0.5*(d+(d+a))

################################################################

        if event.type == pygame.MOUSEBUTTONDOWN:
            if a <= x_cursor <= c and a <= y_cursor <= c:
                pygame.draw.circle(display_surface,black,(temp1,temp1),40)
        
        if a <= x_cursor <= c and a <= y_cursor <= c:
            pygame.draw.circle(display_surface,white,(temp1,temp1),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp1,temp1),20)

        if event.type == pygame.MOUSEBUTTONDOWN:
            if c <= x_cursor <= d and c <= y_cursor <= d:
                pygame.draw.circle(display_surface,black,(temp2,temp2),40)

        if c <= x_cursor <= d and c <= y_cursor <= d:
            pygame.draw.circle(display_surface,white,(temp2,temp2),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp2,temp2),20)

        if event.type == pygame.MOUSEBUTTONDOWN:
            if d <= x_cursor <= d+a and d <= y_cursor <= d+a:
                pygame.draw.circle(display_surface,black,(temp3,temp3),40)

        if d <= x_cursor <= d+a and d <= y_cursor <= d+a:
            pygame.draw.circle(display_surface,white,(temp3,temp3),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp3,temp3),20)
################################################################
        if event.type == pygame.MOUSEBUTTONDOWN:
            if c <= x_cursor <= d and a <= y_cursor <= c:
                pygame.draw.circle(display_surface,black,(temp2,temp1),40)
                
        if c <= x_cursor <= d and a <= y_cursor <= c:
            pygame.draw.circle(display_surface,white,(temp2,temp1),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp2,temp1),20)

        if event.type == pygame.MOUSEBUTTONDOWN:
            if a <= x_cursor <= c and c <= y_cursor <= d:
                pygame.draw.circle(display_surface,black,(temp1,temp2),40)

        if a <= x_cursor <= c and c <= y_cursor <= d:
            pygame.draw.circle(display_surface,white,(temp1,temp2),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp1,temp2),20)

##
        if event.type == pygame.MOUSEBUTTONDOWN:
            if c <= x_cursor <= d and d <= y_cursor <= d+a:
                pygame.draw.circle(display_surface,black,(temp2,temp3),40)
                
        if c <= x_cursor <= d and d <= y_cursor <= d+a:
            pygame.draw.circle(display_surface,white,(temp2,temp3),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp2,temp3),20)

        if event.type == pygame.MOUSEBUTTONDOWN:
            if d <= x_cursor <= d+a and c <= y_cursor <= d:
                pygame.draw.circle(display_surface,black,(temp3,temp2),40)

        if d <= x_cursor <= d+a and c <= y_cursor <= d:
            pygame.draw.circle(display_surface,white,(temp3,temp2),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp3,temp2),20)

##
        if event.type == pygame.MOUSEBUTTONDOWN:
            if a <= x_cursor <= c and d <= y_cursor <= d+a:
                pygame.draw.circle(display_surface,black,(temp1,temp3),40)
                
        if a <= x_cursor <= c and d <= y_cursor <= d+a:
            pygame.draw.circle(display_surface,white,(temp1,temp3),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp1,temp3),20)

        if event.type == pygame.MOUSEBUTTONDOWN:
            if d <= x_cursor <= d+a and a <= y_cursor <= c:
                pygame.draw.circle(display_surface,black,(temp3,temp1),40)

        if d <= x_cursor <= d+a and a <= y_cursor <= c:
            pygame.draw.circle(display_surface,white,(temp3,temp1),20)
          
        else:
            pygame.draw.circle(display_surface,black,(temp3,temp1),20)

################################################################
        
        pygame.display.update()

'''
if event.type == pygame.MOUSEBUTTONDOWN:
            if d <= x_cursor <= d+a and d <= y_cursor <= d+a:
                pygame.draw.circle(display_surface,black,(temp1,temp1),40)
'''
