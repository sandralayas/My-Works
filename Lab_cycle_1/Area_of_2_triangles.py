{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "name": "Area_of_2_triangles.ipynb",
      "provenance": [],
      "collapsed_sections": [],
      "authorship_tag": "ABX9TyNsgyi7xiynlxkpy+mggb3O",
      "include_colab_link": true
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "view-in-github",
        "colab_type": "text"
      },
      "source": [
        "<a href=\"https://colab.research.google.com/github/sandralayas/library/blob/Python-practice-problems/Area_of_2_triangles.ipynb\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "id": "CPjUs8DMNRvW"
      },
      "outputs": [],
      "source": [
        "# Question 2 ; Area of a triangle\n",
        "\n",
        "import math\n",
        "\n",
        "def read_side():# Funtion to read the sides of the triangles\n",
        "  a=int(input('Enter the first side : '))\n",
        "  b=int(input('Enter the second side : '))\n",
        "  c=int(input('Enter the third side : '))\n",
        "  return a,b,c\n",
        "\n",
        "def area(a,b,c):# Calculates the area of the triangle\n",
        "  s=(a+b+c)//2\n",
        "  return math.sqrt(s*(s-a)*(s-b)*(s-c))\n",
        "\n",
        "print(' The first triangle :')# Reads and prints the 1st triangle\n",
        "a,b,c=read_side()\n",
        "t1=area(a,b,c)\n",
        "print(t1,'\\n')\n",
        "\n",
        "print(' The second triangle :\\n')# Reads and prints the 2st triangle\n",
        "x,y,z=read_side()\n",
        "t2=area(x,y,z)\n",
        "print(t2,'\\n')\n",
        "\n",
        "print(' Total area = ',t1+t2)# Total area\n",
        "print('\\n Persentage of t1 = ',t1/(t1+t2)*100,'%')# % of 1st triangle\n",
        "print('\\n Persentage of t2 = ',t2/(t1+t2)*100,'%')# % of 2st triangle\n",
        "\n"
      ]
    }
  ]
}
