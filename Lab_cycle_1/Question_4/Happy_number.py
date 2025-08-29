{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "name": "Happy_number.ipynb",
      "provenance": [],
      "authorship_tag": "ABX9TyN5S6rXkAZmtKsntzFyX26Y",
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
        "<a href=\"https://colab.research.google.com/github/sandralayas/library/blob/Python-practice-problems/Happy_number.ipynb\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "execution_count": 2,
      "metadata": {
        "id": "S19GnolJOJVZ",
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "outputId": "74d7b1e2-015b-4ab4-9860-0e61f1c1d531"
      },
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Enter the number : 1\n",
            "1  is a happy number\n",
            "\n",
            "Enter the lower limit : 1\n",
            "Enter the upper limit : 10\n",
            "1 7 10 \n",
            "\n",
            "Enter how many numbers needed : 7\n",
            "1 7 10 13 19 23 28 "
          ]
        }
      ],
      "source": [
        "''' Question 4 ; Happy number'''\n",
        "\n",
        "def isHappy(num):# Function that checks if the number is happy or not\n",
        "  count=100\n",
        "  while count!=0:\n",
        "    count-=1\n",
        "    sum=0\n",
        "    for i in range(num):\n",
        "      a=num%10\n",
        "      sum+=a*a\n",
        "      num=num//10\n",
        "    if sum==1:\n",
        "      return True\n",
        "    num=sum\n",
        "  else:return False\n",
        "\n",
        "def happy_or_sad():\n",
        "  num=int(input('Enter the number : '))# Prints happy or sad\n",
        "  if isHappy(num):print(num,' is a happy number')\n",
        "  else:print(num,' is a sad number')\n",
        "\n",
        "def happy_range():# Prints all the happy numbers between the given range\n",
        "  lower=int(input('\\nEnter the lower limit : '))\n",
        "  upper=int(input('Enter the upper limit : '))\n",
        "  for i in range(lower,upper+1):\n",
        "    if isHappy(i):print(i,end=' ')\n",
        "\n",
        "def many_happy():# Prints \"count\" number of happy numbers\n",
        "  count=int(input('\\n\\nEnter how many numbers needed : '))\n",
        "  num=1\n",
        "  while count!=0:\n",
        "    if isHappy(num):\n",
        "      count-=1\n",
        "      print(num,end=' ')\n",
        "    num+=1\n",
        "\n",
        "happy_or_sad()\n",
        "happy_range()\n",
        "many_happy()"
      ]
    }
  ]
}
