# Importing the pygame module
import pygame
from pygame.locals import *

# Initiate pygame and give permission
# to use pygame's functionality
pygame.init()

# Create a display surface object
# of specific dimension
window = pygame.display.set_mode((1200, 600))


# Create a list of different sprites
# that you want to use in the animation
image_sprite = [pygame.image.load("fire.jpg"),
    pygame.image.load("fire_flip.jpg")]


# Creating a new clock object to
# track the amount of time
image_sprite=pygame.transform.scale(image_sprite,(50,50))
clock = pygame.time.Clock()

# Creating a new variable
# We will use this variable to
# iterate over the sprite list
value = 0

# Creating a boolean variable that
# we will use to run the while loop
run = True

# Creating an infinite loop
# to run our game
while run:
 for event in pygame.event.get():
    if event.type == pygame.QUIT:
        run = False
 # Setting the framerate to 3fps just
 # to see the result properly
 clock.tick(120)

 # Setting 0 in value variable if its
 # value is greater than the length
 # of our sprite list
 if value >= len(image_sprite):
  value = 0

 # Storing the sprite image in an
 # image variable
 image = image_sprite[value]

 # Creating a variable to store the starting
 # x and y coordinate
 y = 150

 # Changing the y coordinate
 # according the value stored
 # in our value variable
 if value == 0:
  x = 100
 else:
  x = 105

 # Displaying the image in our game window
 window.blit(image, (x, y))

 # Updating the display surface
 pygame.display.update()

 # Filling the window with black color
 window.fill((0, 0, 0))

 # Increasing the value of value variable by 1
 # after every iteration
 value += 1
